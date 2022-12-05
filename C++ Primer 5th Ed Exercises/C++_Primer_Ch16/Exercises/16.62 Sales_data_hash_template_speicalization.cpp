#include <iostream>
#include <string>
#include <memory>
#include <unordered_set>
/*
* Exercise 16.62
* Define own version of hash<Sales_data> and defined unorderd_multiset
* of Sales_data objects, put several transactions into container and print
* its contents
*/

template<typename T> struct std::hash;

/*
* class Sales_data to contain sales of one type of book
*/
class Sales_data {
public:
	friend struct std::hash<Sales_data>;
	friend std::ostream& operator<<(std::ostream&, const Sales_data&);
	friend std::istream& operator>>(std::istream&, Sales_data&);
	friend bool operator==(const Sales_data& lhs, const Sales_data& rhs);

	//constructors
	Sales_data(const std::string& s, unsigned us, double price) :
		bookNO(s), units_sold(us), revenue(us* price) {
	}

	Sales_data() :Sales_data("", 0, 0) {
	}

	Sales_data(std::string& s) : Sales_data() {
	}

	Sales_data(const std::string& s) : Sales_data() {
	}

	Sales_data(std::istream& is) :Sales_data() {
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

/*
* Function avg_price
*/
inline double Sales_data::avg_price() const {//7.26
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}

/*
* Define function combine from class Sales_data
*/
Sales_data& Sales_data::combine(const Sales_data& rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;

	return *this;
}

/*
* Function add takes two Sales_data objects and return their sum
*/
Sales_data add(const Sales_data& lhs, const Sales_data& rhs) {
	Sales_data temp = lhs;
	temp.combine(rhs);

	return temp;
}

/*
* Output operator << for Sales_data
*/
std::ostream& operator<<(std::ostream& os, const Sales_data& sd) {
	os << sd.isbn() << " " << sd.units_sold << " " << sd.revenue
		<< " " << sd.avg_price();
	return os;
}

/*
* Input operator >> for Sales_data
*/
std::istream& operator>>(std::istream& is, Sales_data& sd) {
	double price;
	is >> sd.bookNO >> sd.units_sold >> price;
	if (is)
		sd.revenue = sd.units_sold * price;
	else
		sd = Sales_data();
	return is;
}

/*
* Operator += for Sales_data
*/
Sales_data& Sales_data::operator+=(const Sales_data& sd) {
	units_sold = sd.units_sold;
	revenue += sd.revenue;
	return *this;
}

/*
* Operator + for Sales_data
*/
Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs) {
	Sales_data temp = rhs;
	temp += lhs;
	return temp;
}

/*
* Assignment operator for Sales_data that takes string
*/
Sales_data& Sales_data::operator=(const std::string& s) {
	bookNO = s;
	return *this;
}

/*
* Operator == for Sales_data
*/
bool operator==(const Sales_data& lhs, const Sales_data& rhs) {
	return lhs.bookNO == rhs.bookNO && lhs.units_sold == rhs.units_sold
		&& lhs.revenue == rhs.revenue;
}

/*
* Operator != for Sales_data
*/
bool operator!=(const Sales_data& lhs, const Sales_data& rhs) {
	return !(lhs == rhs);
}

namespace std {
	template<>
	struct hash<Sales_data> {
		typedef size_t result_type;
		typedef Sales_data argument_type;
		size_t operator()(const Sales_data& s) const;
	};

	size_t hash<Sales_data>::operator()(const Sales_data& s) const {
		return hash<string>()(s.bookNO) ^ hash<unsigned>()(s.units_sold)
			^ hash<double>()(s.revenue);
	}
}

int main() {
	Sales_data sd1, sd2, sd3("999", 10, 10.99), sd4("998", 100, 2.99);
	std::unordered_multiset<Sales_data> sdu{ sd1, sd2, sd3, sd4 };
	for (const auto& i : sdu)
		std::cout << i << std::endl;
	
	return 0;
}