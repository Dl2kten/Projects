#include<iostream>
#include<string>
#include<vector>
#include<cctype>

/*
* Exercises 3.4
* 3.25 rewrite grade clustering program, cluster grades into
* buckets of 10, 0 to 9 is one bucket, 10 to 19, etc. 100 has
* its own bucket, take grades and put them in the right bucket
* and see how many grades are in each bucket
*/

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;

int main()
{
	//create buckets of 10: 0-9, 10-19...100
	vector<unsigned> scores(11, 0);

	//user prompt
	cout << "Enter grades to be clustered(from 0 - 100): "
		<< endl;

	unsigned grade = 0;
	auto it = scores.begin();

	while (cin >> grade) {
		if (grade <= 100) {//check to see if valid
			++*(it + (grade / 10));/*divide by 10 to find
								   the right bucket and 
								   increase value by 1*/
		}
	}
	
	//print out the values of the buckets
	for (auto i : scores) {
		cout << i << endl;
	}

	return 0;
}