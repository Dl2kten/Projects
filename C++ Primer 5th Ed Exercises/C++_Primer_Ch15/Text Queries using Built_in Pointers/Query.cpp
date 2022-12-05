#include "Query.h"
#include "Word_query.h"


Query::Query(const std::string& s) : q(new Word_query(s)),
	counter(new std::size_t(1)) { }

Query::Query(const Query& operand):q(operand.q), 
counter(operand.counter) {
	++* counter;
}

Query Query::operator=(const Query& rhs) {
	++* rhs.counter;
	if (-- * counter == 0) {
		delete q;
		delete counter;
	}
	q = rhs.q;
	counter = rhs.counter;
	return *this;
}

Query::Query(Query&& operand) noexcept : q(std::move(operand.q)),
counter(std::move(operand.counter)) {
}

Query Query::operator=(Query&& rhs) noexcept {
	//++rhs.counter;still assign? needs to increment
	q = std::move(rhs.q);
	counter = std::move(rhs.counter);
	return *this;
}

Query::~Query() {
	if (-- * counter == 0) {
		delete q;
		delete counter;
	}
	
	q = nullptr;
	counter = nullptr;
}

