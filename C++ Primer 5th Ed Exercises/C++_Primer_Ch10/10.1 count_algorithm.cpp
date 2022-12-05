#include<iostream>
#include<algorithm>
#include<vector>

/*
* Exercise 10.1, 10.2
* Read a sequence of ints into a vector and print the ocunt of how many
* elements have a given value, use count algorithm
* Repeat previous program but with strings
*/

using std::cout;
using std::cin;
using std::endl;

int main() {

	std::vector<int> ivec;
	std::vector<std::string> svec;
	int i;
	std::string s;
	//user prompt
	cout << "Please enter some words: " << endl;

	/*
	while (cin >> i) {
		ivec.push_back(i);
	}
	*/

	while (cin >> s) {
		svec.push_back(s);
	}

	int count = std::count(svec.cbegin(), svec.cend(), "in");

	cout << "The number of times in was entered is: " << count << endl;

	return 0;
}