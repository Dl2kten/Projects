#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
/*
* Exercise 14.43
* Using library function objects, determine whether a given int value is
* divisible by any element in a container of ints
*/

int main() {
	std::vector<int> ivec{ 2, 3, 4, 5};
	int i = 1;
	while (i != 0) {
		//user prompt
		std::cout << "Enter a number to see if it's divisible 2, 3, 4, "
			"5 or enter 0 to quit:\n";
		std::cin >> i;
		auto found = std::find_if_not(ivec.begin(), ivec.end(), std::bind(
			std::modulus<int>(), i, std::placeholders::_1));
		if (found == ivec.end())
			std::cout << "Not divisible by elements in ivec" << std::endl;
		else
			std::cout << "Divisble by elements in ivec" << std::endl;
	}
	return 0;
}