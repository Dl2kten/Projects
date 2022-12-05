#include <iostream>
#include <string>
#include <vector>

/*
* Exercise 18.26, 18.27
* Given the hierarchy in text code, why is the call to print an error, Revise
* MI to allows this call to print to compile and execute correctly
* Assume added foo ato MI, answer the questions
*/

struct Base1 {
	void print(int) const; // public by default
protected:
	int ival;
	double dval;
	char cval;
private:
	int* id;
};
struct Base2 {
	void print(double) const; // public by default
protected:
	double fval;
private:
	double dval;
};
struct Derived : public Base1 {
	void print(std::string) const; // public by default
protected:
	std::string sval;
	double dval;
};
struct MI : public Derived, public Base2 {
	void print(std::vector<double>) {} // public by default
	void foo(double cval);
protected:
	int* ival;
	std::vector<double> dvec;
};

int ival;
double dval;
void MI::foo(double cval)
{
	int dval;
	dval = Base1::dval + Derived::dval;
	Base2::fval = dvec.back();
	Derived::sval[0] = Base1::cval;

	//ival = 5; pointer hides int ival
	/*
	* (a) List all the names visible from within MI::foo.
	* - local int dval, local double cval, int* ival, std::vector<double> dvec,
	* Derived::sval, Base1::id, Base2::fval
	* (b) Are any names visible from more than one base class?
	* - dval was but declared local version instead
	* (c) Assign to the local instance of dval the sum of the dval
	*	member of Base1 and the dval member of Derived.
	* (d) Assign the value of the last element in MI::dvec to
	*	Base2::fval.
	* (e) Assign cval from Base1 to the first character in sval from
	*	Derived.
	*/
}
int main() {

	MI mi;
	mi.print(std::vector<double>(42));//can't convert from 42 to 
	//std::vector<double>, now ok, make sure to define print

	return 0;
}