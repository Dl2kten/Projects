#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

/*
* Exercise 10.17
* Rewrite compareIsbn function to use lambda instead
*/

using std::cout;
using std::cin;
using std::endl;

/*
* class Sales_data to contain sales of one type of book
*/
class Sales_data {
	friend std::ostream& print(std::ostream& os, const Sales_data& sd);
	friend std::istream& read(std::istream& is, Sales_data& sd);

	//data
	std::string bookNO;
	unsigned units_sold = 0;
	double revenue = 0.0;

public:
	//constructors
	Sales_data(const std::string& s, unsigned us, double price) :
		bookNO(s), units_sold(us), revenue(us* price) {}

	Sales_data() :Sales_data("", 0, 0) {
		cout << "Default" << endl;
	}

	Sales_data(std::string& s) : Sales_data() {
		cout << "String& s" << endl;
	}

	Sales_data(const std::string& s) : Sales_data() {
		cout << "Const string &s" << endl;
	}
	Sales_data(std::istream& is) :Sales_data() {
		read(is, *this);
		cout << "Istream& is" << endl;
	}

	//functions
	std::string isbn() const { return bookNO; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;
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
* Function read takes istream and Sales_data object and reads into the
* data members
*/
std::istream& read(std::istream& is, Sales_data& sd) {
	double price = 0.0;
	is >> sd.bookNO >> sd.units_sold >> price;
	sd.revenue = sd.units_sold * price;

	if (!is) {//if no input, should use try throw?
		sd.bookNO = "Invalid";
	}
	return is;
}

/*
* Function print prints bookNO, units sold, and revenue
*/
std::ostream& print(std::ostream& os, const Sales_data& sd) {
	os << sd.bookNO << " " << sd.units_sold << " " << sd.revenue;

	return os;
}

/*
* Function printVec, prints elements in vector
* param ostream&, vector
* return void
*/
void printVec(std::ostream& os, const std::vector<Sales_data> sd) {
	for (const auto& i : sd) {
		cout << i.isbn() << " ";
	}
	cout << endl;
}


/*
* Function sortSalesData, sorts Sales_data object based on isbn
* param vector<Sales_data>
* return void
*/
void sortSalesData(std::vector<Sales_data>& sdvec) {
	printVec(cout, sdvec);

	std::stable_sort(sdvec.begin(), sdvec.end(), [](const Sales_data& sd1,
		const Sales_data& sd2) {return sd1.isbn().size() < 
		sd2.isbn().size(); });
	printVec(cout, sdvec);

}

int main() {
	Sales_data sd1("9", 0, 0);
	Sales_data sd2("9985", 0, 0);
	Sales_data sd3("9985", 0, 0);
	Sales_data sd4("9976", 0, 0);
	Sales_data sd5("99", 0, 0);
	Sales_data sd6("98", 0, 0);
	Sales_data sd7("99", 0, 0);
	Sales_data sd8("999", 0, 0);
	Sales_data sd9("900", 0, 0);

	std::vector<Sales_data> sdv{ sd1, sd2, sd3, sd4, sd5, sd6, sd7, sd8,
	sd9 };

	sortSalesData(sdv);
	
	return 0;
}