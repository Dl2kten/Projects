#pragma once
#include "Query_base.h"
#include "Text_query.h"
#include "Word_query.h"

#include <memory>
#include <iostream>
#include <string>

/*
* Interface to user
*/
class Query {
	friend Query operator~(const Query&);
	friend Query operator&(const Query&, const Query&);
	friend Query operator|(const Query&, const Query&);
	
public:
	Query(const std::string&);
	Query(const Query&);
	Query operator=(const Query&);
	Query(Query&&) noexcept;
	Query operator=(Query&&) noexcept;
	~Query();

	Query_result eval(const Text_query& t) const {
		return q->eval(t); }
	std::string rep() const { 
		std::cout << "Query rep" << std::endl;
		return q->rep(); }
private:
	Query(Query_base* query) : q(query), counter(new std::size_t(1)) {}
	//std::shared_ptr<Query_base> q;
	Query_base* q;
	std::size_t* counter;

};

inline std::ostream& operator<<(std::ostream& os, const Query& query) {
	return os << query.rep();
}
