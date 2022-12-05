#include <iostream>

/*
* Exercise 13.5
* Use the sketch of a class from text, write a copy constructor, the 
* constructor should dynamically allocate a new string and copy the
* object to which ps points rather than copying ps itself
*/

/*
* class hasPtr has a string ptr
*/
class HasPtr {
public:
	HasPtr(const std::string& s = std::string()) : ps(new std::string(s)),
		i(0) {}
	HasPtr(const HasPtr&);
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

int main() {

	HasPtr hp1("a");
	HasPtr hp2 = hp1;

	hp1.set_ptr_value("abra");
	hp2.set_ptr_value("kadabra");

	std::cout << "hp1's data member string ptr contains value: "
		<< hp1.get_ptr_value() << "\nhp2's data member string ptr "
		"contains value : " << hp2.get_ptr_value() << std::endl;


	return 0;
}