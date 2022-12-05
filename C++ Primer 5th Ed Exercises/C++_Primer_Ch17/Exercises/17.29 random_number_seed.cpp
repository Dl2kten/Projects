#include <iostream>
#include <string>
#include <random>

/*
* Exercise 17.29
* Allow user to supply a seed as an optional argument to function
*/


int random_int(unsigned n) {
	std::default_random_engine e(n);
	std::uniform_int_distribution<unsigned> u(0, 9);
	std::cout << e() << std::endl;
	return u(e);
}

int main() {

	//user prompt
	std::cout << "Enter a seed to see random number generated(q to quit):"
		<< std::endl;

	std::string s;
	while (std::cin >> s && s != "q") {
		unsigned i = std::stoi(s);
		std::cout << random_int(i) << std::endl;
		std::cout << "Enter a seed to see random number generated(q to quit):"
			<< std::endl;
	}

	/*
	* if not static generates same number with same seed, static generates
	* different number with same seed, e() is
	*/
	return 0;
}

