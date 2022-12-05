#include<iostream>
#include<map>
#include<set>
#include<string>
#include <list>

/*
* Exercise 11.11
* Redefine bookstore withou using decltype
*/

using std::cout;
using std::cin;
using std::endl;

/*
* class Sales_data to contain sales of one type of book
*/
class Sales_data {
	friend std::ostream& print(std::ostream& os, const Sales_data& sd);
	friend std::istream& read(std::istream& is, Sales_data& sd);

	//data
	std::string bookNO;
	unsigned units_sold = 0;
	double revenue = 0.0;

public:
	//constructors
	Sales_data(const std::string& s, unsigned us, double price) :
		bookNO(s), units_sold(us), revenue(us* price) {}

	Sales_data() :Sales_data("", 0, 0) {
		cout << "Default" << endl;
	}

	Sales_data(std::string& s) : Sales_data() {
		cout << "String& s" << endl;
	}

	Sales_data(const std::string& s) : Sales_data() {
		cout << "Const string &s" << endl;
	}
	Sales_data(std::istream& is) :Sales_data() {
		read(is, *this);
		cout << "Istream& is" << endl;
	}

	//functions
	std::string isbn() const { return bookNO; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;
};

bool compareIsbn(const Sales_data& lhs, const Sales_data& rhs)
{
	return lhs.isbn() < rhs.isbn();
}

int main() {
	
	std::multiset<Sales_data, bool(*)(const Sales_data& lhs, 
		const Sales_data& rhs)> bookstore(&compareIsbn);

	return 0;
}