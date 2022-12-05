#include <iostream>
#include <regex>
#include <fstream>
#include <string>

/*
* Exercise 17.19, 17.20, 17.21, 17.22
* Why is it okay to call m[4].str() without first checking if matched
* Write own version of program to validate phone numbers
* Rewrite phone number program to use valid function from text
* Rewrite to allow any number of white spaces to separate the three parts
* of a phone number
*/

/*
* function valid checks to see if format is correct
*/
bool valid(const std::smatch& m) {
	if (m[1].matched)//takes (xxx)xxx xxxx or (xxx) xxx xxxx can be
		//anything for second delimiter, -. or nothing
		return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
	else//if no () around area code, two delimiters must equal
		//xxx-xxx-xxxx, xxx xxx xxxx
		return !m[3].matched && m[4].str() == m[6].str();
}

int main() {

	std::string phone = "(\\()?(\\d{3})(\\))?([-. ]*)?(\\d{3})([-. ]*)?"
		"(\\d{4})";//17.22 added *
	std::regex r(phone);
	try {
		r;
	}
	catch (std::regex_error e) {
		std::cerr << e.what() << " code: " << e.code() << std::endl;
	}

	std::smatch m;
	std::string s;

	//user prompt
	std::cout << "Please enter a phone number to see if valid format"
		"(q to quit):\n";
	while (getline(std::cin, s) && s != "q") {
		for (std::sregex_iterator it(s.begin(), s.end(), r), end_it;
			it != end_it; ++it)
			if (valid(*it))
				std::cout << "valid: " << it->str() << std::endl;
			else
				std::cout << "not valid: " << it->str() << std::endl;
		std::cout << "Please enter a phone number to see if valid format"
			"(q to quit):\n";
	}

	/*
	* 17.19
	* Will return empty string if matched is false, won't throw error
	*/
	return 0;
}
