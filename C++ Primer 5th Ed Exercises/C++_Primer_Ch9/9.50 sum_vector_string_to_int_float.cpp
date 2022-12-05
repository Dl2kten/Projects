#include<iostream>
#include<vector>
#include<list>
#include<string>
#include <deque>
#include <forward_list>
#include <fstream>

/*
* Exercise 9.50
* Write a program to process a vector<string> whose elements 
* represents integral values, find sum of all elements, change 
* and find sum of floating-point values
*/

using std::cout;
using std::cin;
using std::endl;


int main() {

	std::vector<std::string> svec1{ "2", "4", "5", "6" };
	std::vector<std::string> svec2{ "0.342", "1.342", "5.34", "6.65" };
	int sum = 0;
	float fsum = 0.0;

	for (const auto& i : svec1) {
		sum += stoi(i);
	}
	cout << "The sum for integral values is: " << sum;

	for (const auto& i : svec2) {
		fsum += stof(i);
	}
	cout << "\nThe sum for floating values is: " << fsum << endl;

	return 0;
}