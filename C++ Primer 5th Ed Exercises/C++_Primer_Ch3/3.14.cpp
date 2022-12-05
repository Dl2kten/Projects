#include<iostream>
#include<string>
#include<vector>

/*
* Exercise 3.3.2
* 3.14 3.15 read a sequence of ints and strings into vectors
*/

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{

	vector<int>vintegers;
	vector<string>vstrings;

	/*
	//user prompt
	cout << "Please enter some integers: " << endl;

	int numbers = 0;

	while (cin >> numbers) {
		vintegers.push_back(numbers);//append to vintegers
	}

	for (auto i : vintegers) {//prints integers to check
		cout << i << endl;
	}
	*/

	//user prompt for strings
	cout << "Please enter some strings: " << endl;

	string s;

	while (cin >> s) {
		vstrings.push_back(s);//append to vstrings
	}

	for (auto s : vstrings)
		cout << s << endl;

	return 0;
}