#include<iostream>
#include<vector>
#include<string>
#include <fstream>

/*
* Exercise 9.49
* Write a program that reads a file containing words and reports the
* longest word that contains neither ascenders nor descenders,
* ascenders are letters that extend above middle line like d or l,
* descenders are like p or g
*/

using std::cout;
using std::cin;
using std::endl;

/*
* Function findLongest, reads file and finds longest word with neither
* ascenders nor descenders
* param three const string&
* return string
*/
std::string findLongest(const std::string& file, 
	const std::string& letters) {
	/*
	* read from file into vec
	* check to see each word in vec, ascenders and descenders
	* record longest word or none recorded
	*/
	std::ifstream inputFile (file);
	std::string word, longestWord;
	std::vector<std::string> svec;
	int longest = 0;

	if (inputFile) {//check file opened
		while (inputFile >> word) {//put each string as vec element
			svec.push_back(word);
		}
	}
	else {
		std::cerr << "File failed to open." << endl;
	}

	std::string::size_type pos = 0;
	
	for (const auto& i : svec) {
		if ((i.find_first_of(letters)) == std::string::npos) {
			if (longest < i.size()) {
				longest = i.size();
				longestWord = i;
			}

		}

	}

	return (longest != 0) ? longestWord : "None found";
}

int main() {

	const std::string nonMidLetters{ "bdfhkltgjpqyi"
	"BDFHKLTGJPQYI"};

	cout << findLongest("test.txt", nonMidLetters);

	/*
	* could've compared words directly without vector
	*/
	return 0;
}