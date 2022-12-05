#include<iostream>
#include <vector>
#include <string>

/*
* Exercise 4.36, 4.37
* Write an expression to do integral multiplication
* Rewrite old-style casts with named casts
*/

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int main() {

	//4.36

	int i = 1;
	double d = 2.0;

	i = i * static_cast<int>(d);

	//4.37
	const string* ps = nullptr; char* pc; void* pv;

	pv = static_cast<void*>(const_cast<string*>(ps));
	i = static_cast<int>(*pc);
	pv = static_cast<void*>( & d);
	pc = static_cast<char*>(pv);

	return 0;
}