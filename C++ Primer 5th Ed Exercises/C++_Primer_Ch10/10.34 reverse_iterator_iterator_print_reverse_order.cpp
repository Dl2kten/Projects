#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<functional>
#include<fstream>

/*
* Exercise 10.34, 10.35
* Use reverse_iterator to print a a vector in reverse order
* Now print the elements in reverse order using ordinary iterator
*/

using std::cout;
using std::cin;
using std::endl;

int main() {

	std::vector<int> ivec{ 1, 2, 3, 4 };

	for (auto riter = ivec.crbegin(); riter != ivec.crend(); ++riter) {
		cout << *riter << " ";
	}
	cout << endl;

	//can also use iter + 1 != ivec.cbegin()
	for (auto iter = (ivec.cend() - 1); iter != ivec.cbegin(); --iter) {
		cout << *iter << " ";
	}
	cout << *ivec.cbegin() << endl;



	return 0;
}