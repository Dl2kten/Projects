#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
/*
* Exercise 14.37
* Writea a class that tests whether two values are equal, use that object
* to replace all instances of a given value in a sequence
*/

struct Equal_value {
	Equal_value(const std::string& s) : svalue(s) {}
	bool operator()(const std::string& str) {
		return svalue == str;
	}
private:
	std::string svalue;
};

int main() {
	std::vector<std::string> svec{ "the", "red", "fox", "jumped", "over",
	"the", "red", "turtle" };
	std::replace_if(svec.begin(), svec.end(), Equal_value("red"), "blue");
	for (const auto& i : svec)
		std::cout << i << " ";
	std::cout << std::endl;
	

	return 0;
}