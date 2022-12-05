#pragma once
#include "Query_base.h"
/*
* Class for query on word to see if its present
*/
class Word_query : public Query_base {
	friend class Query;//query needs access
	Word_query(const std::string& s) : query_word(s) {	}
	
	Query_result eval(const Text_query& t) const override {
		return t.query(query_word);
	}
	std::string rep() const override { 
		std::cout << "Word_query rep" << std::endl;
		return query_word; 
	}

	std::string query_word;
};