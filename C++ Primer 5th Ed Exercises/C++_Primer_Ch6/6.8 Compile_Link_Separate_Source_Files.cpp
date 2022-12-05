#include<iostream>
#include"Chapter6.h"

/*
* Exercise 6.9
* Compile and link the Chapter6.h header file, fact.ccp containing
* functions, and source.cpp
*/

using namespace std;

int main() {

	findFactorial();
	absolute();

	/*
	* Visual studio compiles the separate files
	* Command line would be
	* $ CC Source.cpp fact.cpp -o main
	*/
	
	return 0;
}

