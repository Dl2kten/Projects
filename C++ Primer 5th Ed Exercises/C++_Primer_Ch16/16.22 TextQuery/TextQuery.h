#pragma once
#include "StrBlob.h"
#include "DebugDelete.h"
#include <fstream>
#include <vector>
#include <memory>
#include <string>
#include <set>
#include <map>

class QueryResult;
/*
* class TextQuery stores and organizes input text file for queries into
* whether a particular word is present and how many times it's present
*/
class TextQuery {
public:
	using sz = std::vector<std::string>::size_type;
	friend class QueryResult;
	TextQuery() {}
	TextQuery(std::ifstream& i) :text_map(
		new std::map<std::string, std::set<sz>>(), DebugDelete()) 
		{ parseText(i); }
	std::set<sz>& query(const std::string&) const;
	

private:
	void parseText(std::ifstream& in);
	mutable std::string wordSought;
	//std::shared_ptr<std::vector<std::string>> text;
	StrBlob text;
	std::shared_ptr<std::map<std::string, std::set<sz>>> text_map;
};
