#include <iostream>
#include <cstdlib>
/*
* Exercise 19.1
* Write own operator new(size_t) function using malloc and use free to write
* operator delete(void*)
*/

void* operator new(std::size_t sz) {
	if (void* mem = malloc(sz))
		return mem;
	else
		throw std::bad_alloc();
}

void operator delete(void* mem) noexcept {
	free(mem);
}

int main() {

	int* i = new int;
	delete(i);

	return 0;
}