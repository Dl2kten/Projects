#include <iostream>
#include "Sales_item.h"
/*
* Reads several transactions for the same ISBN and produces
* sum
*/
int main()
{
	Sales_item item1, item2;

	std::cout << "Please enter the transactions for the book"
		" with the ISBN 0-201-78345-X: " << std::endl;

	if (std::cin >> item1) {/*Checks to see if entry is present
							and correct*/

		Sales_item itemTotal = item1;
		while (std::cin >> item2) {/*Reads in the rest of 
								   entries*/
			itemTotal += item2;
		}//end of while loop

		std::cout << "The sum of all the transactions is: "
			<< itemTotal << std::endl;
	}//end of if block

	return 0;

}