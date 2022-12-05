#include <iostream>

/*
* Exercise 19.3
* Given the class hierarchy from text in which each class defines a public 
* default constructor and virtual destructor: which of the dynamic_casts will
* fail?
*/

class A { 
public:
	virtual ~A() {}
};
class B : public A { /* . . . */ };
class C : public B { /* . . . */ };
class D : public B, public A { /* . . . */ };

int main() {
	A* pa = new C;
	B* pb = dynamic_cast<B*>(pa);
	if (pb)
		std::cout << "Succeed" << std::endl;
	else
		std::cout << "Fail" << std::endl;
	B* pb2 = new B;
	C* pc = dynamic_cast<C*>(pb2); //fail, pb has no C
	if (pc)
		std::cout << "Succeed" << std::endl;
	else
		std::cout << "Fail" << std::endl;
	A* pa2 = new D;
	B* pb3 = dynamic_cast<B*>(pa2);
	if (pb3)
		std::cout << "Succeed" << std::endl;
	else
		std::cout << "Fail" << std::endl;

	return 0;
}