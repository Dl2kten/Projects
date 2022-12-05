#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

/*
* Exercise 8.9
* Use function from 8.1 to print the contents of an istringstream object
*/

using namespace std;

/*
* Function read file, read file contents into a vector of string
* param string
* return vector
*/
vector<string> readFile(const string& fileName) {
	vector<string> lines;
	string s;
	ifstream inputFile(fileName);
	if (inputFile.is_open()) {
		while (getline(inputFile, s)) {
			lines.push_back(s);
		}
	}
	else {
		cerr << "Failed to read file, will return empty vector." << endl;
	}

	return lines;
}

int main() {

	vector<string> fileLines(readFile("Test.txt"));

	for (const auto& s : fileLines) {
		istringstream is(s);
		string word;

		while (is >> word)
			cout << word << " ";
		cout << endl;
	}

	/*
	* Using ref in for each loop, no need to copy
	*/
	return 0;
}