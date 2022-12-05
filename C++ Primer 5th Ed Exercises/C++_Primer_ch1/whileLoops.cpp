#include <iostream>
/*
* 
* 
*/
int main()
{
	int sum = 0, val = 50;
	
	/*keep executing while loop as long as val is less
	than or equal to 100*/
	while (val <= 100) {
		sum += val; // assigns sum + val to sum
		++val; // add 1 to val
	}

	std::cout << "Sum of 50 to 100 inclusive is " << sum
		<< std::endl;

	//print from 10 to 0

	int countdown = 10;

	while (countdown >= 0) {
		std::cout << countdown << std::endl;
		--countdown;
	}

	/*prompt user for two integers and print each number
	* in the range specified by those two integers
	*/

	int val1 = 1, val2 = 0;

	/*rather than using if statement have user enter smaller
	* integer first
	*/
	while (val1 >= val2) {
		/*special case if two integers are equal
		would need an extra if else statement to cover
		that case*/
		std::cout << "Please enter two integers(with the "
			"first being smaller second): "
			<< std::endl;
		std::cin >> val1 >> val2;
	}

	std::cout<<"All numbers within the specified range of "
		"the two integers entered by user are:" ;
	while (val2 >= val1) {
		std::cout << val2 << " ";
		--val2;
	}

	return 0;
}