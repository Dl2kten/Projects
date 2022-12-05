#include "S_ptr.h"
#include "U_ptr.h"
#include <vector>

/*
* Exercise 16.28
* Write own version of shared_ptr and unique_ptr
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

	S_ptr<int> s1, s2(new int(2)), s3(s2), s4 = new int(0),
		s5(std::move(s1));
	s4 = std::move(s5);
	S_ptr<std::string> ss1{ new std::string("Hi") },
		ss2{new std::string("Hello")};
	S_ptr<std::vector<int>> sv1 = new std::vector<int>();
	sv1->push_back(10);
	std::cout << *s2 << std::endl;
	std::cout << s2.one() << std::endl;
	std::cout << ss1->size() << std::endl;
	std::cout << s3.u_count() << std::endl;
	int* p_int = s3.get();
	std::cout << *p_int << std::endl;
	swap(ss1, ss2);
	std::cout << *ss1 << std::endl;
	std::cout << *ss2 << std::endl;
	ss1.swap(ss2);
	std::cout << *ss1 << std::endl;
	std::cout << *ss2 << std::endl;

	return 0;
}