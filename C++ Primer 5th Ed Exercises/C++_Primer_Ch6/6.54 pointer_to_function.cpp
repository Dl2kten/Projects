#include<iostream>
#include <vector>

/*
* Exercise 6.54, 6.55, 6.56
* Declare a function that takes two int parameters and returns an int
* and declare a vector whose wlement have this function pointer type
* Write four functions that add, subtract, multipl, and divide two ints
* and store them in vector
* Call each element in the vector and print their result
*/

using namespace std;

/*
* Function declaration
* parameter two ints
* return int
*/
int fun(int, int);

/*
* Function add two ints
*/
inline int addInt(int i, int i2) {
	return i + i2;
}

/*
* Function subtract two ints
*/
inline int subtractInt(int i, int i2) {
	return (i >= i2) ? i - i2: i2 - i;
}

/*
* Function multiply two ints
*/
inline int multiplyInt(int i, int i2) {
	return i * i2;
}

/*
* Function divide two ints
*/
inline int divideInt(int i, int i2) {
	//watch out for divide by 0
	if (i2 == 0) {
		cout << "Second argument can't be 0. This function will"
			" return default value 1." << endl;
		return 1;
	}

	return i / i2;
}

int main() {

	//need to add pointer when using decltype
	vector<decltype(fun) (*)> fp = {addInt, subtractInt, multiplyInt,
	divideInt};

	for (size_t i = 0; i < fp.size(); ++i) {
		//go through each function stored in vector with args 2, 1
		cout << fp[i](2, 1) << " ";
	}

	cout << endl;

	/*
	* wasn't sure about how to declare the vector type but it seems to 
	* be fine, online can also define as int (*)(int, int) so the
	* pointer to function type directly which makes sense... I used 
	* decltype cause it's more in line with question intention as it says
	* to use that functions pointer, hmm, it's the same
	*/

	return 0;
}
