#include "Not_query.h"

Query_result Not_query::eval(const Text_query& text) const {
	auto result = query.eval(text);
	auto return_lines = std::make_shared<
		std::set<line_no>>();
	auto beg = result.begin(), 
		end = result.end();
	auto sz = result.get_file()->size();
	for (std::size_t n = 0; n != sz; ++n) {
		if (beg == end || *beg != n)
			return_lines->insert(n);
		else if (beg != end)
			++beg;
	}
	return Query_result(rep(), return_lines, result.get_file());

}

Query operator~(const Query& operand) {
	return std::shared_ptr<Query_base>(new Not_query(operand));
}