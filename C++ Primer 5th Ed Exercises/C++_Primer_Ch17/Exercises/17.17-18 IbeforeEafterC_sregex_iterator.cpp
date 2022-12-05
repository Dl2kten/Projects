#include <iostream>
#include <regex>
#include <fstream>
#include <string>

/*
* Exercise 17.17, 17.18
* Update program to find all words in an input sequence that violate the
* "ei" grammer rule
* Revise program to ignore words that contain "ei" but not misspellings,
* such as "albeit" and "neighbour"
*/

int main() {

	std::regex r("[[:alpha:]]*[^c]ei[[:alpha:]]*");
	//std::regex rr("freind"); test
	try {
		r;
	}
	catch (std::regex_error e) {
		std::cerr << e.what() << "\ncode: " << e.code() << std::endl;
	}

	std::smatch results;
	/*
	* read in from file of words
	*/
	std::ifstream in("ei_rule.txt");
	if (!in) {
		std::cerr << "Could not open file" << std::endl;
	}

	std::string line, file;
	std::vector<std::string> svec{ "albeit", "neighbour", "being", 
		"deity" };
	bool correct_spelling = false;
	while (getline(in, line)) {
		file += line;
	}
		
	for (std::regex_iterator<std::string::iterator>
		it(file.begin(), file.end(), r), end_it; it != end_it; ++it) {
		for (const auto& i : svec) {
			if (it->str() == i)
				correct_spelling = true;
		}
		
		if (correct_spelling) {
			correct_spelling = false;
			continue;
		}
		
		auto pos = it->prefix().length();
		pos = pos > 40 ? pos - 40 : 0;
		std::cout << it->prefix().str().substr(pos) << "\n\t\t>>>"
			<< it->str() << "<<<\n"
			<< it->suffix().str().substr(0, 40) << std::endl;
	}
	
	/*
	* 17.18
	* Used vector to compare with exceptions, could have used return
	* from it->str as pattern and then searched a string with all the
	* exceptions but initializing regex object every iteration could be
	* slow
	*/
	return 0;
}
