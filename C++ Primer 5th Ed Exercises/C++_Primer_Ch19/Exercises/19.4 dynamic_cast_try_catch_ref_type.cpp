#include <iostream>

/*
* Exercise 19.4, 19.5
* Use the classes defined in the first exercise, rewrite the ollowing code
* to convert the expression *pa to the type C&
* When should you use a dynamic_cast instead of a virtual function
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

	try {
		C& pc = dynamic_cast<C&>(*pa);
		std::cout << "Success" << std::endl;
	}
	catch (std::bad_cast e) {
		std::cerr << e.what() << std::endl;
	}

	/*
	* 19.5
	* Use dynamic_cast over virtual function when want to access operations 
	* from derived objects but can't make it virtual, also must know that
	* it's a proper cast to the desired type
	*/
	return 0;
}