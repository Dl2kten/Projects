#include "Ch15Or_query.h"

namespace Ch15 {
	Query_result Or_query::eval(const Text_query& text) const {
		auto left = lhs.eval(text),
			right = rhs.eval(text);
		auto return_lines = std::make_shared
			<std::set<line_no>>(left.begin(), left.end());
		return_lines->insert(right.begin(), right.end());
		return Query_result(rep(), return_lines, left.get_file());
	}

	Query operator|(const Query& lhs, const Query& rhs) {
		return std::shared_ptr<Query_base>(new Or_query(lhs, rhs));
	}
}
