#include <iostream>
#include <vector>
#include <list>

/*
* Exercise 13.13
* Add copy-assignment operator and destructor to text class X and write
* a program using X objects in various ways
*/

struct X {
	X() { std::cout << "X()" << std::endl; }
	X(const X&) { std::cout << "X(const X&)" << std::endl; }
	X& operator=(const X&);
	~X() { std::cout << "~X()" << std::endl; }

};

/*
* Copy-assignment operator for X
* param const X&
* return X&
*/
X& X::operator=(const X& a) {
	std::cout << "operator=(const X&)"
		<< std::endl;
	X b = a;
	return b;
}
/*
* Function test
* param X
* return void
*/
void test(X a) {
}

/*
* Function testRef
* param const X&
* return void
*/
void testRef(const X& a) {
}

/*
* Function testPtr
* param const X*
* return x
*/
X testPtr(X* a, X b) {
	std::cout << "Pointer";
	X* c(a);
	std::cout << "\nObject" << std::endl;
	X d = b;
	return *a;
	//3 destructor calls deletes b, d, temp
}


int main() {

	std::cout << "Vector object" << std::endl;
	std::vector<X> xvec;
	std::list<X> xlist;
	std::cout << "X object xText, a" << std::endl;
	X xTest, a;//if use X a = xtest counts as copy intialization
	std::cout << "Assign to a" << std::endl;
	a = xTest;//assignment
	std::cout << "X pointer" << std::endl;
	X* xPtr = &xTest;

	std::cout << "Using X as non reference parameter." << std::endl;
	test(xTest);
	std::cout << "Using X as const reference parameter." << std::endl;
	testRef(xTest);
	std::cout << "Using X as const pointer parameter." << std::endl;
	testPtr(xPtr, xTest);

	std::cout << "Vector elements" << std::endl;
	for (int i = 0; i < 4; ++i) {
		std::cout << "X object";
		X x;
		std::cout << "Vector push_back" << std::endl;
		xvec.push_back(x);
		/*
		* the times copy constructor is called is equal to number of 
		* elements which is equal to number of destructor calls, doing
		* a new copy each time push_back happens, at 4 elements, 4 copy
		* constructor calls, 4 destructor calls
		*/
	}

	std::cout << "List elements" << std::endl;
	for (int i = 0; i < 4; ++i) {
		std::cout << "\nX object";
		auto x = new X();
		std::cout << "list" << std::endl;
		xlist.push_back(*x);
		delete x;
	}

	std::cout << "End of program" << std::endl;
	return 0;
}