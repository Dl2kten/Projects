#include<iostream>

/*
* Exercise 7.11, 7.12
* Add constructors to Sales_data classa and use them in a program
* Move Sales_data constructor that takes reference to istream into
* class body
*/

using namespace std;

/*
* Data structure to contain sales of one type of book
*/
struct Sales_data {
	//constructors
	Sales_data() = default;
	Sales_data(const string& s) : bookNO(s) {}
	Sales_data(const string& s, unsigned us, double price) :
		bookNO(s), units_sold(us), revenue(us* price) {}
	Sales_data(istream& is) {//7.12
		read(is, *this);
	}
	
	//data
	std::string bookNO;
	unsigned units_sold = 0;
	double revenue = 0.0;

	//functions
	string isbn() const { return bookNO; }
	Sales_data& combine(const Sales_data&);
	istream& read(istream& is, Sales_data& sd);
};


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
istream& Sales_data::read(istream& is, Sales_data& sd) {
	double price = 0.0;
	is >> sd.bookNO >> sd.units_sold >> price;
	sd.revenue = sd.units_sold * price;

	return is;
}

/*
* Function print prints bookNO, units sold, and revenue
*/
ostream& print(ostream& os, const Sales_data& sd) {
	os << sd.bookNO << " " << sd.units_sold << " " << sd.revenue;

	return os;
}

int main() {

	Sales_data sd1;
	Sales_data sd2("Book");
	Sales_data sd3("Book", 10, 9.99);

	cout << sd1.bookNO << " " << sd1.units_sold << " " << sd1.revenue
		<< endl;
	cout << sd2.bookNO << " " << sd2.units_sold << " " << sd2.revenue
		<< endl;
	cout << sd3.bookNO << " " << sd3.units_sold << " " << sd3.revenue
		<< endl;

	return 0;
}