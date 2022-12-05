#include <iostream>
#include <string>
#include <sstream>

/*
* Exercise 16.56, 16.57
* Write and test variadic version of errorMsg
* Compare with error_msg from 6.2.6
*/

template<typename T>
std::string debug_rep(const T& t) {
	std::ostringstream os;
	os << t;
	return os.str();
}

template<typename T>
std::string debug_rep(T* t) {
	std::ostringstream os;
	os << "pointer: " << t;
	if (t)
		os << " " << *t;
	else
		os << " null pointer";
	return os.str();
}

std::string debug_rep(const std::string& s) {
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

template<typename T>
std::ostream& print(std::ostream& os, const T& t) {
	return os << t;
}

template<typename T, typename... Args>
std::ostream& print(std::ostream& os, const T& t, const Args&... rest) {
	os << t << ", ";
	return print(os, rest...);
}

template<typename...Args>
std::ostream& errorMsg(std::ostream& os, const Args&...rest) {
	return print(os, debug_rep(rest)...);
}

int main() {
	std::string s("error detected");

	errorMsg(std::cout, s, &s, "error #", &s[0]);

	/*
	* 16.57
	* void error_msg(initializer_list<string> il) {
	*	for (auto beg = il.begin(); beg != il.end(); ++beg)
	*	cout << *beg << " " ;
	*	cout << endl;}
	* Advantages of variadic is can have different types and different
	* number of params
	* Advantage of initializer_list is can have different number of params
	* don't need instantiation, performance benefit
	*/
	return 0;
}