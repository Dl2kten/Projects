#include "Query.h"
#include "Word_query.h"


Query::Query(const std::string& s) : q(new Word_query(s)) {
	std::cout << "Query constructor" << std::endl;
}