#include<iostream>
#include<vector>
#include<list>
#include<string>
#include <deque>



/*
* Exercise 9.18
* Write program to read a sequence of strings from standard input to 
* deque, use iterators to print the elements in deque
*/

using std::cout;
using std::cin;
using std::endl;

int main() {
	/*
	* deque object
	* read from standard input, while loop
	* for loop to print
	*/

	std::deque<std::string> sd;
	std::string temp;

	//user prompt
	cout << "Please enter strings: " << endl;

	while (cin >> temp) {
		sd.push_back(temp);
	}

	cout << "The entered strings are: " << endl;

	for (std::deque<std::string>::const_iterator iter = sd.cbegin();
		iter != sd.cend(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;


	return 0;
}