#include <iostream>

/*
* Exercise 16.21
* Write own version of DebugDelete
*/

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


int main() {
	std::string* s = new std::string();
	DebugDelete d;
	d(s);

	return 0;
}