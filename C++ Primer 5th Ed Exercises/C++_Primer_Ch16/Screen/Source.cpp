#include "Screen.h"

/*
* 16.14, 16.15
* Write a screen class template that uses nontype parameters to define
* height and width of screen
* Implement input and output operators for your screen template
*/

int main() {

	Screen<10, 10> s('*');
	s.display(std::cout);

	Window_mgr wmg;
	wmg.print(std::cout);
	wmg.clear(0);
	wmg.print(std::cout);

	//user prompt
	std::cout << "Please enter height, width and char for display:\n";
	
	std::cin >> s;

	std::cout << s << std::endl;


	return 0;
}