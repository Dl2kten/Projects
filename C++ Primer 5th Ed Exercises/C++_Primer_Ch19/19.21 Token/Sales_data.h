#pragma once
#include <iostream>
/*
* class Sales_data to contain sales of one type of book
*/
class Sales_data {
	friend std::ostream& operator<<(std::ostream& os, const Sales_data& sd);
	friend std::istream& operator>>(std::istream& is, Sales_data& sd);
	friend bool operator==(const Sales_data& lhs, const Sales_data& rhs);

public:
	//constructors
	Sales_data() : bookNO(""), units_sold(0), revenue(0.0) {}
	Sales_data(const std::string& s) : bookNO(s) {}
	Sales_data(const std::string& s, unsigned us, double price) :
		bookNO(s), units_sold(us), revenue(us* price) {}
	Sales_data(std::istream& is) {//7.12
		operator>>(is, *this);
	}

	Sales_data& operator+=(const Sales_data&);
	Sales_data& operator=(const std::string&);
	//functions
	std::string isbn() const { return bookNO; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;

private:
	//data
	std::string bookNO;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

std::ostream& operator<<(std::ostream& os, const Sales_data& sd);
std::istream& operator>>(std::istream& is, Sales_data& sd);
bool operator==(const Sales_data& lhs, const Sales_data& rhs);