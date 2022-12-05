#include "String.h"
#include <iostream>
#include <vector>
#include <string>

/*
* 13.44, 13.47, 13.48, 13.49, 13.50
* Write a class named string that is a simplified version of the library
* string class
* Give the copy constructor and copy-assignment operator a statement 
* that prints a message each time function is executed
* Define a vector<String> and call push_back several times, see how many
* Strings are copied
* Add move constructor and move-assignment operator
* Add print statement to move operations and see
*/
int main() {
	String s1;
	String s2("Hi");

	std::cout << s1.size() << " " << s1.capacity() << std::endl;
	std::cout << s2.size() << " " << s2.capacity() << std::endl;

	String s3(s2), s4;
	s4 = s1;
	std::cout << s3.size() << " " << s3.capacity() << std::endl;
	std::cout << s4.size() << " " << s4.capacity() << std::endl;

	std::vector<String> stvec;
	for (std::vector<String>::size_type i = 0; i < 4; ++i) {
		stvec.push_back("a");
	}

	for (const auto i : stvec)
		operator<<(std::cout, i);

	if (s2 == s3)
		std::cout << "Equal" << std::endl;
	else
		std::cout << "Not equal" << std::endl;

	String s5("Hello");
	if (s3 != s4)
		std::cout << "Not equal" << std::endl;
	else
		std::cout << "Equal" << std::endl;

	/*
	* Already checked in a previous exercise each iteration will call
	* copy the same number of times as the number of elements, called move
	* constructor over copy constructor should be faster
	*/

	if (s5 < s2)
		std::cout << "Hello smaller than hi" << std::endl;
	s2[0] = 'a';
	std::cout << s2 << std::endl;

	return 0;
}