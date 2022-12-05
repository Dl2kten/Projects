#include "And_query.h"
#include <algorithm>
#include <iterator>

Query_result And_query::eval(const Text_query& text) const {
	auto left = lhs.eval(text), right = rhs.eval(text);
	auto return_lines = 
		std::make_shared<std::set<line_no>>();
	std::set_intersection(left.begin(), left.end(), 
		right.begin(), right.end(), 
		std::inserter(*return_lines, 
			return_lines->begin()));
	return Query_result(rep(), return_lines, left.get_file());

}

Query operator&(const Query& lhs, const Query& rhs) {
	return std::shared_ptr<Query_base>(new And_query(lhs, rhs));
}