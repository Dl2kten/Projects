#include <iostream>
#include <string>

/*
* Exercise 18.20
* In the text code determine which function, if any matches the call to compute,
* list the candidata and viable functions, what type conversions, if any, are
* applied to the argument to match the parameter in each viable function, what
* would happen if the using declaration were located in main before call to 
* compute, answer same questions as before
*/

namespace primerLib {
	void compute();
	void compute(const void*);
}
//using primerLib::compute;

void compute(int) {}
void compute(double, double = 3.4) {}
void compute(char*, char* = 0) {}

void f()
{
	/*
	* Candidate functions are primerLib::compute(), primerLib:compute(const 
	* void*), compute(int), compute(double, double = 3.4), compute(char*, 
	* char* = 0)
	* viable functions are compute(int), compute(double, double=3.4) 0 
	* converted to double, compute(char*, char* = 0) 0 converted to nullptr, 
	* primerLib::compute(const void*) 0 converted to void*
	* The called function is compute(int), otherwise ambiguous call
	*/
	compute(0);
}

int main() {
	using primerLib::compute;
	/*
	* primerLib::compute functions are declared inside main
	* compute inside f() does not see the primerLib compute functions, so
	* conversions for compute(double, double = 3.4) and compute(char*, char*=0),
	* compute determined at compile-time calls compute(int)
	*/
	f();


	return 0;
}