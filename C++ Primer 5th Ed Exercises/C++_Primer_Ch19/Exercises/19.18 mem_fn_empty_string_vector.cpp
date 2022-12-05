#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

/*
* Exercise 19.18
* Write a function that uses count_if to count how many empty strings there
* are in a given vector
*/

int count_empty_strings(std::vector<std::string> svec) {
	return std::count_if(svec.begin(), svec.end(),
		std::mem_fn(&std::string::empty));
}

int main() {
	std::vector<std::string> svec(5);
	svec.push_back("abra");
	svec.push_back("kadabra");

	std::cout << count_empty_strings(svec) << std::endl;
	for (const auto& i : svec)
		std::cout << i << " ";
	std::cout << std::endl;
	return 0;
}