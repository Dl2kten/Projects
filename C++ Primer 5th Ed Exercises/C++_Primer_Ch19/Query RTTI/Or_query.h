#pragma once
#include "Binary_query.h"

/*
* Class Or_query applies Or to two queries
*/
class Or_query : public Binary_query {
	friend Query operator|(const Query&, const Query&);
	Or_query(const Query& left, const Query& right) : Binary_query(left,
		right, "|") {	}
	
	Query_result eval(const Text_query&) const;
};

Query operator|(const Query& lhs, const Query& rhs);