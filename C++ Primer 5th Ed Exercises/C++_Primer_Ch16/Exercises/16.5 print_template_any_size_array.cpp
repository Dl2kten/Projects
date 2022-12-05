#include <iostream>
#include <list>
#include <vector>

/*
* Exercise 16.5
* Write a template version of print function from 6.2.4 that takes a
* reference to an array and can handle arrays of any size and any
* element type
*/

template<typename T, unsigned N>
void print(const T(&arr)[N]) {
	for (const auto& i : arr)
		std::cout << i << " ";
	std::cout << std::endl;
}

int main() {

	int iarr[] = { 1, 2, 3, 4, 5, 6 };
	std::string sarr[] = { "abra", "kadabra", "alakazam", "sim sala bim" };
	print(iarr);
	print(sarr);

	return 0;
}