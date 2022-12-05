#include <iostream>

/*
* Exercise 18.4
* Looking ahead to the inheritance hierarchy in Figure 18.1, explain what’s 
* wrong with the following try block. Correct it.
*/

int main() {

	/*
	
	try {
		// use of the C++ standard library
	}
	catch (exception) {
		// ...
	}
	catch (const runtime_error& re) {
		// ...
	}
	catch (overflow_error eobj) { // ... }
	
	It's in reverse to the way that the exceptions should be ordered, the
	most general is at the top while the most specific is at bottom

	try {
	} catch(const overflow_err& eobj) {
	} catch(const runtime& re) {
	} catch(exception) {} and according to best practices ought to define
	types related by inheritance as ref
	*/


	return 0;
}