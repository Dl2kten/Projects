#include <iostream>

/*
* Exercise 15.27
* Redefine Bulk_quote to inherit its constructors
*/


class Quote {
public:
	Quote() { std::cout << "Quote Default constructor" << std::endl; }
	Quote(const std::string& book, double sales_price) : bookNo(book),
		price(sales_price) {
		std::cout << "Quote bookNo price constructor" << std::endl;
	}
	Quote(const Quote& rhs): bookNo(rhs.bookNo), price(rhs.price) {
		std::cout << "Quote Copy constructor" << std::endl;
	}
	Quote(Quote&& rhs) noexcept: bookNo(std::move(rhs.bookNo)),
		price(std::move(rhs.price)) {
		std::cout << "Quote Move constructor" << std::endl;
	}
	Quote& operator=(const Quote& rhs) {
		bookNo = rhs.bookNo;
		price = rhs.price;
		std::cout << "Quote Copy-assingment operator" << std::endl;
		return *this;
	}
	Quote& operator=(Quote&& rhs) noexcept {
		bookNo = std::move(rhs.bookNo);
		price = std::move(rhs.price);
		std::cout << "Quote Move-assingment operator" << std::endl;
		return *this;
	}
	virtual ~Quote() {
		std::cout << "Quote destructor" << std::endl;
	}

	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const { return n * price; }
	virtual std::ostream& debug(std::ostream& os) const {
		os << "Data members are string bookNo: " << bookNo
			<< " and double price: " << price << std::endl;
		return os;
	}

private:
	std::string bookNo;

protected:
	double price = 0.0;
};

class Disc_quote : public Quote {
public:
	Disc_quote() { std::cout << "Disc_quote Default constructor" 
		<< std::endl; }
	Disc_quote(const std::string& book, double price, std::size_t qty,
		double disc) : Quote(book, price), quantity(qty), discount(disc)
	{
		std::cout << "Disc_quote quantity discount constructor"
			<< std::endl;
	}
	Disc_quote(const Disc_quote& rhs): Quote(rhs), quantity(rhs.quantity), 
	discount(rhs.discount) {
		std::cout << "Disc_quote copy constructor"
			<< std::endl;
	}
	Disc_quote(Disc_quote&& rhs) noexcept : Quote(std::move(rhs)),
		quantity(std::move(rhs.quantity)), discount(std::move
		(rhs.discount)) {
		std::cout << "Disc_quote move constructor"
			<< std::endl;
	}
	Disc_quote& operator=(const Disc_quote& rhs) {
		Quote::operator=(rhs);
		quantity = rhs.quantity;
		discount = rhs.discount;
		std::cout << "Disc_quote copy-assignment operator" << std::endl;
		return *this;
	}
	Disc_quote& operator=(Disc_quote&& rhs) noexcept {
		Quote::operator=(std::move(rhs));
		quantity = std::move(rhs.quantity);
		discount = std::move(rhs.discount);		
		std::cout << "Disc_quote move-assignment operator" << std::endl;
		return *this;
	}
	~Disc_quote() {
		std::cout << "Disc_quote destructor" << std::endl;
	}

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

	Bulk_quote(const Bulk_quote& rhs) : Disc_quote(rhs) {
		std::cout << "Bulk_quote copy constructor" << std::endl;
	}
	Bulk_quote(Bulk_quote&& rhs) noexcept : Disc_quote(std::move(rhs)){
		std::cout << "Bulk_quote move constructor" << std::endl;
	}
	Bulk_quote& operator=(const Bulk_quote& rhs) {
		Disc_quote::operator=(rhs);
		std::cout << "Bult_quote copy-assignment operator" << std::endl;
		return *this;
	}
	Bulk_quote& operator=(Bulk_quote&& rhs) noexcept {
		Disc_quote::operator=(std::move(rhs));
		std::cout << "Bulk_quote move-assignment operator" << std::endl;
		return *this;
	}
	~Bulk_quote(){
		std::cout << "Bulk_quote destructor" << std::endl;
	}

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
	Limit_quote() {
		std::cout << "Limit_quote default constructor"
			<< std::endl;
	}
	Limit_quote(const std::string& book, double price, std::size_t qty,
		double disc) : Disc_quote(book, price, qty, disc) {
		std::cout << "Limit_quote string, double, size_t, double"
			" constructor" << std::endl;
	}
	Limit_quote(const Limit_quote& rhs) : Disc_quote(rhs) {
		std::cout << "Limit_quote copy constructor" << std::endl;
	}
	Limit_quote(Limit_quote&& rhs) noexcept : Disc_quote(std::move(rhs))
	{
		std::cout << "Limit_quote move constructor" << std::endl;
	}
	Limit_quote& operator=(const Limit_quote& rhs) {
		Disc_quote::operator=(rhs);
		std::cout << "Limit_quote copy-assignment operator" << std::endl;
		return *this;
	}
	Limit_quote& operator=(Limit_quote&& rhs) noexcept {
		Disc_quote::operator=(std::move(rhs));
		std::cout << "Limit_quote move-assignment operator" << std::endl;
		return *this;
	}
	~Limit_quote() {
		std::cout << "Limit_quote destructor" << std::endl;
	}

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

	Quote* iq = &bq;
	Bulk_quote bq2(bq), bq3(std::move(bq2));
	iq = &lq;
	Limit_quote lq2(lq);


	return 0;
}