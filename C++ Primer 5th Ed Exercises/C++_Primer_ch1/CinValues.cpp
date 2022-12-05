#include <iostream>
/*
* 
* 
*/
int main()
{
	int sum = 0, value = 0;
	/*read until end - of - file, calculating a running total of
	all values read, ctrl+z on windows*/

	while (std::cin >> value)
		sum += value;//sum = sum + value

	std::cout << "Sum is: " << sum << std::endl;
	return 0;
}