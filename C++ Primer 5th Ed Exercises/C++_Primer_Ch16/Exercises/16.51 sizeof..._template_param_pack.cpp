#include <iostream>
#include <string>


/*
* Exercise 16.51, 16.52
* Determine what sizeof...(Args) and sizeof...(rest) is for calls in text
* Write a program to check
*/

template<typename T, typename...Args>
void foo(const T& t, const Args&...rest) {
	std::cout << "sizeof... Args " << sizeof...(Args) << std::endl;
	std::cout << "sizeof... rest " << sizeof...(rest) << std::endl;
}


int main() {
	int i = 0; double d = 3.14; std::string s = "how now brown cow",
		s2 = "a";
	foo(i, s, 42, d); //3 and 3
	foo(s, 42, "hi"); //2 and 2
	foo(d, s); //1 and 1
	foo("hi"); //0 and 0
	foo(i, s, s2, 42, d);//so is the template 
	//parameter pack and the function parameter pack always the same?
	//here its 4 and 4 but two of them are same type
	return 0;
}