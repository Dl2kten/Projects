#include "TextQuery.h"
#include <sstream>
#include <string>

/*
* Function TextQuery parses input file
* param std::ifstream&
* return void
*/
void TextQuery::parseText(std::ifstream& in)
{
	std::string line, word;
	while (getline(in, line)) {
		text.push_back(line);
		std::istringstream iss(line);
		int n = text.size() - 1;//current line number, for 1st element
		//it would be 1 - 0, line 0
		while (iss >> word) {
			//get reference to the set and call upon the set using the
			//key and just add the line number
			auto& lineNumber = (*text_map)[word];
			lineNumber.insert(n);
		}
	}

}

/*
* Function void query sees if and how many times a word occurs
* param const std::string&
* return std::set<sz>
*/
std::set<std::vector<std::string>::size_type>& TextQuery::query
(const std::string& s) const {
	static std::set<std::vector<std::string>::size_type> none;
	wordSought = s;

	auto element = text_map->find(s);
	if (element == text_map->end()) {
		//throw std::out_of_range::out_of_range("Word not found.");
		return none;
	}
	else {
		return element->second;
	}
}