#include<iostream>

/*
* Exercise 8.1, 8.2
* Write a function that takes and returns istream&, read stream until
* end-of-file, print what it reads to standart output, reset stream
* Test with cin
*/

using namespace std;

/*
* Function printInput prints input from istream until eof
* param istream&
* return istream&
*/
istream& printInput(istream& is) {
	string s;

	//y does is.eof() print the last string out one more time after eof?
	while (is >> s) {
		cout << s << " ";
	}
	is.clear();

	return is;
}

int main() {

	printInput(cin);

	return 0;
}