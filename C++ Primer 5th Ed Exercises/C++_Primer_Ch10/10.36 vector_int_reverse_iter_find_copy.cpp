#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<functional>
#include<list>

/*
* Exercise 10.36, 10.37
* Use find to find the last element in a list of ints with value 0
* Copy the elements from positions 3 through 7 in reverse order from a
* vector of ten elements to a list
*/

using std::cout;
using std::cin;
using std::endl;

int main() {

	std::vector<int> ivec{ 1, 0, 2, 3, 4, 0, 7, 8, 0, 9};

	auto lastZero = std::find(ivec.crbegin(), ivec.crend(), 0);
	auto count = lastZero.base() - ivec.cbegin() - 1;
	//can also do ivec.size() - difference between lastZero and rbegin
	cout << "The last element with value 0 is ivec[" << count << "]."
		<< endl;

	std::list<int> ilist;
	std::copy(ivec.crbegin() + 2, ivec.crbegin() + 7, std::back_inserter
	(ilist));
	for (const auto& i : ilist)
		cout << i << " ";
	cout << endl;

	/*
	* copy's 2nd arg takes one + end, use auto to avoid missing const
	* qualifiers, could've put operation to find count in cout <<,
	* could've directly initialized list with ivec iter range
	*/
	return 0;
}