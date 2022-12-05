#pragma once
#include <string>
#include <iostream>
#include "Ch15Text_query.h"
#include "Ch15Query_result.h"

namespace Ch15 {
	/*
* Abstract base class
*/
	class Query_base {
		friend class Query;
	protected:
		Query_base() {
			std::cout << "Query_base constructor" << std::endl;
		}
		using line_no = Text_query::sz; //for eval function
		virtual ~Query_base() = default;
	private:
		virtual Query_result eval(const Text_query&) const = 0;
		virtual std::string rep() const = 0;
	};
}

