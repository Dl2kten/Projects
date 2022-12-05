#include<iostream>
#include<vector>
#include<list>
#include<string>



/*
* Exercise 9.15, 9.16
* Write a program to determine whether two vector<int>s are equal
* Repeat but compare elements in a list<int> to a vector<int>
*/

using std::cout;
using std::cin;
using std::endl;

int main() {

	std::vector<int> ivec{ 1, 2, 3, 4 };
	std::vector<int> ivec2{ 1, 2, 3, 4, 5 };

	if (ivec == ivec2)
		cout << "The two vectors are equal." << endl;
	else
		cout << "The two vectors are not equal." << endl;

	//9.16
	std::list<int> ilist{ 1, 2, 3, 4 };
	std::list<int>::const_iterator iterl;
	std::vector<int>::const_iterator iterv;
	
	if (ilist.size() != ivec.size())
		cout << "The list<int> and vector<int> are not equal." << endl;
	else {
		for (iterl = ilist.cbegin(), iterv = ivec.cbegin();
			iterl != ilist.cend(); ++iterl, ++iterv) {
			if (*iterl != *iterv) {
				cout << "The list<int> and vector<int> are not equal."
					<< endl;
				break;
			}
		}

		if (iterl == ilist.end())//if iterated to the end
			cout << "The list<int> and vector<int> are equal." << endl;

	}
		

	return 0;
}