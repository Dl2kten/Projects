#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
/*
* Exercise 14.42
* Using library function objects and adaptors, define an expression to:
* count the number of values that are greater than 1024
* find first string that is not equal to pooh
* mulitply all values by 2
*/


int main() {
	std::vector<int> ivec{ 1, 2, 342423, 2342, 2, 4, 5252525, 3242, 242,
		65, 234242, 34, 2342, 665 };
	
	std::cout << std::count_if(ivec.cbegin(), ivec.cend(), std::bind(
		std::greater<int>(), std::placeholders::_1, 1024)) << std::endl;

	std::vector<std::string> svec{ "pooh", "pooh", "pooh", "pooh", "winny",
	"pooh", "pooh" };

	auto iter = std::find_if(svec.cbegin(), svec.cend(), std::bind(
		std::not_equal_to<std::string>(), std::placeholders::_1, "pooh"));
	std::cout << *iter << std::endl;

	std::transform(ivec.begin(), ivec.end(), ivec.begin(), std::bind(
	std::multiplies<int>(), std::placeholders::_1, 2));
	
	for (const auto& i : ivec)
		std::cout << i << " ";
	std::cout << std::endl;
	return 0;
}