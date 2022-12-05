#include<iostream>

/*
* Exercise 7.31
* Define a pair of classes X and Y, X has a pointer to Y, Y has an
* object of type X
*/

using namespace std;

/*
* Class X
*/
class X {
	Y* y;
};

/*
* Class Y
*/
class Y {
	X x;
};

int main() {


	return 0;
}