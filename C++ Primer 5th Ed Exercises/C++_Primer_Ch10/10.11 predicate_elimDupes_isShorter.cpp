#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

/*
* Exercise 10.11
* Write a program that uses stable_sort and isShorter to sort a vector 
* passed to elimDupes, print to verify
*/

using std::cout;
using std::cin;
using std::endl;

/*
* Function print, prints the elements in a vector
* param ostream&, vector<sting>
* return void
*/
void print(std::ostream& os, std::vector<std::string>& stringvec) {
	for (const auto& i : stringvec) {
		cout << i << " ";
	}
	cout << endl;
}

/*
* Function isShorter, compares the sizes of two strings
* param two const string&
* return bool
*/
bool isShorter(const std::string& s1, const std::string& s2) {
	return s1.size() < s2.size();
}

/*
* Function elimDupes eliminates duplicate words
* param vector<string>
* return void
*/
void elimDupes(std::vector<std::string>& svec) {
	print(cout, svec);

	std::sort(svec.begin(), svec.end());

	auto iter = std::unique(svec.begin(), 
		svec.end());
	print(cout, svec);
		/*
		* printed out blanks after the unique words
		*/

	svec.erase(iter, svec.end());
	print(cout, svec);

	std::stable_sort(svec.begin(), svec.end(), isShorter);
	print(cout, svec);
}


int main() {

	std::vector<std::string> words{ "the", "quick", "fox", "jumps", 
	"over", "the", "slow", "red", "turtle"};
	elimDupes(words);


	return 0;
}