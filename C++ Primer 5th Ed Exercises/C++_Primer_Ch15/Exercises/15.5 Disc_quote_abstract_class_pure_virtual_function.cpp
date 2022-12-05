#include <iostream>

/*
* Exercise 15.15, 15.16, 15.17
* Define own version of Disc_quote and Bulk_quote
* Rewrite Limit_quote to inherit from Disc_quote
* See errors when trying to define obj of Disc_quote
*/

class Quote {
public:
	Quote() = default;
	Quote(const std::string& book, double sales_price) : bookNo(book),
		price(sales_price) {}
	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const { return n * price; }
	virtual std::ostream& debug(std::ostream& os) const {
		os << "Data members are string bookNo: " << bookNo 
			<< " and double price: " << price << std::endl;
		return os;
	}
	virtual ~Quote() = default;

private:
	std::string bookNo;

protected:
	double price = 0.0;
};

class Disc_quote : public Quote {
public:
	Disc_quote() = default;
	Disc_quote(const std::string& book, double price, std::size_t qty,
		double disc) : Quote(book, price), quantity(qty), discount(disc)
	{}

	double net_price(std::size_t) const = 0;
protected:
	std::size_t quantity = 0;
	double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string& book, double price, std::size_t qty,
		double disc) : Disc_quote(book, price, qty, disc) {}

	double net_price(std::size_t) const override;
	std::ostream& debug(std::ostream& os) const override;
};

double Bulk_quote::net_price(std::size_t cnt) const {
	if (cnt >= quantity)
		return cnt * (1 - discount) * price;
	else
		return cnt * price;
}

std::ostream& Bulk_quote::debug(std::ostream& os) const {
	os << "Data members are string bookNo: " << isbn()
		<< " double price: " << price << " min_qty: " << quantity
		<< " and discount: " << discount << std::endl;
	return os;
}

class Limit_quote : public Disc_quote {
public:
	Limit_quote() = default;
	Limit_quote(const std::string& book, double price, std::size_t qty,
		double disc) : Disc_quote(book, price, qty, disc) {}

	double net_price(std::size_t cnt) const override;
	std::ostream& debug(std::ostream& os) const override;
private:
	std::size_t max_qty = 0;
	double discount = 0.0;
};

double Limit_quote::net_price(std::size_t cnt) const {
	if (cnt <= quantity)
		return cnt * (1 - discount) * price;
	else
		return cnt * price;
}

std::ostream& Limit_quote::debug(std::ostream& os) const {
	os << "Data members are string bookNo: " << isbn()
		<< " double price: " << price << " max_qty: " << quantity
		<< " and discount: " << discount << std::endl;
	return os;
}

void print_total(std::ostream& os, const Quote& item, std::size_t n) {
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: "
		<< ret << std::endl;
}


int main() {

	Quote q("999", 5.99);
	Bulk_quote bq("998", 9.99, 20, 0.1);
	Limit_quote lq("997", 2.99, 2, 0.2);
	//Disc_quote dqq; obj of abstract not allowed net_price is pure virtual
	print_total(std::cout, q, 10);
	print_total(std::cout, bq, 25);
	print_total(std::cout, bq, 18);
	print_total(std::cout, lq, 2);
	print_total(std::cout, lq, 4);

	q.debug(std::cout);
	bq.debug(std::cout);
	lq.debug(std::cout);

	
	return 0;
}