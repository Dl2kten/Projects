#include <iostream>
#include <string>
/*
* Data structures
*/
struct Sales_data {
	std::string bookNO;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

int main()
{
	Sales_data data1, data2;
	double price = 0;

	/*reads in values for data members of data1*/
	std::cin >> data1.bookNO >> data1.units_sold >> price;

	//caluclate revenue for data1
	data1.revenue = data1.units_sold * price;

	//repeat for second transaction
	std::cin >> data2.bookNO >> data2.units_sold >> price;
	data2.revenue = data2.units_sold * price;

	/*print the sum of two Sales_data objects*/
	if (data1.bookNO == data2.bookNO) {/*if same isbn*/
		unsigned totalCnt = data1.units_sold + data2.units_sold;
		double totalRev = data1.revenue + data2.revenue;

		/*print isbn, total sold, total rev, and average price*/
		std::cout << data1.bookNO << " " << totalCnt << " "
			<< totalRev << " ";
		
		if (totalCnt != 0) {
			std::cout << totalRev / totalCnt << std::endl;
		} //end of 2nd if block
		else {
			std::cout << "(no sales)" << std::endl;
		}

		return 0; //success

	} //end of first if block
	else {//different isbn
		std::cerr << "Data must refer to the same ISBN"
			<< std::endl;
		return -1; //failed

	}

}