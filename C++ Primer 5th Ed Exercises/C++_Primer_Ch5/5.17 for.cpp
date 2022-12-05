#include<iostream>
#include<vector>

/*
* Exercise 5.17
* Determine whether one vector is a prefix of the other given two 
* vectors of ints, for vectors of unequal size compare using the number
* of element of the smaller one
*/

using namespace std;

int main() {

	/*
	* 5.17 Not sure what prefix means, the ints of the first vector should
	* be smaller than the ints of the second at the same position?
	* two vector ints
	* compare the size
	* for loop until one of the elements is smaller or end
	*/

	vector<int> vInt = { 0, 1, 1, 2, 0 };
	vector<int> vInt2 = { 1, 1, 2, 3, 5, 8 };
	bool prefix = true;

	size_t max;

	if (vInt.size() <= vInt2.size())
		max = vInt.size();
	else
		max = vInt2.size();

	for (int i = 0; i < max; ++i) {
		if (vInt[i] > vInt2[i])//if element is bigger in first vector
			prefix = false;
	}

	if (prefix)
		cout << "True" << endl;
	else
		cout << false << endl;
	

	return 0;
}