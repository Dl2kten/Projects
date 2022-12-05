#include<iostream>
#include<Chapter6.h>
/*
* Exercise 6.3, 6.4, 6.5
* Test own version of factorial program
* Write function that asks for a number and calculates the factorial, 
* call it from main
* Write function to return absolute value of its argument
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

int main() {

	/*
	* 6.3
	* int as parameter
	* int multiplied by itself -1, decrement till 1
	*/

	findFactorial();
	absolute();

	/*
	* Didn't consider the number to be negative, could've just done
	* -val
	*/
	return 0;
}

