#include<iostream>
#include<vector>

/*
* Exercise 7.41
* Rewrite Sales_data class to use delegating constructors, add a 
* statement to each of the constructors that prints a message whenever
* it is executed
*/

using namespace std;

/*
* class Sales_data to contain sales of one type of book
*/
class Sales_data {
	friend ostream& print(ostream& os, const Sales_data& sd);
	friend istream& read(istream& is, Sales_data& sd);

	//data
	string bookNO;
	unsigned units_sold = 0;
	double revenue = 0.0;

public:
	//constructors
	Sales_data(const string& s, unsigned us, double price) :
		bookNO(s), units_sold(us), revenue(us* price) {
		cout << "Parameter const string& s, unsigned us, double price"
			<< endl;
	}

	Sales_data() :Sales_data("", 0, 0) {
		cout << "Default" << endl;
	}

	Sales_data(string& s) : Sales_data() {
		cout << "String& s" << endl;
	}
	
	Sales_data(const string& s) : Sales_data() {
		cout << "Const string &s" << endl;
	}
	Sales_data(istream& is) :Sales_data() {//7.12
		read(is, *this);
		cout << "Istream& is" << endl;
	}

	//functions
	string isbn() const { return bookNO; }
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
istream& read(istream& is, Sales_data& sd) {
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
ostream& print(ostream& os, const Sales_data& sd) {
	os << sd.bookNO << " " << sd.units_sold << " " << sd.revenue;

	return os;
}

int main() {

	const string sc = "A";
	string s = "B";
	Sales_data sd1;
	cout << endl;
	Sales_data sd2(s, 0, 0);
	cout << endl;
	Sales_data sd3(sc);
	cout << endl;
	Sales_data sd4(s);
	cout << endl;
	Sales_data sd5(cin);
	return 0;
}