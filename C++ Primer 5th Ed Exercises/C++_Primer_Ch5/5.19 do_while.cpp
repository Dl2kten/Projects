#include<iostream>
#include<vector>

/*
* Exercise 5.19
* Write a program using do while loop to repetitively request two strings
* and report which string is less than the other
*/

using namespace std;

int main() {

	/*
	* 5.19
	* 2 str variables
	* do body read in to variables
	* str comparison
	*/

	string s1, s2;

	do {
		cout << "Please enter two different strings to compare: " << endl;
		cin >> s1 >> s2;
		cout << (s1 < s2 ? "First string is smaller." : "Second string "
			"is smaller.") << endl;
	} while (cin);

	//if while(true) it just keeps printing if eof entered

	return 0;
}