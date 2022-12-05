#include <iostream>
#include <string>


/*
* Exercise 16.53, 16.54, 16.55
* Write own version of the print functions and test them by printing one,
* two, and five arguments, each of which should have different types
* What happens if call print on a type that doesn't have <<
* Explain what happens if nonvariadic function template is declared after
* variadic function template
*/


template<typename T>
std::ostream& print(std::ostream& os, const T& t) {
	return os << t;
}

template<typename T, typename... Args>
std::ostream& print(std::ostream& os, const T& t, const Args&... rest) {
	os << t << ", ";
	return print(os, rest...);
}

struct No_output {
	No_output() = default;
};

int main() {
	int i = 0;
	std::string s("abra");
	print(std::cout, i, s, 0.5, true, "kadabra");
	std::cout << std::endl;
	print(std::cout, i, s);
	std::cout << std::endl;
	print(std::cout, i);
	std::cout << std::endl;

	//No_output no;
	//print(std::cout, no);//error C2679: binary '<<': no operator 
	//found which takes a right-hand operand of type 'const T' (or there 
	//is no acceptable conversion)

	/*
	* 16.55
	* error, on the last recursive call only 1 arg given, last of the
	* rest... is passed to const T& and the next call there's only
	* std::ostream&
	* no matching overloaded function found, error C2780: 'std::ostream 
	* &print(std::ostream &,const T &,const Args &...)': expects 3 
	* arguments - 1 provided
	*/
	return 0;
}