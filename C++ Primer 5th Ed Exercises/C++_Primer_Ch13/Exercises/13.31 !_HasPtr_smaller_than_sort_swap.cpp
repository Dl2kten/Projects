#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
/*
* Exercise 13.28
* Given classes from text, implement default constructor and necessary
* copy-control members
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
i(orig.i) {}

/*
* Copy-assigment operator for HasPtr
*/
HasPtr& HasPtr::operator=(HasPtr rhs) {
	swap(*this, rhs);
	return *this;
}

/*
* Smaller than operator for HasPtr
*/
bool HasPtr::operator<(const HasPtr& rhs) {
	return *ps < *rhs.ps;
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
	swap(lhs.ps, rhs.ps);//instead of value copy, doing ptr swap(?)
	swap(lhs.i, rhs.i);
	std::cout << "swap executed" << std::endl;
}


int main() {

	HasPtr hp1("Now you see, now you don't"), hp2("kadabra"),
		hp3("boom"), hp4("abra");
	std::vector<HasPtr> hvec{ hp1, hp2, hp3, hp4 };
	//could have initialized with strings hvec{"a", "b"}

	std::cout << "Before sort:\n";
	for (auto& i : hvec) {
		std::cout << i.get_ptr_value() << " ";
	}
	std::cout << std::endl;

	std::sort(hvec.begin(), hvec.end());
	std::cout << "After sort:\n";
	for (auto& i : hvec) {
		std::cout << i.get_ptr_value() << " ";
	}
	std::cout << std::endl;

	/*
	* Capital letter is before lower case, 6 swaps for current order, 
	* 3 swaps even if in correct order(?)
	*/
	return 0;
}