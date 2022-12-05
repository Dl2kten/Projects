#pragma once
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
class Text_query {
public:
	using sz = std::vector<std::string>::size_type;
	using tuple_result = std::tuple<const std::string&,
		std::shared_ptr<std::set<sz>>,
		std::shared_ptr<std::vector<std::string>>>;
	friend class Query_result;
	Text_query() {}
	Text_query(std::ifstream& i);
	tuple_result query(const std::string&) const;

private:
	std::shared_ptr<std::vector<std::string>> file;
	std::map<std::string, std::shared_ptr<std::set<sz>>> data;
};
