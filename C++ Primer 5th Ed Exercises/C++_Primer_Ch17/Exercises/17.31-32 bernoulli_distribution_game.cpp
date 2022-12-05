#include <iostream>
#include <string>
#include <random>
#include <sstream>

/*
* Exercise 17.31 , 17.32
* What would happend if we defined b and e inside the do loop of the
* game-playing program from this section
* What would happen if we defined resp inside the loop
*/



int main() {

	std::string resp;
	std::default_random_engine e;
	std::bernoulli_distribution b(0.55);

	do {
		bool first = b(e);
		std::cout << (first ? "Program goes first" : "You go first")
			<< std::endl;

		std::cout << "Play again? Enter 'yes' or 'no'" << std::endl;
	} while (std::cin >> resp && resp == "yes");

	/*
	* 17.31
	* If generator defined inside loop, the same player would always go
	* first
	* 17.32
	* Can't use local object
	*/


	return 0;
}
