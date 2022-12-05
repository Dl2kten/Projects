#include <iostream>
#include <string>
#include <sstream>

/*
* Exercise 16.48
* Write own versions of debug_rep functions
*/

template<typename T>
std::string debug_rep(const T &t) {
	std::ostringstream os;
	os << t;
	return os.str();
}

template<typename T>
std::string debug_rep(T *t) {
	std::ostringstream os;
	os << "pointer: " << t;
	if (t)
		os << " " << *t;
	else
		os << " null pointer";
	return os.str();
}

std::string debug_rep(const std::string &s) {
	std::cout << "string&" << std::endl;
	return "" + s + "";
}

std::string debug_rep(char* c) {
	std::cout << "char*" << std::endl;
	return debug_rep(std::string(c));
}

std::string debug_rep(const char* c) {
	std::cout << "const char*" << std::endl;

	return debug_rep(std::string(c));
}

int main() {
	std::string s1("a");
	char* p = &s1[0];
	int a = 1;
	std::cout << debug_rep(s1) << std::endl;//calls const string &s
	std::cout << debug_rep(&s1) << std::endl;//calls T*
	std::cout << debug_rep("hello") << std::endl;//calls const char*
	std::cout << debug_rep(a) << std::endl;//calls const T&
	std::cout << debug_rep(p) << std::endl;//calls char*

	return 0;
}