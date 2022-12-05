#include <iostream>
#include <string>
#include <random>
#include <sstream>

/*
* Exercise 17.30
* Revise function again this time to take a min and max value
*/

int random_int(unsigned n, unsigned min, unsigned max) {
	static std::default_random_engine e(n);
	static std::uniform_int_distribution<unsigned> u(min, max);
	std::cout << e() << std::endl;
	return u(e);
}

int main() {

	//user prompt
	std::cout << "Enter a seed, min value and max value to see random"
		" number generated(q to quit) :"
		<< std::endl;

	std::string s;
		while(getline(std::cin, s)) {
			std::istringstream iss(s);
			std::string seed, minimum, maximum;
			iss >> seed >> minimum >> maximum;
			if (seed == "q")
				break;

			std::cout << random_int(std::stoi(seed), 
				std::stoi(minimum), std::stoi(maximum)) 
				<< std::endl;
			std::cout << "Enter a seed, min value and max value to see random"
				" number generated(q to quit) :"
				<< std::endl;
		}

	return 0;
}
