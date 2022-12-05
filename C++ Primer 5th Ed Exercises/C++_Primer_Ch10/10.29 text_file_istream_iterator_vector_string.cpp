#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<functional>
#include<fstream>

/*
* Exercise 10.29
* Use stream iterators to read a text file int a vector of strings
*/

using std::cout;
using std::cin;
using std::endl;



int main() {

	std::ifstream infile("Strings.txt");

	if (!infile) {
		cerr << "Unable to open file." << endl;
		return -1;
	}

	std::istream_iterator<std::string> sin_it(infile), sin_eof;
	std::vector<std::string> svec(sin_it, sin_eof);

	for (const auto& s : svec)
		cout << s << " ";
	cout << endl;

	return 0;

	/*
	* Make sure to check if file is opened
	*/
}