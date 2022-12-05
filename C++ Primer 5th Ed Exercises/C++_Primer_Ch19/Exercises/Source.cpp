#include <iostream>

/*
* Exercise 19.26
* Explain these declarations and indicate whether they are legal
*/

//declarations with linkage directive of "C" language, compiler will generate
//appropriate code provided supports linkage directives to C, the two
//declarations below not legal as C does not support overloaded functions
//error C2733: 'compute': you cannot overload a function with 'extern "C"' 
//linkage
extern "C" int compute(int*, int);
//extern "C" 
double compute(double*, double);

int main() {
	

	return 0;
}