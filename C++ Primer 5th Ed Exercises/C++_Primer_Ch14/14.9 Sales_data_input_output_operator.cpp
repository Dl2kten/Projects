#include <iostream>

/*
* Exercise 14.9
* Define an input operator for your Sales_data class, output already
* defined previously
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

int main() {

	//user prompt
	std::cout << "Please enter book number, units sold, and price:\n";
	Sales_data sd1;
	operator>>(std::cin, sd1);
	operator<<(std::cout, sd1);

	return 0;
}