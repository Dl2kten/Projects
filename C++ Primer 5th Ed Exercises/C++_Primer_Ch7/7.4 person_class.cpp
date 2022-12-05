#include<iostream>

/*
* Exercise 7.4, 7.5
* Write a class named Person, contains name and address, use string
* Provide operations in Person class to return name and address
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

int main() {

	Person p;

	//user prompt
	cout << "Please enter name and address of a person: " << endl;
	cin >> p.name >> p.address;
	cout << p.callName() << ": " << p.callAddress();
	return 0;
}