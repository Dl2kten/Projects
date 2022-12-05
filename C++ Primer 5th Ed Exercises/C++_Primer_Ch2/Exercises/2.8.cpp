#include <iostream>

/*
* Exercise 2.8
* Escape sequences
*/
int main()
{
	
	std::cout << "Who goes with F\145rgus?\012" 
		<< std::endl;

	std::cout << "2\115" << '\n';//prints 2M, newline
	std::cout << '2' << "\t\x4d\n";//prints 2, tab, M, newline
	return 0;

}