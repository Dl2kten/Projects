#include <iostream>
#include <list>
#include <vector>

/*
* Exercise 16.4
* Write a template that acts like the library find algorithm, function
* will need two template type parameters, one to represent the function's
* iterator parameters and the other for the type of the value, test
* with vector<int> and list<string>
*/

template<typename InputIterator, typename val>
InputIterator find(InputIterator beg, InputIterator end, val value) {
	while (beg != end) {
		if (*beg == value)
			return beg;
		++beg;
	}
	return end;
}


int main() {
	std::vector<int> ivec{ 0, 1, 2, 3, 4 };
	std::list<std::string> slist{ "abra", "kadabra", "alakazam" };

	auto iter = ::find(ivec.begin(), ivec.end(), 2);
	std::cout << *iter << std::endl;
	iter = ::find(ivec.begin(), ivec.end(), 6);
	std::cout << (iter == ivec.end() ? "Not found" : "Error") 
		<< std::endl;
	auto iter2 = 
		::find(slist.begin(), slist.end(), "abra");
	std::cout << *iter2 << std::endl;
	iter2 = ::find(slist.begin(), slist.end(), "calamaris");
	std::cout << (iter2 == slist.end() ? "Not found" : "Error")
		<< std::endl;
	return 0;
}