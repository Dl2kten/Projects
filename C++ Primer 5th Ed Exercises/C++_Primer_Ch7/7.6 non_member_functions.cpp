#include<iostream>

/*
* Exercise 7.6, 7.7
* Define add, read, and print functions
* Incorporate these functions
*/

using namespace std;

/*
* Data structure to contain sales of one type of book
*/
struct Sales_data {
	std::string bookNO;
	unsigned units_sold = 0;
	double revenue = 0.0;
	string isbn() const { return bookNO; }
	Sales_data& combine(const Sales_data&);
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
istream& read(istream& is, Sales_data& sd) {
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

	Sales_data total;
	//double price = 0.0;

	//user prompt
	cout << "Please enter a book and the number of units sold plus the "
		"price: " << endl;

	if (read(cin, total)) {
		Sales_data trans;
		//total.revenue = total.units_sold * price;

		while (read(cin, trans))
		{
			//trans.revenue = trans.units_sold * price;

			if (total.isbn() == trans.isbn()) {
				//add together total number of units and revenue
				total.combine(trans);
			}
			else {
				print(cout, total);
				cout << endl;
				total = trans;
			}
		}
		print(cout, total) << endl;
	}
	else {//no input
		cerr << "No data?!" << endl;
		return -1;
	}

	/*
	* Suppose to ask for price and calculate revenue instead of just
	* asking user for revenue
	*/
	
	return 0;
}