#include<iostream>
#include<map>
#include<set>
#include<string>
#include <list>

/*
* Exercise 11.9
* Define a map that associates words with a list of line numbers on which
* the word might occur
*/

using std::cout;
using std::cin;
using std::endl;



int main() {
	std::map<std::string, std::list<int>> msi{ {"hi", {1, 2, 3}},
		{"what", {10, 34, 23}} };

	/*
	* What's this question asking for?
	*/

	return 0;
}