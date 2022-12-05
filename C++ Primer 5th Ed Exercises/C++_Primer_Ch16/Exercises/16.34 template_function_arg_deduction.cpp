#include <iostream>

/*
* Exercise 16.34, 16.35, 16.36
* Is code legal
*/

template <class T> int compare(const T&, const T&);
template <typename T> T calc(T, int);
template <typename T> T fcn(T, T);
template <typename T> int f1(T, T);
template <typename T1, typename T2> int f2(T1, T2);

int main() {
	//compare("hi", "world"); no matching of const char[3] and const
	//char[6]
	compare("bye", "dad");

	double d; float f; char c;
	calc(c, 'c');
	calc(d, f);
	fcn(c, 'c');
	//fcn(d, f); double and float two different types

	int i = 0, j = 42, *p1 = &i, *p2 = &j;
	const int *cp1 = &i, *cp2 = &j;
	f1(p1, p2);
	f2(p1, p2);
	f1(cp1, cp2);
	f2(cp1, cp2);
	//f1(p1, cp1); if *p1 and *cp1 ok, but low level const cannot be 
	//ignored
	f2(p1, cp1);

	return 0;
}