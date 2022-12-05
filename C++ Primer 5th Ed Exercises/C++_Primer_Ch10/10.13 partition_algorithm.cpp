#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

/*
* Exercise 10.13
* Write a function that takes string and returns a bool indicating 
* whether the string has five characters or more, use to partition
* words, vector<string>, print the elements that have five or more
* characters
*/

using std::cout;
using std::cin;
using std::endl;

/*
* Function longer, checks to see if a string has five or more characters
* param const string&
* return bool
*/
bool longer(const std::string& s) {
	return s.size() > 4;
}

int main() {

	std::vector<std::string> svec{ "djaofj", "dkj", "dkafdko", "a", "dk",
	"dkjfaf", "eiorqojr", "c" };

	auto iter = std::partition(svec.begin(), svec.end(), longer);
	for (auto it = svec.cbegin(); it < iter; ++it) {
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}