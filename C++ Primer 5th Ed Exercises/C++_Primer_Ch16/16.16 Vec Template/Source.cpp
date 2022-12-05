#include "Vec.h"

/*
* Exercise 16.16
* Rewrite StrVec class as a template named Vec
*/

int main() {
	Vec<int> ivec1, ivec2{ 1, 2, 3, 4 }, ivec3(ivec2), ivec4 = ivec3,
		ivec5({ 6, 7, 8 }), ivec6 = std::move(ivec1);

	for (const auto& i : ivec2) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	ivec6.push_back(1);
	ivec6.push_back(2);
	for (const auto& i : ivec6) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	std::cout << ivec6.size() << " " << ivec6.capacity() << std::endl;
	ivec6.reserve(10);
	ivec6.resize(1);
	ivec6.resize(4);
	ivec6.resize(5, 0);
	for (const auto& i : ivec6) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	std::cout << ivec6.size() << " " << ivec6.capacity() << std::endl;
	std::cout << *ivec5.begin() << std::endl;
	std::cout << *ivec5.end() << std::endl;

	return 0;
}