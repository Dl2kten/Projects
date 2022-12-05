#include<iostream>
#include<vector>
#include<list>
#include<string>
#include <deque>
#include <forward_list>
#include <fstream>
#include <stack>

/*
* Exercise 9.52
* Use a stack to process parenthesized expressions, detect open
* parenthesis, once a close parenthesis detected after open parenthesis
* pop elements down to and including opern parenthsis off the stack, 
* push a value onto stack on indicate a parenthesized expression was 
* replaced
*/

using std::cout;
using std::cin;
using std::endl;



int main() {

	std::deque<std::string> sd{"c ", "* ", ") ", "b ",
	"- ", "e ", "( " };
	std::stack<std::string> eStack(sd);
	//keep track of how many to pop
	std::stack < std::string>::size_type popNumber = 0;
	bool parenthesis = false;

	while (!eStack.empty()) {
		std::string temp = eStack.top();
		if (!parenthesis) {
			if (temp == "( ") {
				parenthesis = true;
				eStack.pop();
			}
		}
		else {
			if (temp == ") ") {
				eStack.pop();
				eStack.push("X");
				break;
			}
			else {
				eStack.pop();
			}
		}
	}

	while (!eStack.empty()) {
		std::string temp = eStack.top();
		cout << temp;
		eStack.pop();
	}

	/*
	* Didn't really understand question here thought was suppose to use
	* a filled stack, online answers parsed string to fill up stack
	*/
	
	return 0;
}