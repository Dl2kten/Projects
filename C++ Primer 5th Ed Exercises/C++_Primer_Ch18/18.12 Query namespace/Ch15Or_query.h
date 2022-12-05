#pragma once
#include "Ch15Binary_query.h"

namespace Ch15 {
	/*
	* Class Or_query applies Or to two queries
	*/
	class Or_query : public Binary_query {
		friend Query operator|(const Query&, const Query&);
		Or_query(const Query& left, const Query& right) : Binary_query(left,
			right, "|") {
			std::cout << "Or_query constructor" << std::endl;
		}

		Query_result eval(const Text_query&) const;
	};

	Query operator|(const Query& lhs, const Query& rhs);
}
