#include<iostream>
#include<vector>
#include<list>
#include<string>
#include <deque>



/*
* Exercise 9.19
* Write program to read a sequence of strings from standard input to 
* list, use iterators to print the elements in list
*/

using std::cout;
using std::cin;
using std::endl;

int main() {

	std::list<std::string> slist;
	std::string temp;

	//user prompt
	cout << "Please enter strings: " << endl;

	while (cin >> temp) {
		slist .push_back(temp);
	}

	cout << "The strings are: " << endl;

	for (std::list<std::string>::const_iterator iter = slist.begin();
		iter != slist.cend(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;


	return 0;
}