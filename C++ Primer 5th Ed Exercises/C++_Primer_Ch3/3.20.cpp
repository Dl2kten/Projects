#include<iostream>
#include<string>
#include<vector>
#include<cctype>

/*
* Exercise 3.3.2
* 3.20 read integers into vec, compute and print sum of 
* adjacent pairs and first and last, second and last, etc.
*/

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::toupper;

int main()
{
	vector<int> vInt;

	int userInt = 0;
	//user prompt
	cout << "Please enter some integers: " << endl;

	while (cin >> userInt) {/*Fill up the vector with user
							entered values*/
		vInt.push_back(userInt);
	}

	decltype(vInt.size()) index = 0;

	/*print the sum of each pair of adjacent elements, if odd
	* ignore last element, wasn't stated what to do with last
	* element if odd
	*/
	for (decltype(vInt.size()) index = 0; index < vInt.size()-1;
		index += 2) {
		cout << "The sum of the " << index + 1 << " element "
			<< "and the " << index + 2 << " element is: "
			<< vInt[index] + vInt[index + 1] << endl;
	}

	/*Prind the sum of first and last, second and second last,
	* etc. Will ignore middle element if odd
	*/
	for (decltype(vInt.size()) index = 0; index < vInt.size() / 2;
		++index) {//reads up to halfway
		int sum = vInt[index] + vInt[vInt.size() - (index + 1)];

		cout << "The sum of the " << index + 1 << " element "
			<< " and the " << vInt.size() - index
			<< " element is " << sum << "." << endl;
	}

	return 0;
}