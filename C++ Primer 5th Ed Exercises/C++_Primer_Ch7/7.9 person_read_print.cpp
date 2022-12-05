#include<iostream>

/*
* Exercise 7.9
* Add operations read and print Person objects
*/

using namespace std;

/*
* Data structure
*/
struct Person {
	string name;
	string address;
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

	//user prompt
	cout << "Please enter name and address of a person: " << endl;
	read(cin, p);
	print(cout, p);

	return 0;
}