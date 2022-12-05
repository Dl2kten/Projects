#include<iostream>
#include<vector>
#include<list>
#include<string>
#include <deque>
#include <forward_list>

/*
* Exercise 9.45, 9.46
* Write a function that takes a string representing a name and two other
* strings representing a prefix, "Mr" and a suffix, "II", use iterators
* and the insert and append functions generate and return a new string
* with the suffix and prefix added to name
* Rewrite using a position and length, only use insert
*/

using std::cout;
using std::cin;
using std::endl;

/*
* Function preSuffName, adds prefix and suffix to name
* param three string
* return string
*/
std::string preSuffName(std::string name, const std::string& prefix,
	const std::string& suffix) {

	name.append(suffix);

	name.insert(0, prefix);

	return name;
}

/*
* Function preSuffName2, adds prefix and suffix to name
* param three string
* return string
*/
std::string preSuffName2(std::string name, const std::string& prefix,
	const std::string& suffix) {

	name.insert(0, prefix);
	name.insert(name.size(), suffix);

	return name;
}
int main() {
	
	std::string n1{ "Abraham" };
	std::string n2{ "Brock" };
	n1 = preSuffName(n1, "Mr. ", " IV");
	n2 = preSuffName2(n2, "Sir ", " The Great");
	cout << n1 << "\n" << n2 << endl;

	/*
	* would it be better to use const string& name, but then u would
	* have to create a string object inside function, upside is you can
	* use literal to call function, just one string to copy, could be
	* a really long name i guess
	*/
	return 0;
}