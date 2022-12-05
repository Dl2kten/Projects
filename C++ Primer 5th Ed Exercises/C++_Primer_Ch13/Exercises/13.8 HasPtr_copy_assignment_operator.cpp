#include <iostream>

/*
* Exercise 13.8
* Write the copy-assignment operator for the HasPtr class, as with the
* copy constructor the operator should copy the
* object to which ps points rather than copying ps itself
*/

class HasPtr {
public:
	HasPtr(const std::string& s = std::string()) : ps(new std::string(s)),
		i(0) {}
	HasPtr(const HasPtr&);
	HasPtr& operator=(const HasPtr&);
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
HasPtr& HasPtr::operator=(const HasPtr& rhs) {
	auto newps = new std::string(*rhs.ps);//case for 
	//assigning to itself

	delete ps;//need to delete if use = more than once, second time would
	//create a new ps in dynamic memory but old one still exists
	ps = newps;//this way if assigning to self it would not be trying
	//to string(nullptr), newps gets deleted at end of function, no 
	//dangling either
	i = rhs.i;
	return *this;
}


int main() {

	HasPtr hp1("a");
	HasPtr hp2 = hp1;
	HasPtr hp3("b");

	hp1.set_ptr_value("abra");
	hp2.set_ptr_value("kadabra");
	hp3 = hp1;
	std::cout << "hp3's data member string ptr contains value: "
		<< hp3.get_ptr_value() << "\n";
	hp3.set_ptr_value("kazam");

	std::cout << "hp1's data member string ptr contains value: "
		<< hp1.get_ptr_value() << "\nhp2's data member string ptr "
		"contains value : " << hp2.get_ptr_value() 
		<< "\nhp2'3 data member string ptr "
		"contains value : " << hp3.get_ptr_value() << std::endl;


	return 0;
}