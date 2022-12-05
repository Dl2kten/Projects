#include <iostream>

/*
* Exercise 15.5, 15.6
* Define own version of the Bulk_quote class
* Test print_total function from the 15.2 by passing both Quote and
* Bulk_quote objects to that function
*/

class Quote {
public:
	Quote() = default;
	Quote(const std::string& book, double sales_price) : bookNo(book),
		price(sales_price) {}
	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const { return n * price; }
	virtual ~Quote() = default;

private:
	std::string bookNo;

protected:
	double price = 0.0;
};

class Bulk_quote : public Quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string& book, double price, std::size_t qty,
		double disc) : Quote(book, price), min_qty(qty), discount(disc)
	{}

	double net_price(std::size_t) const override;

private:
	std::size_t min_qty = 0;
	double discount = 0.0;
};

double Bulk_quote::net_price(std::size_t cnt) const {
	if (cnt >= min_qty)
		return cnt * (1 - discount) * price;
	else
		return cnt * price;
}

void print_total(std::ostream& os, const Quote& item, std::size_t n) {
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: "
		<< ret << std::endl;
}

int main() {

	Quote q("999", 5.99);
	Bulk_quote bq("998", 9.99, 20, 0.1);

	print_total(std::cout, q, 10);
	print_total(std::cout, bq, 25);
	
	return 0;
}