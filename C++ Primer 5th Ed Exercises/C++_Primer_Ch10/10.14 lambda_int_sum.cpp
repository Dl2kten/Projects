#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

/*
* Exercise 10.14, 10.15
* Write a lambda that takes two ints and return their sum
* Write a lambda that captures int from its enclosing function and takes
* and int parameter, return the sum of the two ints
*/

using std::cout;
using std::cin;
using std::endl;

/*
* Function intGiver, defines local int
* param
* return void
*/
void intGiver() {
	int i = 0;
	[i](int a) {return a + i; };
}

int main() {

	auto f = [](int a, int b) {return a + b; };

	return 0;
}