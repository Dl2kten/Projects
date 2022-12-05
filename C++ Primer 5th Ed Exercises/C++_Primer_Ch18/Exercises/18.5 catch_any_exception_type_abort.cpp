#include <iostream>
#include <cstdlib>

/*
* Exercise 18.5
* Modify main function to catch any of the exception types shown in 
* Figure 18.1
*/

int main() {

	try {
		throw std::range_error("range error");//replace with any of the
		//exception types to check and see
	}
	catch (std::range_error re) {
		std::cerr << re.what() << std::endl;
		abort();
	}
	



	return 0;
}