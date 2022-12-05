#include<iostream>
#include <vector>
#include <string>

/*
* Exercise 4.28, 4.29
* Print the size of each of the built-in types
* Text code
*/

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int main() {

	//4.28, bool, char, int, float, double, wide char, not including void
	char* q;

	cout << "The size of a boolean is: " << sizeof(bool) << "bytes." << endl;
	cout << "The size of a char is: " << sizeof(char) << "bytes." << endl;
	cout << "The size of an int is: " << sizeof(int) << "bytes." << endl;
	cout << "The size of a float is: " << sizeof(float) << "bytes." << endl;
	cout << "The size of a double is: " << sizeof(double) << "bytes." << endl;
	cout << "The size of a wide char is: " << sizeof(wchar_t) 
		<< "bytes." << endl;
	cout << "The size of a pointer is: " << sizeof(q)
		<< "bytes." << endl;

	//4.29
	//first cout prints the number of elements in int array x
	//second cout prints the size of a pointer divided by size of an int
	int x[10]; int* p = x;
	cout << sizeof(x) / sizeof(*x) << endl;
	cout << sizeof(p) / sizeof(*p) << endl;

	return 0;
}