#include "QueryResult.h"
#include <iostream>
/*
* Function print prints lines that contain a specific word
* param ostream&, const std::set<sz>&
* return void
*/
void QueryResult::print(std::ostream& os, const std::set<sz>& sset) {
	os << searchWord << " occurs " << sset.size() <<
		(sset.size() > 1 ? " times" : " time") << "\n";
	for (const auto& i : sset)
		os << "(line " << i + 1 << ")" << " " << data.deref(i) << "\n";
	os << std::endl;
}