#include <iostream>
#include <regex>

/*
* Exercise 17.14
* Write several regular expressions designed to trigger various errors.
* Run it to see what output compiler generates
*/

int main() {

	std::regex r1("[[:alnum:]] + \.(cpp|cxx|cc)$", std::regex::icase);
	//warning . unrecognized character escape sequence
	try {
		std::regex r2("[[:alnum:]] + \\.(cpp|cxx|cc$", std::regex::icase);
	}
	catch (std::regex_error e) {
		std::cout << e.what() << "\ncode: " << e.code() << std::endl;
	} //mismatched bracket, code 5 actually matches table 17.7
	try {
		std::regex r3("[[z-a]] + \.(cpp|cxx|cc$)", std::regex::icase);
	}
	catch (std::regex_error e) {
		std::cout << e.what() << "\ncode: " << e.code() << std::endl;
	} //invalid character range, code 8
	try {
		std::regex r2("[[:alnum:]]* + { + \\.(cpp|cxx|cc$)", std::regex::icase);
	}
	catch (std::regex_error e) {
		std::cout << e.what() << "\ncode: " << e.code() << std::endl;
	}//invalid range in {}, code 7
	return 0;
}