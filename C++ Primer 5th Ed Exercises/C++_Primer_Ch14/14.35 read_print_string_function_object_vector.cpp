#include <iostream>
#include <string>
#include <vector>

/*
* Exercise 14.35, 14.36
* Write  a class like PrintString that read a line of input from an
* istream and returns a string representing what was read if read
* fails, return empty string
* Use the class to read the standard input, sotring each line as an
* element in a vector
*/

struct Read_Print_String {
	Read_Print_String(std::istream& i, std::ostream& o) : is(i), os(o),
		line("") {}
	const std::string& operator()() {
		os << "Please enter a line or q to quit:\n";
		if(getline(is, line))
			return line;
		else
			return "";
	}

private:
	std::istream& is;
	std::ostream& os;
	std::string line;
};

int main() {

	Read_Print_String rps(std::cin, std::cout);
	std::vector<std::string> svec;
	std::string s = rps();

	while (!s.empty() && s != "q") {
		svec.push_back(s);
		s = rps();
	}

	for (const auto& i : svec)
		std::cout << i << "\n";
	std::cout << std::endl;

	return 0;
}