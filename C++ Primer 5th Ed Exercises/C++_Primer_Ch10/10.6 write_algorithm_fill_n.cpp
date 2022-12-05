#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

/*
* Exercise 10.6
* Set a sequence of int values to 0 using fill_n
*/

using std::cout;
using std::cin;
using std::endl;

int main() {

	std::vector<int> ivec{ 0, 3, 4, 2, 6, 2 };
	std::fill_n(ivec.begin(), ivec.size(), 0);

	for (const auto& i : ivec)
		cout << i << " ";


	return 0;
}