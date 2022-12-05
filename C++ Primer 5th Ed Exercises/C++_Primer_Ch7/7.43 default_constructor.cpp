#include<iostream>
#include<vector>

/*
* Exercise 7.43, 7.44
* Class named NoDefault with a constructor that takes int but no default
* constructor, define a class C with member NoDefault, define default
* constructor for NoDefault
* Is vector legal
*/

using namespace std;

/*
* Class NoDefault
*/
class NoDefault {

public:
	NoDefault(int) {}
	NoDefault() = default;

};

/*
* Class C
*/
class C {
	NoDefault nd;
};

int main() {

	/*
	* Program compiles if not trying to declare a class C object when
	* class NoDefault doesn't have a default constructor.  Once class
	* NoDefault does have a default constructor, we can have a class C
	* object
	*/
	C c;

	/*
	* 7.44 Legal once we define default constructor
	*/
	vector<NoDefault> vec(10);
	vector<C> vc(10);

	return 0;
}