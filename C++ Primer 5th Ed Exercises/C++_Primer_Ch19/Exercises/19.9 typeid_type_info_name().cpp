#include <iostream>

/*
* Exercise 19.9
* Write a program similar to the last one in this 
* section to print the names your compiler uses for common type names. If
* compiler gives output similar to text, write a funciton that will translate
* those strings to more readable ones
*/
class Base {
};
class Derived : public Base {
};

class Sales_data { };

int main() {
	int arr[10];
	Derived d;
	Base* p = &d;
	std::cout << typeid(42).name() << ", " << typeid(arr).name() << ", "
		<< typeid(Sales_data).name() << ", " << typeid(std::string).name() << ", "
		<< typeid(p).name() << ", " << typeid(*p).name() << std::endl;

	/*
	* output int, int [10], class Sales_data, class std::basic_string<char, 
	* struct std::char_traits<char>, class std::allocator<char>>, class Base*
	* __ptr64, class Base
	* quite readable unlike text
	*/
	return 0;
}