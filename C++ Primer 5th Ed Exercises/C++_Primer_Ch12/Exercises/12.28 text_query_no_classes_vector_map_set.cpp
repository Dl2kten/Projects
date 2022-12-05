#include <iostream>
#include <memory>
#include <vector>
#include <new>
#include <memory>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
/*
* Exercise 12.28
* Implement text queries without defining classes to manage the data,
* take a file and interact with a user to query for words in that file,
* use vector, map, and set containers to hold data for file and to
* generate results for queries
*/
using sz = std::vector<std::string>::size_type;


int main() {

	std::ifstream in("Text.txt");
	std::vector<std::string> svec;
	std::map<std::string, std::set<sz>> text_map;
	if (!in) {
		std::cerr << "File could not be opened." << std::endl;
		return -1;
	}

	std::string line, word;
	while (getline(in, line)) {
		svec.push_back(line);
	}

	for (sz i = 0; i < svec.size(); ++i) {
		std::istringstream iss(svec[i]);
		
		while (iss >> word) {
			
			if (text_map.find(word) == text_map.end()) {
				std::set<sz> iset{ i };
			
				for (decltype(i) j = i + 1; j < svec.size(); ++j) {
					std::istringstream iss2(svec[j]);
					std::string word_compare;
					while (iss2 >> word_compare) {
						if (word == word_compare) {
							iset.insert(j);
						}
					}
				}
			
				text_map.insert(std::pair<std::string, std::set<sz>>
					(word, iset));
			}

		}

	}

	do {
		std::cout << "Enter word to look for or enter q to quit: \n";
		std::string s;

		if (!(std::cin >> s) || s == "q") break;

		auto element = text_map.find(s);
		if (element == text_map.end()) {
			std::cout << "\nWord not found.\n";
		}
		else {
			for (const auto& i : element->second)
				std::cout << "(line" << i << ")" << svec[i] << "\n";
			std::cout << std::endl;
		}
	} while (true);

	/*
	* I like while loop there's nothing to run once and then check or I
	* don't see it, it would be nice if can have conditions inside while
	*/
	return 0;
}


