#include <iostream>
#include <string>
#include <sstream>

/*
* Exercise 16.65, 16.66, 16.67
* Rewrite debug_rep overloaded functions that took const char* and char*
* as specializations
* What are the advantages and disadvantages of overloading vs 
* specialization
* Would defining these specializations affect function matching for
* debug_rep?
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

template<>
std::string debug_rep(const char* c) { 
	//const char* const& no call, the T* is actually better match unless
	//the variable is ref to const char*, in the text the specialization
	//is for compare versions that take const T& or unsigned, no T*
	std::cout << "const char*" << std::endl;
	//calls const T& here
	return debug_rep(std::string(c));
}

template<>
std::string debug_rep(char* c) {
	std::cout << "char*" << std::endl;
	return debug_rep(std::string(c));
}

std::string debug_rep(const std::string& s) {
	std::cout << "string&" << std::endl;
	return "" + s + "";
}

int main() {
	std::string s1("a");
	char* p = &s1[0];
	const char* cp = "abra";
	int a = 1;
	std::cout << debug_rep(s1) << std::endl;//calls const string &s
	std::cout << debug_rep(&s1) << std::endl;//calls T*
	std::cout << debug_rep("hello") << std::endl;//calls const char*
	std::cout << debug_rep(a) << std::endl;//calls const T&
	std::cout << debug_rep(p) << std::endl;//calls char*
	std::cout << debug_rep(cp) << std::endl;//calls const char*
	//all will call const T& to print the string, except string&

	/*
	* 16.66
	* Specialization means that definition must provide arguments for
	* all template parameters, matches intention of original parameter
	* but allowing specificity for certain template arguments to better
	* reflect intention, eg. const char* compare using strcmp rather than
	* comparing pointer addresses
	* overloaded functions can have different number, type of parameters,
	* different intention
	* 
	* 16.67
	* No if debug_rep is called with specific template argument to
	* specialization the specialization is called, otherwise normal
	* function matching occurs, eg. if int* const T& and T* will be
	* considered and T* is exact match no need for const conversion
	*/
	return 0;
}


