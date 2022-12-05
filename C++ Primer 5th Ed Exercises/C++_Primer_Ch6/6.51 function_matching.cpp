#include<iostream>

/*
* Exercise 6.51
* Write all four version of function f from text and check answers
*/

using namespace std;

/*
* Functions that take different arguments
*/
void f() {
	cout << "No parameter." << endl;
}

void f(int) {
	cout << "One int parameter." << endl;
}

void f(int, int) {
	cout << "Two int parameters." << endl;
}

void f(double, double = 3.14) {
	cout << "Two double parameters." << endl;
}



int main() {

	//f(2.56, 42);
	f(42);
	f(42, 0);
	f(2.56, 3.14);

	return 0;
}
