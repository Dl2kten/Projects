#include <iostream>

/*
* Exercise 16.3
* Call compare function on two Sales_data objects to see how compiler
* handles error
*/

/*
* class Sales_data to contain sales of one type of book
*/
class Sales_data {
public:
	friend std::ostream& print(std::ostream& os, const Sales_data& sd);
	friend std::istream& read(std::istream& is, Sales_data& sd);
	friend std::ostream& operator<<(std::ostream&, const Sales_data&);
	friend std::istream& operator>>(std::istream&, Sales_data&);
	//constructors
	Sales_data(const std::string& s, unsigned us, double price) :
		bookNO(s), units_sold(us), revenue(us* price) {
		std::cout << "Parameter const std::string& s, unsigned us, double price"
			<< std::endl;
	}

	Sales_data() :Sales_data("", 0, 0) {
		std::cout << "Default" << std::endl;
	}

	Sales_data(std::string& s) : Sales_data() {
		std::cout << "std::string& s" << std::endl;
	}

	Sales_data(const std::string& s) : Sales_data() {
		std::cout << "Const std::string &s" << std::endl;
	}
	Sales_data(std::istream& is) :Sales_data() {//7.12
		read(is, *this);
		std::cout << "Istream& is" << std::endl;
	}

	Sales_data& operator+(const Sales_data&);
	Sales_data& operator+=(const Sales_data&);

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
template<typename T>
int compare(const T& t1, const T& t2) {
	if (t1 < t2)
		return -1;
	if (t2 < t1)
		return 1;
	return 0;
}

template<unsigned N, unsigned M>
int compare(const char(&p1)[N], const char(&p2)[M]) {
	return strcmp(p1, p2);
}

int main() {
	Sales_data sd1, sd2;
	std::cout << compare(2.5, 1.2222) << std::endl;
	std::cout << compare("hullo", "abra") << std::endl;
	std::cout << compare(sd1, sd2) << std::endl;

	/*
	* Didn't show link error, error c2676 binary < 'const T' does not 
	* define this operator or a conversion to a type acceptable to the 
	* predefined operator 
	*/
	return 0;
}