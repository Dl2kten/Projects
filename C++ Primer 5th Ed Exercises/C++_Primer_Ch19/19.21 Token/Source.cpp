#include "Token.h"
#include <iostream>

/*
* Exercise 19.21, 19.22, 19.23, 19.24, 19.25
* Write own version of Token class
* Add a member of type Sales_data to Token class
* Add a move constructor and move assignment to Token
* Explain what happens if we assign a Token object to itself
* Write assignment operators that take values of each type in union
*/

int main() {

	Token token1, token2(token1), token3, token4;
	
	std::cout << token1;
	std::cout << token2;
	std::cout << token3;

	token1 = 3.14;
	std::cout << token1;
	token1 = 'c';
	std::cout << token1;
	token1 = 1;	
	std::cout << token1;

	token2 = token1;//test assign with built-in types
	std::cout << token2;
	token1 = "hello";
	std::cout << token1;
	token3 = token1;
	std::cout << token3;
	token3 = "hi";
	token1 = token3;//assign both class types
	std::cout << token1;
	token4 = Sales_data("999", 1, 2.0);
	token1 = token4;
	std::cout << token1;

	//for move operations leverage string and built-in types, string has own
	//move that moves object and leaves moved-from object valid
	Token token5(std::move(token2));
	std::cout << token5;
	std::cout << token2; //nothing happened, still value 1
	token2 = std::move(token3);
	std::cout << token2;
	std::cout << token3; //prints empty string

	token5 = token5;
	token4 = token4;
	std::cout << token5;
	std::cout << token4;
	/*
	* 19.24
	* it just assigns the same value to itself since nothing done with built-in
	* types, as in no deletion, and class types are checked if rhs is also
	* same type and then just assigns same value
	*/
	return 0;
}