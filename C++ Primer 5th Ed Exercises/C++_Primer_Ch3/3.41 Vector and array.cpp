#include<iostream>
#include<string>
#include<cstddef>
#include<vector>
#include<iterator>
#include<cstring>

/*
* Exercise 3.41, 3.42
* Initialize vector from int array
* Copy vector of ints into an array of ints
*/

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::begin;
using std::end;

int main()
{
	//3.41

	int intArray[] = { 0, 1, 2 };

	vector<int> vInts(begin(intArray), end(intArray));

	//3.42
	int intArray2[3];
	int cnt = 0;

	for (auto i : intArray2) {//check values
		cout << i << " ";
	}
	cout << endl;

	for (auto i : vInts) {
		intArray2[cnt] = i;
		cnt++;
	}

	for (auto i : intArray2) {//check
		cout << i << " ";
	}

	return 0;
}