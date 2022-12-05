#include<iostream>

/*
* Exercise 7.26
* Define Sales_data::avg_price as inline function
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
	Sales_data() : bookNO(""), units_sold(0), revenue(0.0) {}
	Sales_data(const string& s) : bookNO(s) {}
	Sales_data(const string& s, unsigned us, double price) :
		bookNO(s), units_sold(us), revenue(us* price) {}
	Sales_data(istream& is) {//7.12
		read(is, *this);
	}

	//functions
	string isbn() const { return bookNO; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;
};

/*
* Function avg_price
*/
inline double Sales_data::avg_price() const{//7.26
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

	//User prompt
	cout << "Please enter the book number, units sold, and price: "
		<< endl;
	Sales_data total(cin);

	if (total.isbn() != "Invalid") {//if(cin)
		Sales_data trans(cin);
		if (trans.isbn() != "Invalid") {
			do {
				if (total.isbn() == trans.isbn()) // check the isbns
					total.combine(trans); // update the running total
				else {
					print(cout, total) << endl; // print the results
					total = trans; // process the next book
				}
			} while (read(cin, trans));
		}//end of 2nd if
		print(cout, total) << endl;
	}//end of 1st if
	else {
		cerr << "No data?!" << endl;
	}


	return 0;
}