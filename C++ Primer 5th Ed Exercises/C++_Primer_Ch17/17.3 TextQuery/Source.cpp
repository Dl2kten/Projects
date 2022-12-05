#include "TextQuery.h"
#include <iostream>
#include <tuple>
/*
* Exercise 17.3
* Rewrite TextQuery program(12.3) to use a tuple instead of the
* QueryResult class
*/

using sz = std::vector<std::string>::size_type;
using tuple_result = std::tuple<const std::string&,
	std::shared_ptr<std::set<sz>>,
	std::shared_ptr<std::vector<std::string>>>;
/*
* Function print prints lines that contain a specific word
* param ostream&, const std::set<sz>&
* return void
*/
std::ostream& print(std::ostream& os, const tuple_result& tr) {
	os << std::get<0>(tr) << " occurs " 
		<< std::get<1>(tr)->size() <<
		(std::get<1>(tr)->size() > 1 ? " times" : " time") << "\n";
	for (const auto& i : *std::get<1>(tr))
		os << "(line " << i + 1 << ")" << " " 
		<< (*std::get<2>(tr))[i] << "\n";
	os << std::endl;
	return os;
}

/*
* Function void runQueries, checks the text file for specific words
* param std::ifstream&
* return void
*/
void runQueries(std::ifstream& infile) {
	Text_query tq(infile);
	
	while (true) {
		std::cout << "Enter the word you wish to search or enter q"
			" to quit: " << std::endl;
		std::string s;
		if (!(std::cin >> s) || s == "q") break;
		auto query_result = tq.query(s);
		print(std::cout, query_result);
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
	* Using QueryResult class is better, the print function is a member
	* so better encapsulation and it's more clear than using all the
	* std::get for all the tuple members, tuple also hard to write
	*/
	return 0;
}