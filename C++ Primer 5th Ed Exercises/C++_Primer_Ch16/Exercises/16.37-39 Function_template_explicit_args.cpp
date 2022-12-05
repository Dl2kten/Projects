#include <iostream>
#include <algorithm>

/*
* Exercise 16.37, 16.38, 16.39
* can pass int and double to std::max?
* why need to provide an explicit template argument to make_shared
* Use explicit template argument to make it sensible to pass two string
* literals to original version of compare from 16.1.1
*/

template <typename T>
int compare(const T& v1, const T& v2)
{
	if (v1 < v2) return -1;
	if (v2 < v1) return 1;
	return 0;
}

int main() {
	//std::max(1, 0.5); only one template type parameter and takes two
	//ref to const, can't pass different types
	std::max(1, 2); //ok

	//need to know type to dynamically allocate memory for make_shared,
	//have to return a shared_ptr needs to know type

	std::cout << compare<const char*>("hi", "hello") << std::endl;
	//1

	return 0;
}