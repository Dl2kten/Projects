#include <iostream>


/*
* Exercise 14.34
* Define a function-object class to perform an if-then-else operation:
* The call operator for this class should take three parameters, it should
* test its first parameter and if that test succeeds, it should return
* it's second parameter; otherwise return third parameter
*/

struct Tri_Param {
	std::string operator() (const std::string& s1,
		const std::string& s2, const std::string& s3) const {
		return s1.size() > 5 ? s2 : s3;
	}

};

int main() {

	Tri_Param tp;
	std::cout << tp("Hello", "More than five", "Less than five")
		<< std::endl;


	return 0;
}