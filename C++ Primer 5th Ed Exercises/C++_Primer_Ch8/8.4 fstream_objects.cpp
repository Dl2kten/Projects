#include<iostream>
#include<vector>
#include<fstream>
#include<string>

/*
* Exercise 8.4, 8.5
* Write a function to open a file for input, read its contents into
* vector of strings, store each line as a separate element in the
* vector
* Rewrite to store each word in a separate element
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
		/*while (getline(inputFile, s)) {
			lines.push_back(s);
		}*/
		while (inputFile >> s) {
			lines.push_back(s);
		}
	}
	else {
		cerr << "Failed to read file, will return empty vector." << endl;
	}
	
	return lines;
}

int main() {

	vector<string> vs = readFile("Test.txt");

	for (auto i : vs) {
		cout << i << endl;
	}

	/*
	* Remember the header files for the functions objects used
	*/
	return 0;
}