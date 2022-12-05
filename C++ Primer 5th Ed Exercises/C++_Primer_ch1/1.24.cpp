#include <iostream>
#include "Sales_item.h"
/*
* Reads several transactions for various ISBNs and counts how
* many consecutive(haven't gone over arrays) transactions
* occur
*/
int main()
{
	Sales_item item1, item2;

	std::cout << "Please enter the transactions for books: "
		<< std::endl;

	if (std::cin >> item1) {/*Checks to see if entry is present
							and correct*/

		int transCount = 1;
		while (std::cin >> item2) {/*Reads in the rest of 
								   entries*/
			
			if (item1.isbn() == item2.isbn()) {
				//check to see same isbn
				++transCount;
			}
			else {
				std::cout << "The number of transactions for "
					<< item1.isbn() << " is: " << transCount
					<< std::endl;
				transCount = 1;//reset the counter
			}
			
			item1 = item2;//reassign item1 to next item

		}//end of while loop

		std::cout << "The number of transactions for "
			<< item1.isbn() << " is: " << transCount
			<< std::endl;
	}//end of if block

	return 0;

}