#include <iostream>

/*
* Exercise 14.50, 14.51
* Conversion code from text
*/

struct LongDouble {
	LongDouble(double = 0.0) {}
	operator double() { return d; }
	operator float() { return d; }
private:
	double d = 0.0;
};

void calc(int) { std::cout << "int" << std::endl; }
void calc(LongDouble) { std::cout << "ld" << std::endl; }

int main() {

	LongDouble IdObj;
	//int ex1 = IdObj; ambiguous call
	float ex2 = IdObj;//float operator
	//14.51
	double dval = 0.0;
	calc(dval);//int selected standard conversion vs class conversion
	
	return 0;
}