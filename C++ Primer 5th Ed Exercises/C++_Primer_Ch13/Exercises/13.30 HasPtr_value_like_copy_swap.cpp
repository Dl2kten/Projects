#include <iostream>
#include <vector>
#include <list>

/*
* Exercise 13.30
* Write and test swap function for value like version of HasPtr, give
* swap a print statement that notes when it is executed
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
i(orig.i) {}

/*
* Copy-assigment operator for HasPtr
*/
HasPtr& HasPtr::operator=(HasPtr rhs) {
	swap(*this, rhs);
	return *this;
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

	HasPtr hp4("b"), hp5("c"), hp6("d");
	std::cout << "hp4 string: " << hp4.get_ptr_value() << " hp5 string: " 
		<< hp5.get_ptr_value() << " hp6 string: "
		<< hp6.get_ptr_value() << std::endl;

	swap(hp4, hp5);
	hp6 = hp5;
	std::cout << "After swap:\nhp4 string: " << hp4.get_ptr_value() 
		<< " hp5 string: " << hp5.get_ptr_value() << " hp6 string: "
		<< hp6.get_ptr_value() << std::endl;

	return 0;
}