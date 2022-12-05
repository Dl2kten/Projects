#include<iostream>

/*
* Exercise 7.2, 7.3
* Add the combine and isbn members to the Sales_data class
* Revise program to use these members
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

int main() {

	Sales_data total;// variable to hold book type

	//user prompt
	cout << "Please enter a book and the number of units sold plus the "
		"revenue: " << endl;

	if (cin >> total.bookNO >> total.units_sold >> total.revenue) {
		Sales_data trans;

		while (cin >> trans.bookNO >> trans.units_sold >> trans.revenue) 
		{
			if (total.isbn() == trans.isbn()) {
				//add together total number of units and revenue
				total.combine(trans);
			}
			else {
				cout << total.bookNO << "'s revenue is: $"
					<< total.revenue << endl;
				total = trans;
			}
		}
		cout << total.bookNO << "'s revenue is: $"
			<< total.revenue << endl;
	}
	else {//no input
		cerr << "No data?!" << endl;
		return -1;
	}
	return 0;

	/*
	* Didn't need price if ask user to enter revenue...
	*/
}