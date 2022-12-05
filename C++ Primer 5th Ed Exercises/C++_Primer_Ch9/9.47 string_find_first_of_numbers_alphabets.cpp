#include<iostream>
#include<vector>
#include<list>
#include<string>
#include <deque>
#include <forward_list>

/*
* Exercise 9.47
* Write a program that finds each numeric character and then each
* alphabetic character in the string "ab2c3d7R4E6", write two versions
* one using find_first_of, and one using find_first_not_of
*/

using std::cout;
using std::cin;
using std::endl;

int main() {
	const std::string s{ "ab2c3d7R4E6" };

	std::string numbers{ "0123456789" };
	std::string alphabet{ "abcdefghijklmnopqrstuvwxyz" 
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	std::string::size_type pos = 0;

	cout << "The numbers in the string ab2c3d7R4E6 are:\n";
	while ((pos = s.find_first_of(numbers, pos)) 
		!= std::string::npos) {
		cout << s.at(pos) << " at index " << pos << endl;
		++pos;
	}
	pos = 0;

	cout << "The alphabets in the string ab2c3d7R4E6 are:\n";
	while ((pos = s.find_first_of(alphabet, pos))
		!= std::string::npos) {
		cout << s.at(pos) << " at index " << pos << endl;
		++pos;
	}
	pos = 0;
	cout << "\n\n";

	//find_first_not_of
	cout << "The alphabets in the string ab2c3d7R4E6 are:\n";
	while ((pos = s.find_first_not_of(numbers, pos))
		!= std::string::npos) {
		cout << s.at(pos) << " at index " << pos << endl;
		++pos;
	}
	pos = 0;

	cout << "The numbers"
		" in the string ab2c3d7R4E6 are:\n";
	while ((pos = s.find_first_not_of(alphabet, pos))
		!= std::string::npos) {
		cout << s.at(pos) << " at index " << pos << endl;
		++pos;
	}
	pos = 0;

	/*
	* could've put uppercase and lowercase in one string
	*/
	return 0;
}