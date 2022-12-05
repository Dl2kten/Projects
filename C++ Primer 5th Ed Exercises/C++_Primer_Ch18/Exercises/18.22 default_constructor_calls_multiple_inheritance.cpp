#include <iostream>
#include <string>

/*
* Exercise 18.22
* Given the text code class hierarchy in which each class defines a default
* constructor, what is the order of constructor execution for the following 
* definition
*/
class A {
public:
	A() {
		std::cout << "A" << std::endl;
	}
};
class B : public A {
public:
	B() {
		std::cout << "B" << std::endl;
	}
};
class C : public B { 
public:
	C() {
		std::cout << "C" << std::endl;
	}
};
class X { 
public:
	X() {
		std::cout << "X" << std::endl;
	}
};
class Y { 
public:
	Y() {
		std::cout << "Y" << std::endl;
	}
};
class Z : public X, public Y {
public:
	Z() {
		std::cout << "Z" << std::endl;
	}
};
class MI : public C, public Z { 
public:
	MI() {
		std::cout << "MI" << std::endl;
	}
};

int main() {
	
	MI mi;//so calls C, B, A, Z, X, Y, MI
	//so A default constructor->B->C->X->Y->Z->MI

	return 0;
}