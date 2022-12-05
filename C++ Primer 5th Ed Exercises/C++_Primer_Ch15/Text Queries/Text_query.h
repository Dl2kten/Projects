#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <set>
#include "Query_result.h"

/*
* class TextQuery stores and organizes input text file for queries into
* whether a particular word is present and how many times it's present
*/
class Text_query {
public:
	using sz = std::vector<std::string>::size_type;
	friend class Query_result;
	Text_query() {}
	Text_query(std::ifstream& i);
	Query_result query(const std::string&) const;

private:
	std::shared_ptr<std::vector<std::string>> file;
	std::map<std::string, std::shared_ptr<std::set<sz>>> data;
};