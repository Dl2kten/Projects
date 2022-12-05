#pragma once
#include "Text_query.h"
#include <iostream>
/*
* Class QueryResult prints contents of TextQuery
*/
class Query_result {
public:
	using sz = std::vector<std::string>::size_type;
	using set_iter = std::set<sz>::const_iterator;
	friend std::ostream& print(std::ostream&, const Query_result&);
	Query_result(std::string sought, std::shared_ptr<std::set<sz>> p,
		std::shared_ptr<std::vector<std::string>> f) : searchWord(sought),
		lines(p), file(f) {}
	set_iter begin() const { return lines->cbegin(); }
	set_iter end() const { return lines->cend(); }
	std::shared_ptr<std::vector<std::string>> get_file() { return file; }
	
private:
	std::string searchWord;
	std::shared_ptr<std::set<sz>> lines;
	std::shared_ptr<std::vector<std::string>> file;


};

std::ostream& print(std::ostream&, const Query_result&);