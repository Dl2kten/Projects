#include <iostream>
#include "Sales_item.h"
/*
* Reads several transactions for various ISBNs and counts how
* many consecutive(haven't gone over arrays) transactions
* occur
*/
int main()
{
	Sales_item total;/*variable to hold data for the next
					 transaction*/

	if (std::cin >> total) {/*read to see if there's data
							to process*/

		Sales_item trans;//hold running sum

		while (std::cin >> trans) {
			if (total.isbn() == trans.isbn()) {
				total += trans;
			}
			else {
				std::cout << total << std::endl;
				total = trans; // total now equals next book
			}
		}//end of while loop

		std::cout << total << std::endl;/*prints last 
										transaction*/
	}//end of if block
	else {
		//no input, warn the user
		std::cerr << "No data?!" << std::endl;
		return -1; //indicate failure
	}//end of else block

	return 0;
}