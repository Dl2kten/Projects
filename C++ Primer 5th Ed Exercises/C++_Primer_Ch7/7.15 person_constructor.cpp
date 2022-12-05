#include<iostream>

/*
* Exercise 7.15
* Add appropriate constructors to Person class
*/

using namespace std;

/*
* Data structure for Person
*/
struct Person {
	//constructor
	Person() = default;
	Person(const string& sName, const string& sAddress) : name(sName),
		address(sAddress) {}

	//data
	string name;
	string address;

	//functions
	string callName() const { return name; }
	string callAddress() const { return address; }
};

/*
* Function reads name and address into Person
*/
istream& read(istream& is, Person& p) {
	is >> p.name >> p.address;
	return is;
}

/*
* Function prints out name and address from Person
*/
ostream& print(ostream& os, const Person& p) {
	//limit formatting
	os << p.name << " " << p.address;

	//is it better to call the functions instead?
	return os;
}


int main() {

	Person p1;
	Person p2("Abel", "10MarineDr");

	cout << p1.callName() << " " << p1.callAddress() << endl;
	cout << p2.callName() << " " << p2.callAddress() << endl;

	/*
	* I only put in two constructors because the default one is to take
	* in name and address while the second constructor is meant to
	* construct a Person whose name and address already known
	*/

	return 0;
}