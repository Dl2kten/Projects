#include <iostream>

/*
* Exercise 15.18, 15.19, 15.20
* Determine which assignments are legal
* Determine which class would be legal to have a member function
* void memfcn(Base& b) {b=*this;}
* Write code to test
*/

class Base {
public:
	int i;
protected:
	int j;
private:
	int k;
};

class Pub_derv : public Base {
public:
	void memfcn(Base& b) { b = *this; }
};

class Priv_derv : private Base {
public:
	void memfcn(Base& b) { b = *this; }
};

class Prot_derv : protected Base {
public:
	void memfcn(Base& b) { b = *this; }
};

class Derived_from_Public : public Pub_derv {
public:
	void memfcn(Base& b) { b = *this; }
};

class Derived_from_Private : public Priv_derv {
public:
	//void memfcn(Base& b) { b = *this; }, can't access private
};

class Derived_from_Protect : public Prot_derv {
public:
	void memfcn(Base& b) { b = *this; }
};

int main() {
	Pub_derv d1; Priv_derv d2; Prot_derv d3;

	Base* p = &d1;
	/*p = &d2; p = &d3; are not okay can't convert from derived-to-base
	* unless public, p == &dd1 is okay derived from d1, others derived
	* from priv and prot not okay, tip is very useful ok if a public
	* member can be used
	*/
	return 0;
}