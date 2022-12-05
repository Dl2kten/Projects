#include<iostream>

/*
* Exercise 7.21
* Update Sales_data class to hide implementation
*/

using namespace std;

/*
* Class for Person
* Data, name, address
*/
class Person {
	friend istream& read(istream& is, Person& p);
	friend ostream& print(ostream& os, const Person& p);

	//data
	string name;
	string address;

public:
	//constructor
	Person() = default;
	Person(const string& sName, const string& sAddress) : name(sName),
		address(sAddress) {}

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

	Person p;

	read(cin, p);
	print(cout, p);

	return 0;
}