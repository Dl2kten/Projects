#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

/*
* Exercise 19.19
* Write a function that takes a vector<Sales_data> and finds the first element
* whose average price is greater than some given amount
*/


/*
* Inherits from runtime_error, used to signal that an order cannot be
* fulfilled
*/
class out_of_stock : public std::runtime_error {
public:
	explicit out_of_stock(const std::string& s) : std::runtime_error(s) {}
};

/*
* Inhertis from logic_error, represents isbn mismatched when search/selling
*/
class isbn_mismatch : public std::logic_error {
public:
	explicit isbn_mismatch(const std::string& s) : std::logic_error(s) {}
	isbn_mismatch(const std::string& s, const std::string& rhs,
		const std::string& lhs) : std::logic_error(s), left(lhs), right(rhs) {}
	const std::string left, right;

};


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
	bool greater_avg_price() const;
private:
	//data
	std::string bookNO;
	unsigned units_sold = 0;
	double revenue = 0.0;
	double avg_price_min = 5.00;
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
* Function finds if average price is greater than a given amount
*/
bool Sales_data::greater_avg_price() const
{
	return (((*this).avg_price() > avg_price_min) ? true : false);
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
	if (isbn() != sd.isbn())
		throw isbn_mismatch("wrong isbns", isbn(), sd.isbn());
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

/// <summary>
/// Finds first element whose average price is greater than some given amount
/// </summary>
/// <param name="sdv"></param>
/// <returns></returns>
Sales_data find_Sales_data(std::vector<Sales_data> sdv) {
	//since callable need empty param for function
	const auto ret_elem = std::find_if(sdv.begin(), sdv.end(),
		std::mem_fn(&Sales_data::greater_avg_price));
	return *ret_elem;
}

int main() {
	Sales_data sd1("997", 5, 5), sd2("999", 10, 100), sd3("998", 10, 200);
	std::vector<Sales_data> s_dvec{ sd1, sd2, sd3 };

	std::cout << find_Sales_data(s_dvec) << std::endl;
	return 0;
}