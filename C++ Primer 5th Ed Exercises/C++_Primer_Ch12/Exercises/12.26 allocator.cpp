#include <iostream>
#include <memory>
#include <vector>
#include <new>
#include <memory>
/*
* Exercise 12.26
* Rewrite program to take in string and store in dynamically allocated
* memory using an allocator
*/



int main() {
	std::allocator<std::string> salloc;
	auto const p = salloc.allocate(20);
	auto q = p; //use for deallocate

	//user prompt
	std::cout << "Please enter some words: " << std::endl;
	std::string word;

	//ensure don't try to initialize more obj than memory allocated
	while (std::cin >> word && q != p + 20) {
		salloc.construct(q++, word);
	}
	
	for (auto i = p; i != q; ++i) {
		std::cout << *i << " ";
	}
	std::cout << std::endl;

	while (q != p) {//destroy elements
		salloc.destroy(--q);
	}

	salloc.deallocate(p, 20);//free memory

	/*
	* Tested with 20 elements, above 20 will cut off all elements above
	*/

	return 0;
}


