#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<functional>

/*
* Exercise 10.24
* Use bind and check_size to find the first element in vector int that
* has a value greater than the length of a specified string value
*/

using std::cout;
using std::cin;
using std::endl;

/*
* Function check_size, checks to see if an int has a value bigger than
* size
* param int, sting::size_type
* return bool
*/
bool check_size(int a, std::string::size_type sz) {
	return a > sz ;
}


int main() {
	const std::string svalue = "Hello";
	
	std::vector<unsigned> ivec{ 1, 2, 3, 4, 5, 6, 7, 9, 10, 12 };

	auto iter = std::find_if(ivec.begin(), ivec.end(),
		std::bind(check_size, std::placeholders::_1, svalue.size()));
	
	for (; iter < ivec.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;

	/*
	* need to consider case where int value is negative
	*/
	return 0;
}