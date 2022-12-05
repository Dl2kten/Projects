#include <iostream>

/*
* Exercise 15.2
* Define own version of Quote class and print_total function
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

void print_total(std::ostream& os, const Quote& item, std::size_t n) {
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: "
		<< ret << std::endl;
}

int main() {

	Quote q("999", 5.99);
	print_total(std::cout, q, 10);


	return 0;
}