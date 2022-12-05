#include <iostream>
#include <string>

/*
* Exercise 18.21
* Explain the following declarations, identify any that are in error and
* explain why
*/
class CAD {};
class Vehicle {};
class List {};
class CADVehicle : public CAD, Vehicle { };
class istream {};
class ostream {};
//class DblList : public List, public List { };//error an inherited class may
//appear only once in derivation list
class iostream : public istream, public ostream {}; //unless intends to inherit
//from std library members then need to open namespace, and there's already
//an iostream header, complications?

int main() {
	


	return 0;
}