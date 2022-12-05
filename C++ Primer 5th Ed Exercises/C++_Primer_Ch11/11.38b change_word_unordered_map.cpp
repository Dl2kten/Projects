#include<iostream>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
#include<sstream>
#include <unordered_map>

/*
* Exercise 11.38b
* Rewrite to use an unordered_map
*/

using std::cout;
using std::cin;
using std::endl;

/*
* Function build_map, builds map that contains rules for changing words
* param ifstream&
* return map<string, string>
*/
std::unordered_map < std::string, std::string> build_map(std::ifstream& mapFile) {
	std::string key, value;
	std::unordered_map<std::string, std::string> mss;

	while (mapFile >> key && getline(mapFile, value)) {
		if (value.size() > 1)
			mss[key] = value.substr(1);//getline will include the space
		else
			throw std::runtime_error::runtime_error("no rule for " + key);
	}
	return mss;

}


/*
* Function transform, checks and transforms words according to rules
* param string&, const map<string,string>&
* return string&
*/
const std::string& transform(const std::string& w, 
	const std::unordered_map<std::string,std::string>& tMap) {
	auto mss_iter = tMap.find(w);
	if (mss_iter != tMap.cend()) {
		return mss_iter->second;
	}
	else {
		return w;
	}
}


/*
* fuction change_word, changes specific words based on rules set by an
* input file
* param two ifstream&
* return void
*/
void change_word(std::ifstream& rules, std::ifstream& inFile) {
	auto transformMap = build_map(rules);
	std::string temp;

	while (getline(inFile, temp)) {
		std::istringstream iss(temp);
		std::string word;
		while (iss >> word) {
			cout << transform(word, transformMap) << " ";
		}
		cout << endl;
	}
}



int main() {

	std::ifstream inRule("Rules.txt");
	std::ifstream inFile("SampleText.txt");

	if (!inRule) {
		std::cerr << "Unable to open rules input file." << endl;
		return -1;
	}

	if (!inFile) {
		std::cerr << "Unable to open sample text file." << endl;
		return -2;
	}

	change_word(inRule, inFile);

	return 0;
}