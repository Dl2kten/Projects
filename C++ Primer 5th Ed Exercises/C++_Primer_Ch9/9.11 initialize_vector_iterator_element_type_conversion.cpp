#include<iostream>
#include<vector>
#include<list>
#include<string>



/*
* Exercise 9.11, 9.13
* Show an example of each of the six ways to create and intialize a
* vector
* Initialize a vector<double> from a list<int> and vector<int>
*/

using std::cout;
using std::cin;
using std::endl;

int main() {

	std::vector<int> ivec();//default constructor
	//initialize with brace list
	std::vector<int> ivec2{ 1, 2, 3, 4 };
	std::vector<int> ivec3 = { 1, 2 };
	//copy initialize
	std::vector<int> ivec4(ivec2);
	std::vector<int> ivec5 = ivec2;
	//initialize with iterator range
	std::vector<int> ivec6(ivec3.cbegin(), ivec3.cend());
	//initialize with size
	std::vector<int> ivec7(5);
	//initialize with size and value
	std::vector<int> ivec8(5, 10);
		
	//9.13
	std::list<int> ilist{ 1, 2, 3, 4 };
	std::vector<int> ivec9{ 1, 2 };

	std::vector<double> dvec(ilist.cbegin(), ilist.cend());
	std::vector<double> dvec2(ivec9.cbegin(), ivec9.cend());

	for (const auto& i : dvec)
		cout << i << " ";
	cout << endl;


	for (const auto& i : dvec2)
		cout << i << " ";
	cout << endl;


	return 0;
}