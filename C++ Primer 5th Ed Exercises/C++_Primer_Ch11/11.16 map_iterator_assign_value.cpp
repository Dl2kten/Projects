#include<iostream>
#include<map>
#include<set>
#include<string>
#include<vector>


/*
* Exercise 11.16
* Using a map iterator, write an expression that assigns a value
* to an element
*/

using std::cout;
using std::cin;
using std::endl;



int main() {

	std::map<std::string, int> msi{ {"a", 1}, {"b", 2} };
	auto map_it = msi.begin();
	cout << msi.begin()->second << endl;

	map_it->second = 4;
	cout << msi.begin()->second << endl;

	return 0;
}