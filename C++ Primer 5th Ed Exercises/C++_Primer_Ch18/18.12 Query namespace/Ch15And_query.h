#pragma once
#include "Ch15Binary_query.h"

namespace Ch15 {
	/*
* Class And_query applies And to two queries
*/
	class And_query : public Binary_query {
		friend Query operator&(const Query&, const Query&);
		And_query(const Query& left, const Query& right) : Binary_query(left,
			right, "&") {
			std::cout << "And_query constructor" << std::endl;
		}
		//inherits rep() from Binary_queue
		Query_result eval(const Text_query&) const;
	};

	Query operator&(const Query&, const Query&);
}
