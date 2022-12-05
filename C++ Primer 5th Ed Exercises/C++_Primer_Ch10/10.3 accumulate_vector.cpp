#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

/*
* Exercise 10.3
* Use accumulate to sum the elements in a vector<int>
*/

using std::cout;
using std::cin;
using std::endl;

int main() {

	std::vector<int> ivec{ 3, 4, 2, 6, 8 };

	cout << "The sum of ivec is: "
		<< std::accumulate(ivec.cbegin(), ivec.cend(), 0);


	return 0;
}