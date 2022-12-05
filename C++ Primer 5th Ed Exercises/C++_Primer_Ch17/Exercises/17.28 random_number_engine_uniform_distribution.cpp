#include <iostream>
#include <string>
#include <random>

/*
* Exercise 17.28
* Write a function that generates and returns a uniformly distributed
* random unsigned int each time it is called
*/

int random_int() {
	static std::default_random_engine e;
	static std::uniform_int_distribution<unsigned> u(0, 9);
	return u(e);
}

int main() {

	for (size_t i = 0; i < 10; ++i)
		std::cout << random_int() << " ";
	std::cout << std::endl;

	std::default_random_engine f;
	std::uniform_int_distribution<unsigned> v(0, 9);
	
	for (size_t i = 0; i < 10; ++i)
		std::cout << v(f) << " ";
	std::cout << std::endl;

	/*
	* generates 2245419583 each time program runs even with different
	* engine and distribution object, can change values by changing
	* v(0, 10)
	*/
	return 0;
}

