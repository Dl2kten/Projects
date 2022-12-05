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
	class QueryResult;
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

/*
* Class QueryResult prints contents of TextQuery
*/
class TextQuery::QueryResult {
public:
	using set_iter = std::set<sz>::iterator;

	QueryResult(TextQuery& a) : searchWord(a.wordSought), data(a.text),
		data_map(a.text_map) {}
	void print(std::ostream& os, const std::set<sz>&);
	set_iter begin();
	set_iter end();
	std::shared_ptr<std::ifstream&> get_file();
	//or to the vector?

private:
	std::string searchWord;
	const StrBlob& data;
	std::shared_ptr < std::map<std::string, std::set<sz>>> data_map;

};
