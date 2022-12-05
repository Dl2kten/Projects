#pragma once
#include "Binary_query.h"

/*
* Class And_query applies And to two queries
*/
class And_query : public Binary_query {
	friend Query operator&(const Query&, const Query&);
public:
	And_query(const Query& left, const Query& right): Binary_query(left,
		right, "&") {
	}
	//inherits rep() from Binary_queue
	Query_result eval(const Text_query&) const;
};

Query operator&(const Query&, const Query&);