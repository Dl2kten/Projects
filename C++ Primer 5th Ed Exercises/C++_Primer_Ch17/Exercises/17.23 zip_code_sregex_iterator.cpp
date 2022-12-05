#include <iostream>
#include <regex>
#include <fstream>
#include <string>

/*
* Exercise 17.23
* Write a regular expression to find zip codes. A
* zip code can have five or nine digits. The first five digits can be
* separated from the remaining four by a dash.
*/

int main() {

	std::string zip_code("(\\d{5})([-])?(\\d{4})?");
	std::regex r(zip_code);
	try {
		r;
	}
	catch (std::regex_error e) {
		std::cerr << e.what() << " code: " << e.code() << std::endl;
	}

	std::smatch m;
	std::string s;

	//user prompt
	std::cout << "Please enter a zip code to see if valid format"
		"(q to quit):\n";
	while (getline(std::cin, s) && s != "q") {
		for (std::sregex_iterator it(s.begin(), s.end(), r), end_it;
			it != end_it; ++it)
			std::cout << "valid: " << it->str() << std::endl;
		std::cout << "Please enter a zip code to see if valid format"
			"(q to quit):\n";
	}

	return 0;
}

