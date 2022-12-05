#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
/*
* Exercise 13.54
* Code and see what happens when move-assignment defined but did not 
* change copy and swap
*/



/*
* Class HasPtr has string pointer
*/

class HasPtr {
public:
	friend void swap(HasPtr&, HasPtr&);
	HasPtr(const std::string& s = std::string()) : ps(new std::string(s)),
		i(0) {}
	HasPtr(const HasPtr&);
	HasPtr& operator=(HasPtr);
	//HasPtr& operator=(const HasPtr&);
	HasPtr(HasPtr&&) noexcept;
	HasPtr& operator=(HasPtr&&) noexcept;
	bool operator<(const HasPtr&);
	~HasPtr();
	std::string get_ptr_value() { return *ps; }
	void set_ptr_value(std::string s) { *ps = s; }
private:
	std::string* ps;
	int i;
};

/*
* Copy constructor for HasPtr
*/
HasPtr::HasPtr(const HasPtr& orig) : ps(new std::string(*orig.ps)),
i(orig.i) {
	std::cout << "Copy constructor" << std::endl;
}

/*
* Assigment operator for HasPtr
*/
HasPtr& HasPtr::operator=(HasPtr rhs) {
	std::cout << "Assignment" << std::endl;
	swap(*this, rhs);
	return *this;
}

/*
* Copy-assignment operator for HasPtr
*
HasPtr& HasPtr::operator=(const HasPtr& rhs) {
	std::cout << "Copy-assignment operator" << std::endl;
	auto temp = new std::string(*rhs.ps);
	delete ps;
	ps = temp;
	i = rhs.i;
	return *this;
}*/

/*
* Move constructor for HasPtr
*/
HasPtr::HasPtr(HasPtr&& h) noexcept: ps(h.ps), i(h.i) {
	std::cout << "Move constructor" << std::endl;
	h.ps = nullptr;
}

/*
* Move-assignment operator for HasPtr
*/
HasPtr& HasPtr::operator=(HasPtr&& rhs) noexcept {
	std::cout << "Move-assignment operator" << std::endl;
	if (this != &rhs) {
		delete ps;
		ps = rhs.ps;
		i = rhs.i;
		rhs.ps = nullptr;
	}
	return *this;
}

/*
* Smaller than operator for HasPtr
*/
bool HasPtr::operator<(const HasPtr& rhs) {
	return (*ps < *rhs.ps) ? true : false;
}

/*
* Destructor for HasPtr
*/
HasPtr::~HasPtr() {
	delete ps;
}

/*
* Swap function for HasPtr
*/
inline void swap(HasPtr& lhs, HasPtr& rhs) {
	using std::swap;
	swap(lhs.ps, rhs.ps);//instead of copy, doing ptr swap(?)
	swap(lhs.i, rhs.i);
	std::cout << "swap executed" << std::endl;
}


int main() {

	HasPtr hp1("a"), hp2 = hp1, hp3("b"), hp4("c");
	hp2 = hp3;

	/*
	* Got compiler error when using = std::move, more than one matching
	* =, general assignment ran in hp2 = hp3, 2 copy constructor calls
	*/
	return 0;
}