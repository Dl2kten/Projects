#include <iostream>

/*
* Exercise for sections 2.3 2.4
* Testing legal references and pointers
*/
int i = 42;

int main()
{
	int i, & ri = i;
	i = 5; ri = 10;
	std::cout << i << " " << ri << std::endl;

	double ival = 42, ival2 = 10;
	double* p = &ival; // p holds the address of ival; p is a pointer to ival
	std::cout << p << " " << * p << std::endl;

	p = &ival2;
	*p = 20;

	int o, * ip = 0;

	std::cout << p << " " << *p << std::endl;

	const double pi = 3.14; // pi is const; its value may not be changed
	const double* cptr = &pi;
	double dval = 3.14;
	cptr = &dval;

	int errNumb = 0;
	int test = 0;
	int* const curErr = &errNumb;
	
	const double pie = 3.14159;
	const double* const pip = &pie;

	const int i2 = i;
	const int ic = 2;
	i = ic;

	int* p1 = &i;
	int * const p2 = p1;

	const int v2 = 0; int v1 = v2;
	int* pp1 = &v1, & r1 = v1;
	const int* pp2 = &v2, * const pp3 = &i, & r2 = v2;
	r1 = v2;
	pp2 = pp1;
	pp2 = pp3;/*pointer to a const pointer won't change the
			  object const pointer is pointing to, other
			  way around is error*/

	int& rr2 = i;
	int d = 0;
	rr2 = d;//copying value stored in int d to v1

	int null = 0, * p = null;


	return 0;

}