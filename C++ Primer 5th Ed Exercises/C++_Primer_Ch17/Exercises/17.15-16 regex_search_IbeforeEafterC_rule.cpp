#include <iostream>
#include <regex>

/*
* Exercise 17.15, 17.16
* Write program using the pattern that find words that violate the
* "i before e except after c" rule, prompt user to supply a word and 
* indicate okay or not
* What would happen if regex object were initialized with "[^c]ei"
*/

int main() {

	//std::regex r("[[:alpha:]]*[^c]ei[[:alpha:]]*");
	std::regex r("[^c]ei");
	try {
		r;
	}
	catch (std::regex_error e) {
		std::cerr << e.what() << "\ncode: " << e.code() << std::endl;
	}

	std::smatch results;

	//user prompt
	std::cout << "Please enter a word to see if it follows i before e "
		<< "except after c rule(enter q to quite):\n";

	std::string word;
	while (std::cin >> word && word != "q") {
		if (std::regex_search(word, results, r)) {
			std::cout << results.str() << " does not follow rule, enter "
				<< "new word to check or q to quite: " << std::endl;
		}
		else {//if enter p will say follow rule as doesn't match r
			std::cout << word << " does follow rule, enter "
				<< "new word to check or q to quite: " << std::endl;
		}
	}

	/*
	* 17.16
	* results.str only returns three characters, ei and the char before,
	* however, regex_match didn't seem to have any change, was using
	* regex_match as just one word
	*/
	return 0;
}