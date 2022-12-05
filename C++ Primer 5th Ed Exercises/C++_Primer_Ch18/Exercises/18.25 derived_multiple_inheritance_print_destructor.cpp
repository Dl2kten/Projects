#include <iostream>
#include <string>

/*
* Exercise 18.25
* Assume two base classes, Base1 and Base2, each of which defines a virtual
* member named print and a virtual destructor, from these base classes, text 
* classes are derived, each of which redefines the print function, using code
* given from text determine which function is used in each call
*/
class Base1 {
public:
	virtual void print() {
		std::cout << "Base1 print" << std::endl;
	}
	virtual ~Base1() {
		std::cout << "Base1" << std::endl;
	}
};

class Base2 {
public:
	virtual void print() {
		std::cout << "Base1 print" << std::endl;
	}
	virtual ~Base2() {
		std::cout << "Base2" << std::endl;
	}
};
class D1 : public Base1 {
public:
	void print() {
		std::cout << "D1 print" << std::endl;
	}
	~D1() {
		std::cout << "D1 destructor" << std::endl;
	}
};
class D2 : public Base2 {
public:
	void print() {
		std::cout << "D2 print" << std::endl;
	}
	~D2() {
		std::cout << "D2 destructor" << std::endl;
	}
};
class MI : public D1, public D2 {
public:
	void print() {
		std::cout << "MI print" << std::endl;
	}
	~MI() {
		std::cout << "MI destructor" << std::endl;
	}
};
int main() {
	Base1* pb1 = new MI;
	Base2* pb2 = new MI;
	D1* pd1 = new MI;
	D2* pd2 = new MI;
	pb1->print(); //MI print
	pd1->print(); //MI print
	pd2->print(); //MI print
	delete pb2; //MI destructor
	delete pd1; //MI destructor
	delete pd2; //MI destructor

	//or did question mean not to override print function but hide it?
	return 0;
}