#include <iostream>

/*
* Exercise for sections 2.5
* Testing auto, decltype
*/
int i = 42;

int main()
{
	int i = 0, & r = i;
	const int ci = i, & cr = ci;

	auto a = r;//a is int
	auto b = ci;//b is int
	auto c = cr;//c is int
	auto d = &i;//d is pointer to int
	auto e = &ci;//e is pointer to const int
	auto &g = ci;//g is a constant reference to constant int

	a = 42; b = 42; c = 42;
	//d = 42; e = 42; g = 42;
	/*d and e cannot be initialized with int
	g cannot change value*/

	const int j = 42;
	auto k = j;//k is int
	const auto &l = j;//l is const reference to const int
	auto* p = &j;//p is pointer to const int
	const auto j2 = j, & k2 = j;/*j2 is const int, k2 is 
								const ref to const int*/


	int m = 3, n = 4;
	decltype(m) u = m;//p is an int with value of 3
	decltype((n)) v = m;//q is an reference to int m
	std::cout << ++u << " " << ++v << std::endl;

	int aa = 3, bb = 4;
	decltype(aa)cc = aa;
	decltype(aa = bb)dd = aa;
	std::cout << cc << " " << dd << std::endl;

	return 0;

}