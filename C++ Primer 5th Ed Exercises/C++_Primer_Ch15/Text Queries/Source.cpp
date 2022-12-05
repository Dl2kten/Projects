#include "Query.h"

/*
* 15.35, 15.36, 15.39
* Implement the Query and Query_base classes
* Put print statements in constructors and rep
* Implement the Query and Query_base classes with eval
*/

int main() {
	Query q = Query("fiery") & Query("bird") | Query("wind");
	std::cout << "\n\n" << q << std::endl;

	std::ifstream in("Ch15_sample.txt");
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

	return 0;
}