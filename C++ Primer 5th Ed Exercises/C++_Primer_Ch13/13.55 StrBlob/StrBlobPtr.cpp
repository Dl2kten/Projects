#include"StrBlobPtr.h"
#include<iostream>


/*
* Function check, checks that wptr.lock() is valid and that element is
* within range
* param size_t, const string&
* return std::shared_ptr<std::vector<str::string>>
*/
std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i,
	const std::string& msg) const {
	auto sp = wptr.lock();

	if (!sp) //no shared_ptr
		throw std::runtime_error("unbound StrBlobPtr");
	if (i >= sp->size()) {//index out of range
		throw std::out_of_range(msg);
	}
	return sp;
}

/*
* Prefix ++ for StrBlobPtr
*/
StrBlobPtr& StrBlobPtr::operator++() {
	check(curr, "Increment past end of StrBlobPtr");
	++curr;
	return *this;
}

/*
* Prefix -- for StrBlobPtr
*/
StrBlobPtr& StrBlobPtr::operator--() {
	--curr;
	check(-1, "Decrement past begin of StrBlobPtr");
	return *this;
}

/*
* Postfix ++ for StrBlobPtr
*/
StrBlobPtr StrBlobPtr::operator++(int) {
	auto ret = *this;
	++* this;
	return ret;
}

/*
* Postfix -- for StrBlobPtr
*/
StrBlobPtr StrBlobPtr::operator--(int) {
	auto ret = *this;
	--* this;
	return ret;
}

/*
* Operator + for pointer arithmetic
*/
StrBlobPtr StrBlobPtr::operator+(unsigned n) {
	StrBlobPtr temp = *this;
	return temp += n;
}

/*
* Operator += for pointer arithmetic
*/
StrBlobPtr& StrBlobPtr::operator+=(unsigned n) {
	curr += n;
	check(curr, "Increment pas end of StrBlobPtr");
	return *this;
}

/*
* Operator - for pointer arithmetic between two StrBlobPtr objects
*/
unsigned operator-(const StrBlobPtr& sbp1, const StrBlobPtr& sbp2) {
	return sbp1.curr - sbp2.curr;
}

/*
* Operator - for pointer arithmetic between StrBlobPtr object and unsigned
*/
StrBlobPtr StrBlobPtr::operator-(unsigned n) {
	StrBlobPtr temp = *this;
	return temp -= n;
}

/*
* Operator -= for pointer arithmetic
*/
StrBlobPtr& StrBlobPtr::operator-=(unsigned n) {
	if (n > curr)
		check(-1, "Decrement past begin of StrBlobPtr");
	curr -= n;
	return *this;
}

/*
* Function deref returns element from data member
* param
* return string&
*/
std::string& StrBlobPtr::deref() const {
	auto sp = check(curr, "element out of range");
	return (*sp)[curr];
}

/*
* Function incr, increments curr count
* param
* return StrBlobPtr&
*/
StrBlobPtr& StrBlobPtr::incr() {
	check(curr, "incremented past end of range");
	++curr;
	return *this;
}
