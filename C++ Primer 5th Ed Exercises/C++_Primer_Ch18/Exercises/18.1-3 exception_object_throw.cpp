#include <iostream>

/*
* Exercise 18.1, 18.2, 18.3
* What is type of exception object in the following throws,
* what would happen if written as throw p
* What happens if exception occurs at indicated point of text code
* There are two ways to make it work correctly if exception is thrown, 
* describe them and implement them
*/

int main() {

	std::range_error r("error");
	try {
		throw r;
	}
	catch (std::range_error re) {
		std::cerr << " " << std::endl;
	}
	std::exception* p = &r;
	try {
		throw *p; //Unhandled exception at 0x00007FFF03744FD9 if p, but if the
		//param of catch is exception* then would run fine with throw p
	}
	catch (std::exception e) {
		std::cerr << " " << std::endl;
	}
	
	/*
	void exercise(int b, int e)
	{
		vector<int> v(b, e);
		int* p = new int[v.size()];
		ifstream in("ints");
		// exception occurs here
	}
	18.2 the dynamically allocated p will be destroyed but the memory won't
	be freed, memory leak
	18.3 can destroy and free in local catch if knows that catch will match
	the throw statement, or just define p to point to non dynamic int array
	*/

	return 0;
}