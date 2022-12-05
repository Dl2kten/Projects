#include <iostream>
/*
* 
* 
*/
int main()
{
	int sum = 0;
	for (int i = -100; i <= 100; ++i)
		sum += i;

	std::cout << "Sum from -100 to 100 is: " << sum << ".";
	/*while loops continue to run until condition is false,
	* for loops already declare the values so might be better
	* for memory(?)
	*/
	return 0;
}