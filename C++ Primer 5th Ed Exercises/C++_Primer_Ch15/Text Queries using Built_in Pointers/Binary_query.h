#pragma once
#include "Query_base.h"
#include "Query.h"

/*
* Class Binary_query acts as abstract class for queries that take two
* operands
*/
class Binary_query: public Query_base {
protected:
	Binary_query(const Query& l, const Query& r, std::string s) : 
		lhs(l), rhs(r), op_Symbol(s) {
		std::cout << "Binary_query constructor" << std::endl;
	}
	std::string rep() const {
		std::cout << "Binary_query rep()" + op_Symbol << std::endl;
		return "(" + lhs.rep() + " " + op_Symbol
			+ " " + rhs.rep() + ")";
	}

	Query lhs, rhs;
	std::string op_Symbol;

};