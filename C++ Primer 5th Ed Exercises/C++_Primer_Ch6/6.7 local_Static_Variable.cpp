#include<iostream>

/*
* Exercise 6.7
* Write a function that returns 0 when first called then generates 
* numbers in sequence when it's called again
*/

using namespace std;

/*
* Function that returns number in sequence
*/

size_t sequence() {
	static size_t num = 0;
	return num++;
}

int main() {

	for (size_t i = 0; i <= 10; ++i) {
		cout << sequence() << endl;
	}

	
	return 0;
}

