#include <iostream>
#include "Ch12TextQuery.h"
#include "Ch12QueryResult.h"
#include "Ch15Query.h"
#include "Ch15Text_query.h"
#include "Ch15Not_query.h"

/*
* Exercise 18.12
* Organize programs written into their own namespace based on chapter, 
* namespace chapter15 would contain code for the Query programs and chapter10
* would contain TextQuery code, compile the Query code examples
* (I don't have any in chapter 10 did I accidentally not save it?)
*/


/*
* Function void runQueries, checks the text file for specific words
* param std::ifstream&
* return void
*/
void runQueries(std::ifstream& infile) {
	Ch12::TextQuery tq(infile);

	while (true) {
		std::cout << "Enter the word you wish to search or enter q"
			" to quit: " << std::endl;
		std::string s;
		if (!(std::cin >> s) || s == "q") break;
		Ch12::QueryResult(tq).print(std::cout, tq.query(s));
	}
}


int main() {

	std::ifstream in("Text.txt");
	if (!in) {
		std::cerr << "Could not open file." << std::endl;
		return -1;
	}

	runQueries(in);

	//Ch15
	Ch15::Query q = Ch15::Query("fiery") & Ch15::Query("bird") | 
		Ch15::Query("wind");
	std::cout << "\n\n" << q << std::endl;

	std::ifstream in2("Ch15_sample.txt");
	if (!in2) {
		std::cerr << "Could not open file" << std::endl;
		return -1;
	}
	Ch15::Text_query tq(in2);
	Ch15::Query_result query_result = q.eval(tq);
	print(std::cout, query_result);
	q = ~Ch15::Query("Alice");
	query_result = q.eval(tq);
	print(std::cout, query_result);
	return 0;
}