#include <iostream>
#include <vector>
#include <list>

/*
* Exercise 13.22, 13.27
* Write the HasPtr copy constructor and copy-assignment operator for each
* object to have its own copy of the string to which the pointer points
* Define own ref-count version of HasPtr
*/

/*
* Class HasPtr has string pointer
*/
class HasPtr {
public:
	HasPtr(const std::string& s = std::string()) : ps(new std::string(s)),
		i(0), counter(new std::size_t(1)) {}
	HasPtr(const HasPtr& hp) : ps(hp.ps), i(hp.i), counter(hp.counter)
	{
		++* counter;
	}
	HasPtr& operator=(const HasPtr&);
	~HasPtr();
	std::string get_ptr_value() { return *ps; }
	void set_ptr_value(std::string s) { *ps = s; }
	std::size_t get_counter() { return *counter; }
private:
	std::string* ps;
	int i;
	std::size_t *counter;
};

/*
* Copy-assigment operator for HasPtr
*/
HasPtr& HasPtr::operator=(const HasPtr& rhs) {
	++* rhs.counter;
	if (-- * counter == 0) {
		delete ps;
		delete counter;
	}
	ps = rhs.ps;
	i = rhs.i;
	counter = rhs.counter;
	return *this;
}

/*
* Destructor for HasPtr
*/
HasPtr::~HasPtr() {
	if (-- * counter == 0) {
		delete ps;
		delete counter;
	}
}


int main() {

	HasPtr hp1("a");
	HasPtr hp2(hp1), hp3;
	hp3 = hp1;

	std::cout << "hp1 string: " << hp1.get_ptr_value() << " counter: "
		<< hp1.get_counter() << "\nhp2 string: " << hp2.get_ptr_value() 
		<< " counter: " << hp2.get_counter() << "\nhp3 string: " 
		<< hp3.get_ptr_value() << " counter: " << hp1.get_counter()
		<< std::endl;

	/*
	* Remember to define destructor
	*/
	return 0;
}