#include <iostream>
/*
* Counts number of distinctive values that appear 
* consecutively
*/
int main()
{
	/*currVal is the number we're counting; we'll read new
	* values into val
	*/
	int currVal = 0, val = 0;

	/*read first number and ensure that we have data to 
	process*/
	if (std::cin >> currVal) {
		int cnt = 1;/*store count for current value, define
					cnt after we know there are ints to be 
					counted*/

		while (std::cin >> val) {//read remaining numbers
			
			if (val == currVal) //if values same
				++cnt; //add 1 to cnt
			else {/*otherwise print the count of the
				  previous value*/
				std::cout << currVal << " occurs " << cnt
					<< " times." << std::endl;
				currVal = val;//remember the new value to count
				cnt = 1;//reset the counter
				
			}//else loop end

		}//while loop end

		/*remember to print count for the last value*/
		std::cout << currVal << " occurs " << cnt << " times."
			<< std::endl;

	}//if loop end
	return 0;

}