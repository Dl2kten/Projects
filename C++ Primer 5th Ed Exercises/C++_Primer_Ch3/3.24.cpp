#include<iostream>
#include<string>
#include<vector>
#include<cctype>

/*
* Exercises 3.4
* 3.24 read integers int a vector, print sum of adjacent and first
* and last, second and last, etc. using iterators
*/

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;

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
	cout << "The sum of the adjacent elements throughout"
		<< " the list are: " << endl;

	decltype(vInt.size()) count = 0;

	for (auto index = vInt.begin(); index != vInt.end();
		++index) {
		
		if (count % 2 == 1) {//odd numbers
			auto sum = *index + *(index - 1);
			cout << sum << endl;
		}

		++count; //increase counter
	}

	/*Prind the sum of first and last, second and second last,
	* etc. Will ignore middle element if odd
	*/
	cout << "The sum of the first and last elements, "
		<< "the second and second last elements, and so on "
		<< "are: " << endl;
	for (auto index = vInt.begin(), end = vInt.end() - 1; index <  end;
		++index, --end) {
		auto sum = *index + *end;
		
		cout << sum << endl;
	}

	
	return 0;
}