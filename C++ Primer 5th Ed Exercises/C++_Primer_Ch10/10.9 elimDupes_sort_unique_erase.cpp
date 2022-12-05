#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

/*
* Exercise 10.9
* Implement own version of elimDups, test by printing the vector after
* input, after unique, and after erase
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
}

int main() {

	std::vector<std::string> words{ "a", "b", "a", "c", "d", "e", "b" };
	elimDupes(words);


	return 0;
}