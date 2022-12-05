#include <iostream>

/*
* Exercise 16.2
* Write and test own version of compare functions
*/

template<typename T>
int compare(const T& t1, const T& t2) {
	if (t1 < t2)
		return -1;
	if (t2 < t1)
		return 1;
	return 0;
}

template<unsigned N, unsigned M>
int compare(const char(&p1)[N], const char(&p2)[M]) {
	return strcmp(p1, p2);
}

int main() {

	std::cout << compare(2.5, 1.2222) << std::endl;
	std::cout << compare("hullo", "abra") << std::endl;


	return 0;
}