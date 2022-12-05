#include<iostream>

/*
* Exercise 4.9, 4.10, 4.11
* Text code
* Write condition for a while loop that stop when value is 42
* Write expression that tests and ensures a > b which is > c which is > d
*/

using std::cout;
using std::cin;
using std::endl;

int main() {

	//4.9
	const char* cp = "Hello World";
	if (cp && *cp)//if cp and *cp are non zero
		cout << "True" << endl;
	else
		cout << "False" << endl;

	//4.10

	int i = 0;

	while ( i != 42) {//stop if i is 42 else keep read in ints
		cin >> i;
	}

	//4.11
	int a = 3;
	int b = 2;
	int c = 1;
	int d = 0;

	if(a > b && b > c && c > d)//a>b>c would become true>c
		cout << "True" << endl;
	else
		cout << "False" << endl;

	//testing some variable values
	double e;
	e = i = 3.5;
	cout << e << " ";
	i = e = 3.5;
	cout << i << endl;

	double dval; int ival; int* pi = &a;
	dval = ival = *pi = 0;

	int* ptr = &i;

	if (ptr != 0 && *ptr++) //basically checks the same thing
		cout << "true" << endl;

	a = 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2;
	b = -30 * 3 + 21 / 5;
	c = -30 + 3 * 21 / 5;
	d = 30 / 3 * 21 % 5;
	int f = -30 / 3 * 21 % 4;

	std::vector<std::string>::iterator it;

	*it++;
	it->empty();
	it++->empty();
	return 0;
}