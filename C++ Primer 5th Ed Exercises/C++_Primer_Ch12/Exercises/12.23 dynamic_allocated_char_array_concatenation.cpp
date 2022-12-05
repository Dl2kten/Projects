#include <iostream>
#include <memory>
#include <vector>
#include <new>
#include <memory>
/*
* Exercise 12.23
* Write a program to concatenate two string literals, putting the
* result in a dynamically allocated array of char, concatenate two 
* library strings that have the same value as the literals
*/

using std::cout;
using std::cin;
using std::endl;



int main() {

	std::string a, b;
	//user prompt
	std::cout << "Please enter two strings: " << endl;
	std::cin >> a >> b;
	

	char* cp = new char[a.size() + b.size()];
	for (std::string::size_type i = 0; i < a.size(); ++i) {
		cp[i] = a[i];
	}
	for (std::string::size_type i = a.size(), j = 0; i < a.size() + b.size(); 
		++i, ++j) {
		cp[i] = b[j];
	}
	for (std::string::size_type i = 0; i < a.size() + b.size(); ++i) {
		std::cout << cp[i] << " ";
	}

	std::string total = a + b;
	std::cout << "\n" << total << std::endl;
	delete[] cp;
	/*
	* hmm suppose to store the literals in char* or char[] and go from
	* there, well it's easier to use library string for concatenation
	*/
	return 0;
}


