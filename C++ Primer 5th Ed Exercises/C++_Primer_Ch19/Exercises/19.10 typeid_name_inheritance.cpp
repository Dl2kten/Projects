#include <iostream>

/*
* Exercise 19.10
* Given the following class bierarchy in which each class defines a public 
* default constructor and virtual destructor, which type name is printed
*/
class A { 
public:
	virtual ~A() {};
};
class B : public A { /* . . . */ };
class C : public B { /* . . . */ };

int main() {
	A* pa = new C;
	std::cout << typeid(pa).name() << std::endl; //class C __ptr64 cause virtual
	//and pointer causes pa to be evaluated at runtime
	C cobj;
	A& ra = cobj;
	std::cout << typeid(&ra).name() << std::endl; //class C
	//so expression is address of ra which results in pointer, pointer to 
	//class A __ptr64, didn't look carefully enough
	A* d = &ra;
	B* px = new B;
	A& ra2 = *px;
	std::cout << typeid(ra2).name() << std::endl;//class B
	return 0;
}