#include <iostream>
#include <vector>
#include <set>
/*
* Exercise 15.30
* Add own version of the Basket class and use it to compute prices for
* transactions from previous exercises
*/


class Quote {
public:
	Quote() { }
	Quote(const std::string& book, double sales_price) : bookNo(book),
		price(sales_price) {	}
	Quote(const Quote& rhs): bookNo(rhs.bookNo), price(rhs.price) {	}
	Quote(Quote&& rhs) noexcept: bookNo(std::move(rhs.bookNo)),
		price(std::move(rhs.price)) { }
	Quote& operator=(const Quote& rhs) {
		bookNo = rhs.bookNo;
		price = rhs.price;
		return *this;
	}
	Quote& operator=(Quote&& rhs) noexcept {
		bookNo = std::move(rhs.bookNo);
		price = std::move(rhs.price);
		return *this;
	}
	virtual ~Quote() { }

	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const { return n * price; }
	virtual std::ostream& debug(std::ostream& os) const {
		os << "Data members are string bookNo: " << bookNo
			<< " and double price: " << price << std::endl;
		return os;
	}
	virtual Quote* clone() const& { return new Quote(*this); }
	virtual Quote* clone()&& { return new Quote(std::move(*this)); }

private:
	std::string bookNo;

protected:
	double price = 0.0;
};

class Disc_quote : public Quote {
public:
	Disc_quote() { }
	Disc_quote(const std::string& book, double price, std::size_t qty,
		double disc) : Quote(book, price), quantity(qty), discount(disc)
	{ }
	Disc_quote(const Disc_quote& rhs): Quote(rhs), quantity(rhs.quantity), 
	discount(rhs.discount) { }
	Disc_quote(Disc_quote&& rhs) noexcept : Quote(std::move(rhs)),
		quantity(std::move(rhs.quantity)), discount(std::move
		(rhs.discount)) { }
	Disc_quote& operator=(const Disc_quote& rhs) {
		Quote::operator=(rhs);
		quantity = rhs.quantity;
		discount = rhs.discount;
		return *this;
	}
	Disc_quote& operator=(Disc_quote&& rhs) noexcept {
		Quote::operator=(std::move(rhs));
		quantity = std::move(rhs.quantity);
		discount = std::move(rhs.discount);		
		return *this;
	}
	~Disc_quote() {	}

	double net_price(std::size_t) const = 0;
protected:
	std::size_t quantity = 0;
	double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
public:
	/*
	Bulk_quote() {
		std::cout << "Bult_quote Default constructor" << std::endl;
	}
	Bulk_quote(const std::string& book, double price, std::size_t qty,
		double disc) : Disc_quote(book, price, qty, disc) {
		std::cout << "Bult_quote string, double, size_t, double " 
			"constructor" << std::endl;
	}
	*/
	using Disc_quote::Disc_quote;//inherits constructors

	Bulk_quote(const Bulk_quote& rhs) : Disc_quote(rhs) {}
	Bulk_quote(Bulk_quote&& rhs) noexcept : Disc_quote(std::move(
		rhs)){}
	Bulk_quote& operator=(const Bulk_quote& rhs) {
		Disc_quote::operator=(rhs);
		return *this;
	}
	Bulk_quote& operator=(Bulk_quote&& rhs) noexcept {
		Disc_quote::operator=(std::move(rhs));
		return *this;
	}
	~Bulk_quote(){}

	double net_price(std::size_t) const override;
	std::ostream& debug(std::ostream& os) const override;
	Bulk_quote* clone() const& { return new Bulk_quote(*this); }
	Bulk_quote* clone()&& { return new Bulk_quote(std::move(*this)); }
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
	Limit_quote() {}
	Limit_quote(const std::string& book, double price, std::size_t qty,
		double disc) : Disc_quote(book, price, qty, disc) {}
	Limit_quote(const Limit_quote& rhs) : Disc_quote(rhs) {}
	Limit_quote(Limit_quote&& rhs) noexcept : Disc_quote(std::move(rhs))
	{}

	Limit_quote& operator=(const Limit_quote& rhs) {
		Disc_quote::operator=(rhs);
		return *this;
	}
	Limit_quote& operator=(Limit_quote&& rhs) noexcept {
		Disc_quote::operator=(std::move(rhs));
		return *this;
	}
	~Limit_quote() {}

	double net_price(std::size_t cnt) const override;
	std::ostream& debug(std::ostream& os) const override;
	Limit_quote* clone() const& { return new Limit_quote(*this); }
	Limit_quote* clone()&& { return new Limit_quote(std::move(*this)); }

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



double print_total(std::ostream& os, const Quote& item, std::size_t n) {
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: "
		<< ret << std::endl;
	return ret;
}

class Basket {
public:
	void add_item(const Quote& sale) {
		items.insert(std::shared_ptr<Quote>(sale.clone()));
	}
	void add_item(Quote&& sale) {
		items.insert(std::shared_ptr<Quote>(
			std::move(sale.clone())));
	}
	double total_receipt(std::ostream&) const;

private:
	static bool compare(const std::shared_ptr<Quote>& lhs,
		const std::shared_ptr<Quote>& rhs) {
		return lhs->isbn() < rhs->isbn();
	}
	std::multiset <std::shared_ptr<Quote>, decltype(compare)*>
		items{ compare };
};

double Basket::total_receipt(std::ostream& os) const {
	double sum = 0.0;
	for (auto iter = items.cbegin();
		iter != items.cend(); iter = items.upper_bound(*iter)) {
		sum += print_total(os, **iter, items.count(*iter));
	}
	os << "Total Sale: " << sum << std::endl;
	return sum;
}



int main() {

	Quote q("999", 5.99);
	Bulk_quote bq("998", 9.99, 20, 0.1);
	Limit_quote lq("997", 2.99, 2, 0.2);

	Quote* iq = &bq;
	Bulk_quote bq2(bq), bq3(std::move(bq2));
	iq = &lq;
	Limit_quote lq2(lq);

	std::vector<Quote> qvec;
	qvec.push_back(q);
	qvec.push_back(bq);
	qvec.push_back(lq);
	qvec.push_back(Bulk_quote("996", 4.99, 10, 0.5));
	double total_price = 0.0;
	for (const auto& i : qvec) {
		total_price += i.net_price(10);
	}
	std::cout << "\n\nThe total price of all books is: " << total_price
		<< "\n\n" << std::endl;
	//discount not applied
	
	std::vector<std::shared_ptr<Quote>> shvec;
	shvec.push_back(std::make_shared<Quote>(q));
	shvec.push_back(std::make_shared<Bulk_quote>(bq));
	shvec.push_back(std::make_shared<Limit_quote>(lq));
	shvec.push_back(std::make_shared<Bulk_quote>("996",
		4.99, 10, 0.5));

	total_price = 0.0;
	for (const auto& i : shvec) {
		total_price += i->net_price(10);
	}
	std::cout << "The total price of all books is: " << total_price
		<< "\n\n" << std::endl;
	//discount applied
	
	Basket basket;
	basket.add_item(q);
	basket.add_item(bq);
	basket.add_item(lq);
	//use move
	basket.add_item(Bulk_quote("996", 4.99, 10, 0.5));
	basket.add_item(Bulk_quote("996", 4.99, 10, 0.5));
	basket.add_item(Bulk_quote("996", 4.99, 10, 0.5));
	basket.add_item(Bulk_quote("996", 4.99, 10, 0.5));
	basket.add_item(Bulk_quote("996", 4.99, 10, 0.5));
	basket.add_item(Bulk_quote("996", 4.99, 10, 0.5));
	basket.add_item(Bulk_quote("996", 4.99, 10, 0.5));
	basket.add_item(Bulk_quote("996", 4.99, 10, 0.5));
	basket.add_item(Bulk_quote("996", 4.99, 10, 0.5));
	basket.add_item(Bulk_quote("996", 4.99, 10, 0.5));
	basket.add_item(Bulk_quote("996", 4.99, 10, 0.5));

	basket.total_receipt(std::cout);

	return 0;
}