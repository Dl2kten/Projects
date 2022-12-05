#include "TextQuery.h"
#include "QueryResult.h"
#include <iostream>
/*
* Exercise 16.22
* Override deleter for shared_ptr data members with DebugDelete
*/


/*
* Function void runQueries, checks the text file for specific words
* param std::ifstream&
* return void
*/
void runQueries(std::ifstream& infile) {
	TextQuery tq(infile);
	
	while (true) {
		std::cout << "Enter the word you wish to search or enter q"
			" to quit: " << std::endl;
		std::string s;
		if (!(std::cin >> s) || s == "q") break;
		QueryResult(tq).print(std::cout, tq.query(s));
	}
}


int main() {

	std::ifstream in("Text.txt");
	if (!in) {
		std::cerr << "Could not open file." << std::endl;
		return -1;
	}

	runQueries(in);

	return 0;
}