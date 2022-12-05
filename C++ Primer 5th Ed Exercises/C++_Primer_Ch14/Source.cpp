#include <iostream>

/*
* Exercise 14.50
* Conversion code from text
*/

struct LongDouble {
	LongDouble(double =0.0){}
	operator double() { return d; }
	operator float() { return d; }
private:
	double d = 0.0;
};

int main() {


	
	return 0;
}