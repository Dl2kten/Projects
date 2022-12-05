#include "Query.h"
#include "And_query.h"
#include "Not_query.h"

/*
* Exercise 19.6, 19.7, 19.8
* Write an expression to dynamically cast a pointer to a Query_base to a pointer
* to an And_Query, test the cast by using objects of And_Query and of another
* query type, print a statment indicating whether the cast works and be sure
* that the output mathces your expectations
* Write the same test but cast a Query_base object to a reference to And_Query,
* repeat test to ensure that cast works correctly
* Write a typeid expression to see whether two Query_base pointers point
* to same type, now check whether that type is an And_Query
*/

int main() {
	Query q = Query("fiery") & Query("bird") | Query("wind");
	std::cout << "\n\n" << q << std::endl;

	std::ifstream in("Ch19_sample.txt");
	if (!in) {
		std::cerr << "Could not open file" << std::endl;
		return -1;
	}
	Text_query tq(in);
	Query_result query_result = q.eval(tq);
	print(std::cout, query_result);
	q = ~Query("Alice");
	query_result = q.eval(tq);
	print(std::cout, query_result);

	//19.6
	Query_base* qb = new And_query(Query("fiery"), Query("bird"));
	if (And_query* aq = dynamic_cast<And_query*>(qb)) {
		std::cout << "Success" << std::endl;
		query_result = aq->eval(tq);
		print(std::cout, query_result);
		q = Query("hair") | Query("bird");
		query_result = q.eval(tq);
		print(std::cout, query_result);

	}
	else {
		std::cout << "Fail" << std::endl;
	}

	//19.7
	std::cout << "------------------19.7-----------------" << std::endl;
	try {
		const And_query& aq = dynamic_cast<const And_query&>(*qb);
		std::cout << "Success" << std::endl;
		query_result = aq.eval(tq);
		print(std::cout, query_result);
		q = Query("hair") | Query("bird");
		query_result = q.eval(tq);
		print(std::cout, query_result);
	}
	catch (std::bad_cast e) {
		std::cerr << e.what() << std::endl;
	}

	//19.8
	std::cout << "------------------19.8-----------------" << std::endl;
	Query_base* qb2 = new Not_query(Query("Emma"));
	if (typeid(*qb2) == typeid(*qb)) {
		std::cout << "Same type" << std::endl;
	}
	else {
		std::cout << "not same type" << std::endl;
	}

	if (typeid(*qb) == typeid(And_query)) {
		std::cout << "Same type" << std::endl;
	}
	else {
		std::cout << "not same type" << std::endl;
	}
	return 0;
}