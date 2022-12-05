#include <iostream>
#include <string>

/*
* Exercise 18.15, 18.16, 18.17
* Explain the differences between using declarations and directives
* Explain text code assuming using declarations for all the members of 
* namespace Exercise are located at location position 1, what if they appear
* at position 2, answer same question but replace using declaration with
* using using directive for namespace Exercise
* Write code to test
*/

namespace Exercise {
	int ivar = 1;
	double dvar = 0;
	const int limit = 1000;
} 

int ivar = 0;

// position 1
/*
* If using declarations appeared here would be global scope, name collision
* with ivar, error
* If using directive, still global, name collision, ivar error
*/
//using Exercise::ivar;
//using Exercise::dvar;
//using Exercise::limit;

//using namespace Exercise;

void manip() {
	// position 2
	/*
	* if using declarations local scope, no name collision with ivar, *dvar
	* redefinition
	* if using directive global scope, name collision with ivar
	*/
	//using Exercise::ivar;
	//using Exercise::dvar;
	//using Exercise::limit;

	using namespace Exercise;
	double dvar = 3.1416;
	int iobj = limit + 1;
	//++ivar;
	++::ivar;
}

int main() {
	
	/*
	* 18.15
	* using declarations only inject the specified namespace members like 
	* declaring a local alias of that member, follows all the scope rules as
	* if local variable, function
	* using directive inject all members of namespace into enclosing scope
	* of namespace and using directive, can result in name collision which is
	* permitted but to use must specify which version
	*/

	manip();


	return 0;
}