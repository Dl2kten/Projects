#include<iostream>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
#include<sstream>
#include <random>


/*
* Exercise 17.33
* Write a version of word transformation program from 11.3.6 that allows
* multiple transformations for a given word and randomly selects which
* transformation to apply
*/

/*
* Function build_map, builds map that contains rules for changing words
* param ifstream&
* return map<string, string>
*/
std::map < std::string, std::string> build_map(std::ifstream& mapFile) {
	std::string key, value;
	std::map<std::string, std::string> mss;

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
	const std::map<std::string, std::string>& tMap) {
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
			std::cout << transform(word, transformMap) << " ";
		}
		std::cout << std::endl;
	}
}

int main() {

	std::ifstream inRule1("Rules1.txt"), inRule2("Rules2.txt"),
		inRule3("Rules3.txt");
	std::ifstream inFile("SampleText.txt");

	if (!(inRule1 || inRule2 || inRule3)) {
		std::cerr << "Unable to open rules input file." << std::endl;
		return -1;
	}

	if (!inFile) {
		std::cerr << "Unable to open sample text file." << std::endl;
		return -2;
	}

	std::string resp;
	std::default_random_engine e;
	std::normal_distribution<> n(2, 1.0); //hmm how did it go, 64 within
	//1 deviation, 95 within 2?
	do {
		unsigned value = std::lround(n(e));
		if (value > 3)
			value = 3;
		//if alot of rules would have to use vector
		if (value == 3) {
			inFile.clear();
			inFile.seekg(0, std::ios::beg);
			change_word(inRule3, inFile);
		}
		if (value == 2) {
			inFile.clear();
			inFile.seekg(0, std::ios::beg);
			change_word(inRule2, inFile);
		}
		if (value == 1) {
			inFile.clear();
			inFile.seekg(0, std::ios::beg);
			change_word(inRule1, inFile);
		}
		std::cout << "Enter again for different transformation or q to "
			"quit:" << std::endl;
	} while (std::cin>>resp && resp == "again");

	return 0;
}
