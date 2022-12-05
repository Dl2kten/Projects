#include <iostream>
#include <string>
#include <sstream>

/*
* Exercise 16.49, 16.50
* Explain what happens to each call
* Add print statement to functions and check if right
*/

template <typename T> void f(T) {
	
	std::cout << typeid(t).name() << "f(T)" << std::endl;
}
template <typename T> void f(const T*) {
	std::cout << "f(const T*)" << std::endl;
}
template <typename T> void g(T) {
	std::cout << "g(T)" << std::endl;
}
template <typename T> void g(T*) {
	std::cout << "g(T*)" << std::endl;
}

int main() {
	int i = 42, * p = &i;
	const int ci = 0, * p2 = &ci;
	g(42);//can't take, g(T) not g(T&) so can take, just copy 
	g(p); //T*
	g(ci); //T
	g(p2); //T, T* g(T*)-> T is const int more specialized than g(T), was
	//thinking about how would need const conversion but that would only
	//be if taking plain ptr to const T*
	f(42); //can't take, f(T) 
	f(p); //T
	f(ci); //T
	f(p2);//T*

	return 0;
}