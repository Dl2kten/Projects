#include"ConstStrBlobPtr.h"
#include<iostream>
/*
* Function check, checks that wptr.lock() is valid and that element is
* within range
* param size_t, const string&
* return std::shared_ptr<std::vector<str::string>>
*/
std::shared_ptr<std::vector<std::string>> ConstStrBlobPtr::check(
	std::size_t i, const std::string& msg) const {
	auto sp = wptr.lock();

	if (!sp) //no shared_ptr
		throw std::runtime_error("unbound StrBlobPtr");
	if (i >= sp->size()) {//index out of range
		throw std::out_of_range(msg);
	}
	return sp;
}

/*
* Function deref returns element from data member
* param
* return string&
*/
std::string& ConstStrBlobPtr::deref() const {
	auto sp = check(curr, "element out of range");
	return (*sp)[curr];
}

/*
* Function incr, increments curr count
* param
* return StrBlobPtr&
*/
ConstStrBlobPtr& ConstStrBlobPtr::incr() {
	check(curr, "incremented past end of range");
	++curr;
	return *this;
}