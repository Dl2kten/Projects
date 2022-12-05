#include <iostream>
#include <vector>
#include <list>

/*
* Exercise 13.17
* Write versions of numbered and f from text and check if predictions
* correct
*/

class Numbered {
public:
	Numbered() : mysn(0) { ++mysn; }
	Numbered(const Numbered&);
	int mysn;
};

/*
* Copy constructor for Numbered
*/
Numbered::Numbered(const Numbered& orig) {
	mysn = orig.mysn;
	++mysn;
}

/*
* Function f returns mysn of a Numbered object
* param Numbered
* return void
*/
void f(Numbered s) {
	std::cout << s.mysn << std::endl;
}

/*
* Function fRef returns mysn of a Numbered object
* param const Numbered&
* return void
*/
void fRef(const Numbered& s) {
	std::cout << s.mysn << std::endl;
}

int main() {

	Numbered a, b = a, c = b;
	f(a);//1 no copy constructor, 2 if copy constructor
	f(b);//1 no copy constructor, 3 if copy constructor 
	f(c);//1 no copy constructor, 4 if copy constructor

	Numbered d, e = d, f = e;
	fRef(d);//1
	fRef(e);//2
	fRef(f);//3, copy constructor not called for const ref

	return 0;
}