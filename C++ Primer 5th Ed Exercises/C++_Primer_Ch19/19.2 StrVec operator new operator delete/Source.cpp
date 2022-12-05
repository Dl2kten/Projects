#include "StrVec.h"
#include <iostream>
#include <algorithm>

/*
* Exercise 19.2
* By default, the allocator class uses operator new to obtain storage and 
* operator delete to free it, recompile and rerun StrVec program from ch 13
* using your version of the functions from the previous exercise
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

	/*
	* Not called when defined as member function of StrVec as allocate is 
	* allocating memory for string objects, called once in global scope, so 
	* many warnings once turn on all warnings...
	*/
	return 0;

}