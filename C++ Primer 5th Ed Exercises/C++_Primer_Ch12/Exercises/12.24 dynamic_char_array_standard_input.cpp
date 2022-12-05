#include <iostream>
#include <memory>
#include <vector>
#include <new>
#include <memory>
/*
* Exercise 12.24
* Write a program that reads a string from the standard input into a 
* dynamically allocated character array
*/

using std::cout;
using std::cin;
using std::endl;



int main() {

	std::string word;
	//user prompt
	std::cout << "Please enter string: " << endl;
	std::cin >> word;
	char* cp = new char[word.size()];
	for (size_t i = 0; i < word.size(); ++i) {
		cp[i] = word[i];
		std::cout << cp[i];
	}
	std::cout << std::endl;
	delete[] cp;

	/*
	* Online answers asked for length from user and just ingored chars
	* after the length, unsure what questions are looking for
	*/
	return 0;
}


