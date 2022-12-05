#include <iostream>
#include <string>

/*
* Exercise 18.23
* Using the hierarchy from 18.22 along with class D defined in text, assuming
* each class defines a default constructor, which if any of the folloiwng 
* conversions are not permitted
*/
class A {
};
class B : public A {
};
class C : public B {
};
class X { 
};
class Y { 
};
class Z : public X, public Y {
};
class MI : public C, public Z { 
};
class D : public X, public C { };
int main() {
	D* pd = new D;
	X* px = pd;
	A* pa = pd;
	B* pb = pd;
	C* pc = pd;
	//all permitted

	return 0;
}