#include <iostream>

/*
* Exercise 15.23
* Fix class D1 from text to override fcn function, how would the calls
* be resolved
*/
class Base {
public:
	virtual int fcn() {
		std::cout << "Base fcn" << std::endl;
		return 1;
	}
};
class D1 : public Base {
public:
	
	int fcn() override { 
		std::cout << "d1 fcn" << std::endl;	
		return 1;
	}
	int fcn(int) { 
		std::cout << "d1 fcn(int)" << std::endl;
		return 1;
	}
	virtual void f2() { std::cout << "d1 f2" << std::endl; }
};
class D2 : public D1 {
public:
	int fcn(int) { 
		std::cout << "d2 fcn(int)" << std::endl;
		return 1;
	}
	int fcn() { 
		std::cout << "d2 fcn" << std::endl;
		return 1;
	}
	void f2(){ std::cout << "d1 f2" << std::endl; }
};

int main() {

	Base bobj; D1 d1obj; D2 d2obj;
	Base* bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
	bp1->fcn(); // virtual call, will call Base::fcn at run time
	bp2->fcn(); // virtual call, will call D1::fcn at run time
	bp3->fcn(); // virtual call, will call D2::fcn at run time
	D1* d1p = &d1obj; D2* d2p = &d2obj;
	//bp2->f2(); 
	d1p->f2(); // virtual call, will call D1::f2 at run time
	d2p->f2(); // virtual call, will call D2::f2 at run time

	Base* p1 = &d2obj; D1* p2 = &d2obj; D2* p3 = &d2obj;
	//p1->fcn(42); // error: Base has no version of fcn that takes an int
	p2->fcn(42); // statically bound, calls D1::fcn(int)
	p3->fcn(42); // statically bound, calls D2::fcn(int)
	return 0;
}