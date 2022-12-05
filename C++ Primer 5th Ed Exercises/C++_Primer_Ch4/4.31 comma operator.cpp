#include<iostream>
#include <vector>
#include <string>

/*
* Exercise 4.31, 4.32
* Rewrite for loop using postfix operators
* Text code
*/

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int main() {

	//4.31
	vector<int> ivec = { 0, 1, 2, 3, 4 };
	vector<int>::size_type cnt = ivec.size();
	// assign values from size... 1 to the elements in ivec
	for (vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt) {
		ivec[ix] = cnt;
		cout << ivec[ix];
	}

	cnt = 5;

	for (vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--) {
		ivec[ix] = cnt;
		cout << ivec[ix];
	}
	/*Same results, if the comparison of ix and ivec.size() is not 
	* processed first then there would be issue
	*/

	//4.32 sets int pointer to equal first element of ia and checks
	//ix doesn't equal 5 and pointer doesn't equal to one past last element
	constexpr int size = 5;
	int ia[size] = { 1,2,3,4,5 };
	for (int* ptr = ia, ix = 0; ix != size && ptr != ia + size; ++ix, ++ptr)
	{
		cout << ia[ix] << " " << endl;
	}

	//testing
	int x = 0;
	int y = 1;
	int a = (size < 6) ? ++x, ++y : --x;/*Why did --y become a local variable
									that needs to be defined?*/
	(size < 6) ? ++x, ++y : --x, --y; // this is okay
	//so evaluates to (size < 6 ? (++x, ++y) : --x), --y

	return 0;
}