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
	 //user prompt
	cout << "Please enter 10 integers: " << endl;

	vector<int> iVec;
	int count = 0;

	while (count < 10) {//take in first 10 integers entered
		int temp = 0;
		cin >> temp;
		iVec.push_back(temp);
		++count;
	}

	cout << "The integers multiplied by 2: " << endl;

	for (auto it = iVec.begin(); it != iVec.end(); ++it) {
		*it *= 2;
		cout << *it << endl;
	}
	
	
	return 0;
}