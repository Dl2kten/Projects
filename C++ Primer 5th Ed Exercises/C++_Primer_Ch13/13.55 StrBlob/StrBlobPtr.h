#pragma once
#include<memory>
#include<vector>
#include<string>
#include "StrBlob.h"

/*
* Class StrBlobPtr, throws exception on attempts to access a nonexistent
* data element in StrBlobk, operates on the index value stored in curr
*/
class StrBlobPtr {
public:
	friend class StrBlobPtrPtr;
	friend unsigned operator-(const StrBlobPtr&, const StrBlobPtr&);
	StrBlobPtr() : curr(0) {}
	StrBlobPtr(StrBlob& a, size_t sz = 0) : wptr(a.data), curr(sz) {}
	StrBlobPtr& operator++();
	StrBlobPtr& operator--();
	StrBlobPtr operator++(int);
	StrBlobPtr operator--(int);
	StrBlobPtr operator+(unsigned);
	StrBlobPtr operator-(unsigned);
	StrBlobPtr& operator+=(unsigned);
	StrBlobPtr& operator-=(unsigned);
	std::string& operator*() const {
		auto p = check(curr, "Dereference past end");
		return (*p)[curr];
	}
	std::string* operator->() const {
		return &this->operator*();
	}

	std::string& deref() const;
	StrBlobPtr& incr();

private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t,
		const std::string&) const;
	std::size_t curr;
	std::weak_ptr < std::vector<std::string>> wptr;

};

unsigned operator-(const StrBlobPtr&, const StrBlobPtr&);
