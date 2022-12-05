#include <iostream>
#include <utility>

/*
* Exercise 16.47
* Write own version of flip function and test it by calling functions that
* have lvalue and rvalue reference parameters
*/

template<typename F, typename T, typename U>
void flip(F f, T&& t, U&& u) {
	//auto p = std::forward<U>(u);
	//auto q = std::forward<T>(t);
	//f(p, q);
	f(std::forward<U>(u), std::forward<T>(t)); //error can't convert
	//was there change in later versions? only works with rvalue ref
}


void f(int&& i, int&& j) {
	std::cout << i << " " << j << std::endl;
}

void g(std::string&& i, std::string&& j) {
	std::cout << i << " " << j << std::endl;
}

void h(double& i, double& j) {
	std::cout << i << " " << j << std::endl;
}

template<typename T>
void test(T&& t) {
	std::cout << t << std::endl;
	t = 1;
}

int main() {
	//int i = 0, j = 2;
	//flip(f, i, j);
	flip(f, 1, 2);

	//std::string s1("a"), s2("b");
	//flip(g, s1, s2);
	flip(g, std::string("Hi"), std::string("Hello"));
	//double d1 = 0.6, d2 = 1.2;
	//flip(h, d1, d2);
	//flip(h, 0.5, 1.2);
	//why does only int work...
	int i = 0;
	test(i);
	std::cout << i << std::endl;
	test(2);
	return 0;
}