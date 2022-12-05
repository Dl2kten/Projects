#include<iostream>
#include<map>
#include<set>
#include<string>
#include<vector>
#include <iomanip>

/*
* Exercise 17.35, 17.36
* Write a version of the program from text
* that printed the square root of 2 but this time print hexadecimal
* digits in uppercase
* Line the various floating-point values up in a column
*/


int main() {
	
	std::cout << std::setw(22) << "default format: " << 100 * sqrt(2.0)
			<< '\n'
			<< std::setw(22) << "scientific: " << std::scientific 
			<< 100 * sqrt(2.0) << '\n'
			<< std::setw(22) << "fixed decimal: " << std::fixed 
			<< 100 * sqrt(2.0) << '\n'
			<< std::setw(22) << "hexadecimal: " << std::hexfloat 
			<< 100 * sqrt(2.0) << '\n'
			<< std::setw(22) << "use defaults: " << std::defaultfloat 
			<< 100 * sqrt(2.0) << '\n'
			<< std::setw(22) << "hexdecimal uppercase: " 
			<< std::uppercase << std::hexfloat << 100 * sqrt(2.0) 
			<< std::endl;
	return 0;
}
