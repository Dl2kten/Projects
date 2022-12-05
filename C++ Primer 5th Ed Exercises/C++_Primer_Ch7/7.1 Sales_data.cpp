#include<iostream>

/*
* Exercise 7.1
* Write a version of the transaction-processing program from ch 1 using
* Sales_data class from ch 2
*/

using namespace std;

/*
* Data structure to contain sales of one type of book
*/
struct Sales_data {
	std::string bookNO;
	unsigned units_sold = 0;
	double revenue = 0.0;
	double price = 0.0;
};

int main() {
	/*Sales_item total; // variable to hold data for the next transaction
// read the first transaction and ensure that there are data to process
	if (std::cin >> total) {
		Sales_item trans; // variable to hold the running sum
		// read and process the remaining transactions
		while (std::cin >> trans) {
			// if we're still processing the same book
			if (total.isbn() == trans.isbn())
				total += trans; // update the running total
			else {
			// print results for the previous book
				std::cout << total << std::endl;
				total = trans; // total now refers to the next book
			}
		}
		std::cout << total << std::endl; // print the last transaction
	} else {
	// no input! warn the user
	std::cerr << "No data?!" << std::endl;
	return -1; // indicate failure
}
	*/
	Sales_data total;// variable to hold book type

	//user prompt
	cout << "Please enter a book and the number of units sold plus the "
		"selling price: " << endl;

	if (cin >> total.bookNO >> total.units_sold >> total.price) {
		Sales_data trans;

		while (cin >> trans.bookNO >> trans.units_sold >> trans.price) {
			if (total.bookNO == trans.bookNO) {
				//add together total number of units and revenue
				total.units_sold += trans.units_sold;
				total.revenue = total.units_sold * total.price +
					trans.units_sold * trans.price;
			}
			else {
				cout << total.bookNO << "'s revenue is: $"
					<< total.units_sold * total.price << endl;
				total = trans;
			}
		}
		cout << total.bookNO << "'s revenue is: $"
			<< total.units_sold * total.price << endl;
	}
	else {//no input
		cerr << "No data?!" << endl;
		return -1;
	}
	return 0;
}