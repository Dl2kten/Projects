#include "Query_result.h"

/*
* Function print prints lines that contain a specific word
* param ostream&, const std::set<sz>&
* return void
*/
std::ostream& print(std::ostream& os, const Query_result& qr) {
	os << qr.searchWord << " occurs " << qr.lines->size() <<
		(qr.lines->size() > 1 ? " times" : " time") << "\n";
	for (const auto& i : *qr.lines)
		os << "(line " << i + 1 << ")" << " " << *(qr.file->begin()+i) 
		<< "\n";
	os << std::endl;
	return os;
}