#include <iostream>
#include <vector>

/*
* Exercise 16.42, 16.43, 16.44, 16.45
* Determine the type of T and val in each of the following calls
* What happends when call g(i = ci)
* What if g's function parameter is T or const T&
* What happens if call g1 on literal value, or on a varibale of type int
*/

template <typename T> void g(T&& val) {
	std::cout << val << std::endl;
	val = 5;
}

template <typename T> void f(T val) {
	std::cout << val << std::endl;
	val = 5;
}

template <typename T> void h(const T& val) {
	std::cout << val << std::endl;
	//val = 5;
}

template <typename T> void g1(T&& val) { 
	std::vector<T> v; }

int main() {
	int i = 0; const int ci = i;
	std::cout << "Function parameter T&&" << std::endl;
	g(i); //T is int& 
	//g(ci); //T is const int&, fails to assign
	g(i * ci); //T is int
	std::cout << i << std::endl;//5

	g(i = ci);//assign to i, g(i)

	std::cout << "Function parameter T" << std::endl;
	i = 0;
	f(i); //T is int
	f(ci); //T is int
	f(i * ci); //T is int
	std::cout << i << std::endl;//0

	std::cout << "Function parameter const T&" << std::endl;
	h(i); //T is int&, cannot assign as function param is const
	h(ci); //T is int&, cannot assign
	h(i * ci); //T is int&, cannot assign
	std::cout << i << std::endl;//0

	g1(42); //T is int, vector<int>, val is 42 but not used
	//g1(i); //error, T is int&, cannot create pointer to ref, compiler
	//tried to convert to pointer

	return 0;
}