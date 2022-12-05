#pragma once
#include <iostream>

/*
* Class DebugDelete acts like a deleter
*/
class DebugDelete {
public:
	DebugDelete(std::ostream& s = std::cerr) : os(s) {}
	template<typename T>
	void operator()(T* p) const {
		os << "deleting pointer" << std::endl;
		delete p;
	}

private:
	std::ostream& os;

};
