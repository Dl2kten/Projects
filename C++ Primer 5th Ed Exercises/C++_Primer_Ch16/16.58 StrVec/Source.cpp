#include "StrVec.h"
#include <iostream>
#include <algorithm>

/*
* 13.39, 13.40, 13.43
* Write own version of StrVec, including versions of reserve,
* capacity, and resize
* Add a constructor that takes an initializer_list<string>
* Rewrite free member to use for_each and a lambda
* Includes exercises from ch 14
*/

int main() {
	StrVec stvec;
	std::cout << stvec.size() << " " << stvec.capacity() << std::endl;

	stvec.push_back("a");
	stvec.push_back("b");
	stvec.push_back("c");
	std::cout << stvec.size() << " " << stvec.capacity() << std::endl;

	stvec.resize(2);
	for (auto iter = stvec.begin(); iter != stvec.end();
		++iter) {
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
	stvec.resize(10, "d");
	for (auto iter = stvec.begin(); iter != stvec.end();
		++iter) {
		std::cout << *iter << " ";
	}
	std::cout << std::endl;

	stvec.reserve(20);
	std::cout << stvec.size() << " " << stvec.capacity() << std::endl;

	StrVec stvec2({ "kadabra","abra", "kazam" });
	std::cout << stvec2.size() << " " << stvec2.capacity() << std::endl;
	StrVec stvec3(stvec2), stvec4;
	stvec4 = stvec;
	std::cout << stvec3.size() << " " << stvec3.capacity() << std::endl;
	std::cout << stvec4.size() << " " << stvec4.capacity() << std::endl;

	if (stvec2 == stvec3)
		std::cout << "Equal" << std::endl;
	else
		std::cout << "Not Equal" << std::endl;

	if (stvec3 != stvec4)
		std::cout << "Not Equal" << std::endl;
	else
		std::cout << "Equal" << std::endl;

	std::sort(stvec2.begin(), stvec2.end());
	std::cout << stvec2 << std::endl;
	stvec2 = { "hi", "bonjour", "nihao" };
	std::cout << stvec2 << std::endl;
	stvec2[0] = "howdy";
	std::cout << stvec2 << std::endl;

	std::string s1("konnichiwa");
	stvec2.emplace_back(s1);
	stvec2.emplace_back(std::string("hola"));
	stvec2.emplace_back(10, 'h');
	std::cout << stvec2 << std::endl;

	return 0;

}