#include <iostream>
#include <vector>

/*
* Check whether all elements in a given array are distince, determine 
* a) the basic operation 
* b) basic operation count 
* c) if basic operation count depends on input form 
*/


bool distinct_check(std::vector<std::string> p_svec) { //p_ for parameter
	//c) does depend on input form, 1st and 2nd elements could be same
	//best case 1 worst case covered in b)
	int count = 0;
	for (decltype(p_svec.size()) i = 0; i < p_svec.size(); ++i) {
		for (auto j = i + 1; j < p_svec.size(); ++j) {
			std::cout << ++count << std::endl;
			if (p_svec[i] == p_svec[j]) { // a) basic operation
				return false;
			}
		}
	}

	std::cout << count << std::endl;
	return true;
	/*
	* b) hmm how do i do this... factorial? Not factorial it's summation of
	* n + n-1 ... 0, i don't know how to write it, will loop up summation 
	* notation
	*/
}

int main() {

	std::vector<std::string> svec1{ "a", "b", "c", "d"};
	std::vector<std::string> svec2{ "a", "a", "b", "c", "d" };
	std::cout << std::boolalpha << distinct_check(svec1)
		<< std::noboolalpha << std::endl;
	std::cout << std::boolalpha << distinct_check(svec2)
		<< std::noboolalpha << std::endl;

	return 0;
}
