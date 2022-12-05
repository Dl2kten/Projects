#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <sstream>

/*
* Exercise 17.6
* Rewrite find_book to not use tuple or pair
*/

/*
* class Sales_data to contain sales of one type of book
*/
class Sales_data {
public:
	friend std::ostream& operator<<(std::ostream&, const Sales_data&);
	friend std::istream& operator>>(std::istream&, Sales_data&);
	friend bool operator==(const Sales_data& lhs, const Sales_data& rhs);

	//constructors
	Sales_data(const std::string& s, unsigned us, double price) :
		bookNO(s), units_sold(us), revenue(us* price) {
	}

	Sales_data() :Sales_data("", 0, 0) {
	}

	Sales_data(const std::string& s) : bookNO(s) {
	}

	Sales_data(std::istream& is) :Sales_data() {
		operator>>(is, *this);
	}

	Sales_data& operator+=(const Sales_data&);
	Sales_data& operator=(const std::string&);
	//functions
	std::string isbn() const { return bookNO; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;

private:
	//data
	std::string bookNO;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

/*
* Function avg_price
*/
inline double Sales_data::avg_price() const {//7.26
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}

/*
* Define function combine from class Sales_data
*/
Sales_data& Sales_data::combine(const Sales_data& rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;

	return *this;
}

/*
* Function add takes two Sales_data objects and return their sum
*/
Sales_data add(const Sales_data& lhs, const Sales_data& rhs) {
	Sales_data temp = lhs;
	temp.combine(rhs);

	return temp;
}

/*
* Output operator << for Sales_data
*/
std::ostream& operator<<(std::ostream& os, const Sales_data& sd) {
	os << sd.isbn() << " " << sd.units_sold << " " << sd.revenue
		<< " " << sd.avg_price();
	return os;
}

/*
* Input operator >> for Sales_data
*/
std::istream& operator>>(std::istream& is, Sales_data& sd) {
	double price;
	is >> sd.bookNO >> sd.units_sold >> price;
	if (is)
		sd.revenue = sd.units_sold * price;
	else
		sd = Sales_data();
	return is;
}

/*
* Operator += for Sales_data
*/
Sales_data& Sales_data::operator+=(const Sales_data& sd) {
	units_sold = sd.units_sold;
	revenue += sd.revenue;
	return *this;
}

/*
* Operator + for Sales_data
*/
Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs) {
	Sales_data temp = rhs;
	temp += lhs;
	return temp;
}

/*
* Assignment operator for Sales_data that takes string
*/
Sales_data& Sales_data::operator=(const std::string& s) {
	bookNO = s;
	return *this;
}

/*
* Operator == for Sales_data
*/
bool operator==(const Sales_data& lhs, const Sales_data& rhs) {
	return lhs.bookNO == rhs.bookNO && lhs.units_sold == rhs.units_sold
		&& lhs.revenue == rhs.revenue;
}

/*
* Operator != for Sales_data
*/
bool operator!=(const Sales_data& lhs, const Sales_data& rhs) {
	return !(lhs == rhs);
}






using vv = std::vector<std::vector<Sales_data>>;


struct book_sold {
	book_sold() = default;
	book_sold(std::vector<Sales_data>::size_type s,
		std::vector<Sales_data>::const_iterator f,
		std::vector<Sales_data>::const_iterator se) : sz(s), first(f),
		second(se) {}
	std::vector<Sales_data>::size_type sz;
	std::vector<Sales_data>::const_iterator first;
	std::vector<Sales_data>::const_iterator second;
};

/*
* function compareIsbn compares isbn of two Sales_data objects
*/
bool compareIsbn(const Sales_data& lhs, const Sales_data& rhs) {
	return lhs.isbn() < rhs.isbn();
}

/*
* function read_data reads in sales from different stores
*/
vv read_data(std::ifstream& infile) {
	std::string line;
	vv ret;
	std::vector<Sales_data> svec;

	while (getline(infile, line)) {
		if (line == "*") {
			//ret pushback empty vector<string>
			ret.push_back(svec);
			svec.clear();
			continue;
		}
		std::istringstream iss(line);
		std::string book; unsigned units; double price;
		iss >> book >> units >> price;
		svec.push_back(Sales_data(book, units, price));
	}
	ret.push_back(svec);

	return ret;
}
/*
* function find_book finds all sales of a particular book
*/
book_sold find_book(const vv& files, std::vector<Sales_data>::size_type in,
	const std::string& book) {
	book_sold bs_ret(in, files[in].cend(), files[in].cend());
		
		auto first_iter = files[in].cbegin(), 
			second_iter = files[in].cbegin();
		bool found = false;
		for (auto iter = files[in].cbegin();
			iter != files[in].cend(); ++iter) {
			if (!found) {
				if ((*iter).isbn() == book) {
					first_iter = iter;
					second_iter = iter;
					found = true;
				}
			}
			else {
				if((*iter).isbn() != book) {
					second_iter = iter;
						found = false;
				}
			}
		}
		
		if (first_iter != second_iter) {
			bs_ret.first = first_iter;
			bs_ret.second = second_iter;
		}

	return bs_ret;
}

/*
* function report_results prints sales of a particular book for each store
* that sold it
*/
void report_results(std::istream& in, std::ostream& os, const vv& files) {
	std::string s;

	//user prompt
	std::cout << "Please enter isbn to search: " << std::endl;
	while (in >> s && s != "q") {

		std::vector <book_sold> trans;

		for (decltype(files.size()) i = 0; i != files.size(); ++i) {
			trans.push_back(find_book(files, i, s));
		}

		if (trans[0].first == files[0].cend()
			&& trans[1].first == files[1].cend()
			&& trans[2].first == files[2].cend()) {
			std::cout << s << " wasn't sold in any stores." 
				<< " Please enter new isbn or q to quit: " << std::endl;
			continue;
		}

		for (decltype(files.size()) i = 0; i != files.size(); ++i) {
			if (trans[i].first != files[i].cend()) {
				os << "store " << trans[i].sz << " sales: "
					<< std::accumulate(trans[i].first,
						trans[i].second,
						Sales_data(s)) << std::endl;
			}
		}
		
		
		std::cout << "Please enter new isbn or q to quit: " << std::endl;
	}
}




int main() {
	
	std::ifstream in("Sales.txt");
	if (!in) {
		std::cerr << "Unable to open text" << std::endl;
		return -1;
	}

	vv files = read_data(in);
	report_results(std::cin, std::cout, files);
	/*
	* Could've returned a vector of book_sold from find_book, would've
	* prob been better
	*/
	return 0;
}