#include <iostream>
#include <vector>

/*
* Computing the sum of a set of numbers, determine 
* a) the basic operation 
* b) basic operation count 
* c) if basic operation count depends on input form 
*/


int sum(std::vector<int> p_ivec) { //p_ for parameter
	//c) does not depend on input form, needs to go through all elements
	int sum = 0;
	for (const auto& i : p_ivec)
		sum += i; //a) basic operation
	/*
	* b) it's just the summation of all the elements, n
	*/
	
	return sum;
}

int main() {

	std::vector<int> ivec{ 1, 1, 2, 4, 5, 6 };
	std::cout << sum(ivec) << std::endl;

	return 0;
}
