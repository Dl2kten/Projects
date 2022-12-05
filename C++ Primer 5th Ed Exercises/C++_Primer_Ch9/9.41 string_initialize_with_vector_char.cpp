#include<iostream>
#include<vector>
#include<list>
#include<string>
#include <deque>
#include <forward_list>

/*
* 9.41
* Initailize a string from a vector<char>
*/

using std::cout;
using std::cin;
using std::endl;


int main() {
	std::vector<char> cvec{ 'h', 'i' };
	std::string s(cvec.cbegin(), cvec.cend());

	cout << s << endl;
	
	return 0;
}