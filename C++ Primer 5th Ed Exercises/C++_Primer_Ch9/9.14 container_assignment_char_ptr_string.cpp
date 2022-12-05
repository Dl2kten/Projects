#include<iostream>
#include<vector>
#include<list>
#include<string>

/*
* Exercise 9.14
* Assign the elements from a list char* pointers to c style character
* strings to a vector of strings
*/


int main() {

	std::list<const char*> clist = { "h", "i" };

	std::vector<std::string> svec;
	svec.assign(clist.cbegin(), clist.cend());

	for (const auto& i : svec)
		std::cout << i << " ";

	/*
	* the element of list needs to be const char*, couldn't convert
	* from char* to _obj(?)
	*/
	char cp[] = "This is a c string";
	std::string s = cp;
	std::cout << s;

	return 0;
}