#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

/*
* Exercise 8.10
* Write a program to store each line from file in a vector<string>,
* use an istringstream to read each element from the vector a word
* at a time
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

int main(int argc, char** argv) {

	istringstream iss("Hello");

	printInput(iss);

	return 0;
}