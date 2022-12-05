#include "Query.h"

/*
* 15.41, 15.42
* Reimplement class to use built-in pointers rather than shared_ptrs
* Print words once per sentence rather than once per line
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