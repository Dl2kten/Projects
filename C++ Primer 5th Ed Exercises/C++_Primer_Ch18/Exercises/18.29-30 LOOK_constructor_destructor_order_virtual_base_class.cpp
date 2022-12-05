#include <iostream>
#include <string>

/*
* Exercise 18.29, 18.30
* Given the hierarchy from text
* Define a default constructor, a copy constructor, and a constructor
* that has an int parameter in Base, define the same three constructors in
* each derived class, each constructor should use its argument to initialize
* its Base part
*/

class Class {
public:
	Class() {
		std::cout << "Class constructor" << std::endl;
	}
};
class Base : public Class {
public:
	Base() {//default
		std::cout << "Base constructor" << std::endl;
	}
	Base(const Base&) = default;
	Base(int) {
		std::cout << "Base int constructor" << std::endl;
	}
};
class D1 : virtual public Base {
public:
	D1() {
		std::cout << "D1 constructor" << std::endl;
	}
	D1(const D1&) = default;
	D1(int i) : Base(i) {
		std::cout << "D1 int constructor" << std::endl;
	}
};
class D2 : virtual public Base {
public:
	D2() {
		std::cout << "D2 constructor" << std::endl;
	}
	D2(const D2&) = default;
	D2(int i) : Base(i) {
		std::cout << "D2 int constructor" << std::endl;
	}
};
class MI : public D1, public D2 {
public:
	MI() {
		std::cout << "MI constructor" << std::endl;
	}
	MI(const MI&) = default;
	MI(int i) :Base(i), D1(i), D2(i) {
		std::cout << "MI int constructor" << std::endl;
	}
};
class Final : public MI, public Class {
public:
	Final() {
		std::cout << "Final constructor" << std::endl;
	}
	Final(const Final&) = default;
	Final(int i) : Base(i), MI(i) {
		std::cout << "Final int constructor" << std::endl;
	}
};

int main() {
	/*
	* (a) In what order are constructors and destructors run on a Final object?
	* -For constructors Class(), Base()(so Base constructor runs first, which
	* calls Class constructor, and then Base constructor body), D1(), D2(),
	* MI(), Class(), Final()
	* -Destructor in reverse order
	* (b) A Final object has how many Base parts? How many Class parts?
	* -One Base sub-object, two Class sub-object
	* (c) Which of the following assignments is a compile-time error?
	*/
	Base* pb; Class* pc; MI* pmi = nullptr; D2* pd2;
	//pb = new Class; Class does not contain any sub-objects cannot assign
	// pb to Class
	pc = new Final; //what if Final took two values and passed one to the 
	//direct Class and another different one to indirect class, well better
	// to avoid multiple sub-objects of base class in first place
	//pmi = pb; Base does not have MI
	pd2 = pmi;

	Final f;
	MI m(0); //this won't call Base(int) constructor, Base default
	//constructor called which calls Class constructor and then D1(int) 
	//constructor, D1(int) won't call Base(int) and just proceeds to constructor
	//body, the data members of Base is default initialized, since jumped to
	//Base initialization, initializers of that Base in intermediate classes
	//D1 and D2 are ignored
	//**ooh wait that's why all derived classes should
	//initialize virtual Base cause there's a chance at some point they're the
	//most derived class
	D1 d(0), d2(d);
	return 0;
}