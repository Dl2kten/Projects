#include<iostream>
#include<string>
#include<vector>
#include<cctype>

/*
* Exercises 3.4
* Use iterator to print size and contents of the vectors
*/

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;

int main()
{
	vector<int> v1;
	vector<int> v2(10);
	vector<int> v3(10, 42);
	vector<int> v4{ 10 };
	vector<int> v5{ 10, 42 };
	vector<string> v6{ 10 };
	vector<string> v7{ 10, "hi" };

	vector<vector<int>> vTotal = { v1, v2, v3, v4, v5 };

	decltype(vTotal.size()) index = 0;

	/*Check to see if the vectors are empty if not print out
	* all the elements
	*/

	for (auto it = vTotal.cbegin(); it != vTotal.cend(); ++it) {
		//it has type vector<vector<int>>::iterator
		if (it->begin() != it->end()) {
			auto size = it->size();
			cout << "Vector v" << index + 1 << " contains " << size
				<< " ints." << endl;
			cout << "The integers are the following: " << endl;

			for (auto it2 = it->cbegin(); it2 != it->cend();
				++it2) {//print all the integers
				cout << *it2 << endl;
			}//end of inner for loop

			++index;
		}//end of if block
		else {
			cout << "Vector v" << index + 1 << " is empty." << endl;
			++index;
		}//end of else block

	}//end of outer for loop

	/*Since there are only 2 string vectors, did not use
	for loop*/
	
	if (!v6.empty()) {
		auto size = v6.size();
		cout << "Vector v6 contains " << size << " strings."
			<< endl;
		cout << "The strings contained are the following: "
			<< endl;

		for (auto it = v6.cbegin(); it != v6.cend(); ++it) {
			cout << *it << endl;
		}
	}


	//Care when copy paste to change all the required data
	if (!v7.empty()) {
		auto size = v7.size();
		cout << "Vector v7 contains " << size << " strings."
			<< endl;
		cout << "The strings contained are the following: "
			<< endl;

		for (auto it = v7.cbegin(); it != v7.cend(); ++it) {
			cout << *it << endl;
		}
	}
	return 0;
}