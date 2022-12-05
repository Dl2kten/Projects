#include<iostream>


/*
* Exercise 6.12
* Rewrite program from 6.10 to use references instead of pointers
*/

using namespace std;

/*
* Int swap function
* parameters take in the two int ptrs
* no need to return anything since ptrs can change value
*/

void intSwap(int &int1, int &int2) {
	int temp = int1;
	int1 = int2;
	int2 = temp;

	return;
}


int main() {

	int num1, num2;
	//user prompt
	cout << "Please enter two integers to be swapped: " << endl;
	cin >> num1 >> num2;

	cout << "Integer one is: " << num1 << ". Integer two is: "
		<< num2 << ".\n";

	intSwap(num1, num2);

	cout << "After using swap function, integer one is: " << num1
		<< ". Integer two is: " << num2 << "." << endl;
	
	/*
	* References prob easier as you don't have to deal with the 
	* dereference notation and no need to copy pointer objects
	*/
	return 0;
}

