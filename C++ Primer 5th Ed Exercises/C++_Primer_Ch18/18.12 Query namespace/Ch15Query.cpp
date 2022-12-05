#include "Ch15Query.h"
#include "Ch15Word_query.h"

namespace Ch15 {
	Query::Query(const std::string& s) : q(new Word_query(s)) {
		std::cout << "Query constructor" << std::endl;
	}
}
