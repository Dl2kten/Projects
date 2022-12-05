#include<iostream>
#include<string>
#include<vector>

/*
* Exercise 3.3.2
* 3.16 Print the size and contents of vectors
*/

using std::cin;
using std::cout;
using std::endl;
using std::string;
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

	for (auto v : vTotal) {//vectors of type int

		if (!v.empty()) {//not empty
			auto size = v.size();
			cout << "Vector v" << index+1 << " contains " << size
				<< " ints." << endl;
			cout << "The integers are the following: " << endl;
			
			for (auto i : v) {//print all the integers
				cout << i << endl;
			}//end of inner for loop

			++index;
		}//end of if block
		else {
			cout << "Vector v" << index+1 << " is empty." << endl;
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

		for (auto i : v6) {
			cout << i << endl;
		}
	}

	//Care when copy paste to change all the required data
	if (!v7.empty()) {
		auto size = v7.size();
		cout << "Vector v7 contains " << size << " strings."
			<< endl;
		cout << "The strings contained are the following: "
			<< endl;

		for (auto i : v7) {
			cout << i << endl;
		}
	}
	return 0;
}