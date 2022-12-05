#include <iostream>
#include <string>
#include <tuple>
#include <vector>

/*
* Exercise 17.1, 17.2
* Define a tuple that holds three int values and initialize the
* members to 10, 20, 30
* Define a tuple that holds a string, a vector<string>, and a
* pair<string,int>
*/


int main() {
	std::tuple<int, int, int> threeI{ 10, 20, 30 };
	std::tuple<std::string, std::vector<std::string>,
		std::pair<std::string, int>> svp_tuple;
	std::cout << std::get<0>(threeI) << std::endl;
	std::cout << std::get<0>(svp_tuple) << std::endl;

	return 0;
}