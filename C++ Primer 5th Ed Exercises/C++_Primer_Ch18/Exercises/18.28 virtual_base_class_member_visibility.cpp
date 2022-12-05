#include <iostream>
#include <string>

/*
* Exercise 18.28
* Given the following class hierarchy, which inherited members can be accessed
* without qualification from within the VMI class, which require qualification,
* explain
*/
struct Base {
	void bar(int) {} // public by default
protected:
	int ival;
};
struct Derived1 : virtual public Base {
	void bar(char) {} // public by default
	void foo(char) {}
protected:
	char cval;
};
struct Derived2 : virtual public Base {
	void foo(int) {} // public by default
protected:
	int ival;
	char cval;
};
class VMI : public Derived1, public Derived2 {
public:
	//bar member, ival member can be accessed without qualification
	//foo and cval requires qualification
	void func() {
		ival = 0;
		bar('c');
		//foo(1);
		//cval = 1;
	}
};

int main() {
	VMI vmi;
	vmi.func();
	return 0;
}