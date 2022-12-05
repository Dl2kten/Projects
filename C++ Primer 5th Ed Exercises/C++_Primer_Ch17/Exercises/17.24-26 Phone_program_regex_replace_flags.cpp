#include <iostream>
#include <regex>
#include <fstream>
#include <string>

/*
* Exercise 17.24, 17.25, 17.26
* Write own version of program to reformat phone numbers
* Rewrite phone program so that it writes only the first phone
* number for each person
* Rewrite phone program so that it writes only second and subsequent
* phone numbers for people with more than one number
*/

int main() {

	std::string phone =
		"(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";

	std::regex r(phone);
	try {
		r;
	}
	catch (std::regex_error e) {
		std::cerr << e.what() << " code: " << e.code() << std::endl;
	}

	std::smatch m;
	std::string s, fmt = "$2.$5.$7";
	
	//user prompt
	std::cout << "Please enter a phone number for reformat"
		"(q to quit):\n";
	while (getline(std::cin, s) && s != "q") {
		//std::cout << std::regex_replace(s, r, fmt,
		//	std::regex_constants::format_first_only) << std::endl;
		std::sregex_iterator it(s.begin(), s.end(), r);
		auto p = it->suffix().str();
		std::cout << it->prefix().str()
			<< std::regex_replace(p, r, fmt,
			std::regex_constants::format_default) << std::endl;
		std::cout << "Please enter a phone number for reformat"
			"(q to quit):\n";
	}
	
	/*
	* maybe someway to do it using m.format
	*/
	return 0;
}
