#pragma once
#include "Ch15Query_base.h"
#include "Ch15Word_query.h"

#include <memory>
#include <iostream>
#include <string>

namespace Ch15 {
	/*
* Interface to user
*/
	class Query {
		friend Query operator~(const Query&);
		friend Query operator&(const Query&, const Query&);
		friend Query operator|(const Query&, const Query&);

	public:
		Query(const std::string&);
		Query_result eval(const Text_query& t) const { return q->eval(t); }
		std::string rep() const {
			std::cout << "Query rep" << std::endl;
			return q->rep();
		}

	private:
		Query(std::shared_ptr<Query_base> query) : q(query) {}
		std::shared_ptr<Query_base> q;
	};

	inline std::ostream& operator<<(std::ostream& os, const Query& query) {
		return os << query.rep();
	}
}

