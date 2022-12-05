#pragma once
#include <string>
#include <iostream>
#include "Text_query.h"
#include "Query_result.h"

/*
* Abstract base class
*/
class Query_base {
	friend class Query;
public:
	Query_base() {
	}
	using line_no = Text_query::sz; //for eval function
	virtual ~Query_base() = default;
private:
	virtual Query_result eval(const Text_query&) const = 0;
	virtual std::string rep() const = 0;
};
