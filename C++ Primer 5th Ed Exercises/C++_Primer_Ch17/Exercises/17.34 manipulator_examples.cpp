#include<iostream>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
#include<sstream>
#include <iomanip>

/*
* Exercise 17.34
* Write a program that illustrates the use of each manipulator in Tables
* 17.17 and 17.18
*/


int main() {
	
	//boolaplha, 
	std::cout << std::boolalpha << true << " " << false << '\n'
		<< std::noboolalpha << true << " " << false << std::endl;
	//showbase
	std::cout << "-----------------------------------\n"
		<<  std::showbase << "showbase: " << 100 << " " << std::oct 
		<< 100 << std::noshowbase << " no base: " << 100 << std::dec 
		<< std::endl;
	//showpoint
	double i = 30;
	std::cout << "-----------------------------------\n"
		<< std::showpoint << "showpoint: " << i << " no showpoint: "
		<< std::noshowpoint << i << std::endl;
	//showpos
	std::cout << "-----------------------------------\n"
		<< std::showpos << "showpos: " << 1 << std::noshowpos
		<< " no show pos: " << 1 << std::endl;
	//uppercase
	std::cout << "-----------------------------------\n"
		<< std::uppercase <<"uppercase: " << std::hex << 1000 <<
		std::nouppercase << " no upper case: " << 1000 << std::dec
		<< std::endl;
	//setbase, only takes 0, 8, 16, 10
	std::cout << "-----------------------------------\n"
		<< std::setbase(16) << "setbase(16): " << 110 << std::setbase(10)
		<< " setbase(10): " << 110
		<< std::endl;

	//and so on, others have examples in text
	return 0;
}
