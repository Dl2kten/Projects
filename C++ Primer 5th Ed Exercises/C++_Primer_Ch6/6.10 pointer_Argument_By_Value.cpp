#include<iostream>


/*
* Exercise 6.10
* Use pointers to write a function to swap the value of two ints
*/

using namespace std;

/*
* Int swap function
* parameters take in the two int ptrs
* no need to return anything since ptrs can change value
*/

void intSwap(int* int1, int* int2) {
	int temp = *int1;
	*int1 = *int2;
	*int2 = temp;

	return;
}


int main() {

	int *intp, *intp2, num1, num2;
	//user prompt
	cout << "Please enter two integers to be swapped: " << endl;
	cin >> num1 >> num2;
	intp = &num1;
	intp2 = &num2;

	cout << "Integer one is: " << *intp << ". Integer two is: "
		<< *intp2 << ".\n";

	intSwap(intp, intp2);

	cout << "After using swap function, integer one is: " << *intp
		<< ". Integer two is: " << *intp2 << "." << endl;
	
	return 0;

	/*
	* Didn't need to use the two pointers, could've just used address
	* of the two ints as arguments for intSwap()
	*/
}

