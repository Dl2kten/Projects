#include "Sales_data.h"


/*
* Function avg_price
*/
double Sales_data::avg_price() const {//7.26
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
* operator<< prints bookNO, units sold, and revenue
*/
std::ostream& operator<<(std::ostream& os, const Sales_data& sd)
{
	os << sd.bookNO << " " << sd.units_sold << " " << sd.revenue;

	return os;
}

/*
* operator>> takes istream and Sales_data object and reads into the
* data members
*/
std::istream& operator>>(std::istream& is, Sales_data& sd)
{
	double price = 0.0;
	is >> sd.bookNO >> sd.units_sold >> price;
	sd.revenue = sd.units_sold * price;

	if (!is) {//if no input, should use try throw?
		sd.bookNO = "Invalid";
	}
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