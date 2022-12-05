#include <iostream>
#include <vector>

/*
* Computing n!, determine 
* a) the basic operation 
* b) basic operation count 
* c) if basic operation count depends on input form 
*/


int factorial(unsigned n) { //p_ for parameter
	//c) does not depend on input form, needs to go through all elements
	int product = n;
	
	if(n > 1)
		product *= factorial(--n); // a) basic operation
	
	return product;

	/*
	* b) count is n - 1, (summation of 1 to n?)
	*/
}

int main() {

	std::cout << factorial(3) << std::endl;

	return 0;
}
