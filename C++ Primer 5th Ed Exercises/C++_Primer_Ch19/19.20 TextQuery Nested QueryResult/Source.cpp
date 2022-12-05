#include "TextQuery.h"
#include <iostream>
/*
* Exercise 19.20
* Nest QueryResult class inside TextQuery and rerun program
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
		TextQuery::QueryResult(tq).print(std::cout, tq.query(s));
	}
}


int main() {

	std::ifstream in("Text.txt");
	if (!in) {
		std::cerr << "Could not open file." << std::endl;
		return -1;
	}

	runQueries(in);
	/*
	* Need to define nested class in header or would have to include cpp file,
	* separate implementation, can define member functions from nested in cpp
	*/
	return 0;
}