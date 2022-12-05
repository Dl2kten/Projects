#include<iostream>
#include"Chapter6.h"

/*
* File containing functions used in 6.1
*/

using namespace std;

/*
* Function to calculate a number's factorial
*/
void findFactorial() {
	int num;

	cout << "Please enter a positive number to see its factorial: "
		<< endl;
	cin >> num;

	int multiply = num;

	while (multiply > 1) {
		num *= --multiply;
	}

	cout << "The factorial is: " << num << endl;

	return;
}

/*
* Function that returns absolute value of its argument
*/
void absolute() {
	int val;

	cout << "Please enter a number to see its absolute value: " << endl;
	cin >> val;
	cout << "Its absolute value is: " << (val < 0 ? val *= -1 : val)
		<< endl;

	return;
}