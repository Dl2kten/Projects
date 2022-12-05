#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<functional>
#include<fstream>
#include "Sales_item.h"

/*
* Exercise 10.32
* Rewrite bookstore program, use a vector to hold the transactions
* and various algorithms to do the processing, use sort with
* compareIsbn function, use find and accumulate to do the sum
*/

using std::cout;
using std::cin;
using std::endl;


/*
* Function compareIsbn, compares isbn of two Sales_data objects
* param two const Sales_data&
* return bool
*/
bool myCompareIsbn(const Sales_item& si1, const Sales_item& si2) {
	return si1.isbn() < si2.isbn();
}


/*
* Function print, prints contents of vector
* param ostream&, vector
* return void
*/
void print(std::ostream& os, const std::vector<Sales_item>& vec) {
	for (const auto& i : vec)
		os << i << "\n";
	os << endl;
}


/*
* Function modifyFind, change find to check for isbns as Sales_item is
* class type, need to use strings for find
* param vector<Sales_item>
* return iterator
*/
bool modifyFind(const std::vector<Sales_item>& salesV, 
	const std::string& isbn) {
	std::vector<std::string> svec;
	for (const auto& i : salesV) {
		svec.push_back(i.isbn());
	}

	auto iter = 
		std::find(svec.begin(), svec.end(), isbn);

	return (iter != svec.end()) ? true : false;
}


int main() {

	std::ifstream infile("Sales_item.txt");

	if (!infile) {
		std::cerr << "File could not be opened" << endl;
		return -1;
	}

	std::istream_iterator<Sales_item> item_iter(infile), eof;
	std::ostream_iterator<Sales_item> out_iter(cout, "\n");
	std::vector<Sales_item> sivec{item_iter, eof};
	
	print(cout, sivec);
	std::sort(sivec.begin(), sivec.end(), myCompareIsbn);
	auto iter = sivec.begin();
	print(cout, sivec);

	while (iter < sivec.end()) {
		//get current iterator and increment
		auto sum = *iter++;

		//use find starting on next element
		std::vector<Sales_item> sv(iter, sivec.end());

		//if more than one found
		if (modifyFind(sv, sum.isbn())) {
			auto curr = iter;
			//need to make sure don't try to access end
			while (iter < sivec.end() && iter->isbn() == sum.isbn()) {
				++iter;
			}
			out_iter = std::accumulate(curr, iter, sum);
		}
		else {
			out_iter = sum;
		}
	}

	/*
	* Did the question include find_if algorithm as the general find 
	* category, if so would've been faster to finish
	*/

	return 0;
}