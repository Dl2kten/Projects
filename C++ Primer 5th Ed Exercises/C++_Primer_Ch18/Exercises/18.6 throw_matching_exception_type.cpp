#include <iostream>

/*
* Exercise 18.6
* Given the following exception types and catch clauses, write a throw 
* expression that creates an exception object that can be caught by each 
* catch clause
*/

class exceptionType { };

int main() {

	try {
		throw exceptionType();
	}
	catch (exceptionType* pet) {}

	try {
		throw std::exception("exception");
	}
	catch (...) {}

	typedef int EXCPTYPE;
	try {
		throw EXCPTYPE();
	}
	catch (EXCPTYPE) {}



	return 0;
}