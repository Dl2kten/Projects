#pragma once
#include "Query_base.h"
#include "Query.h"

/*
* Class Not_query, applies not operator to word search
*/
class Not_query : public Query_base {
	friend Query operator~(const Query&);
	Not_query(const Query& q) : query(q) {
		std::cout << "Not_query constructor" << std::endl;
	}
	
	Query_result eval(const Text_query&) const;
	std::string rep() const { 
		std::cout << "Not_query rep" << std::endl;
		return "~(" + query.rep() + ")"; }

	Query query;
};

Query operator~(const Query& operand);