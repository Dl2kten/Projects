#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <map>
/*
* Exercise 14.44
* Write own version of a simple desk calculator that can handle binary
* operations
*/

struct Div {
	int operator()(int i, int j) {
		return i / j;
	}
};
/*
* Function add
* param int, int
* return int
*/
int add(int i, int j) {
	return i + j;
}


int main() {
	
	std::map < std::string, std::function<int(int, int)>> calc_table{
		{"+", add}, {"-", std::minus<int>()}, {"*", [](int i, int j) {
		return i * j; }}, {"/", Div()}, {"%", [](int i, int j) { 
		return i % j; }}
	};

	//user prompt
	std::cout << "Please enter operator and two ints, enter q to quit:\n";
	std::string op;
	int i, j;
	std::cin >> op >> i >> j;

	while (std::cin) {
		std::cout << calc_table[op](i, j) << std::endl;

		std::cin >> op >> i >> j;
	}

	return 0;
}