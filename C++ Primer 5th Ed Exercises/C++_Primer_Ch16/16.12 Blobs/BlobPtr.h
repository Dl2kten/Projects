#pragma once
#include "Blob.h"

template<typename T> class BlobPtr;
template<typename T>
bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);
template<typename T>
bool operator<(const BlobPtr<T>&, const BlobPtr<T>&);

template<typename T> class BlobPtr {
	friend bool operator==<T>(const BlobPtr<T>&, const BlobPtr<T>&);
	friend bool operator< <T>(const BlobPtr<T>&, const BlobPtr<T>&);

public:
	BlobPtr() : curr(0) {}
	BlobPtr(Blob<T>& a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}

	T& operator*() const {
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
	}
	BlobPtr& operator++();
	BlobPtr& operator--();
	BlobPtr operator++(int);
	BlobPtr operator--(int);
	
private:
	std::shared_ptr<std::vector<T>> check(std::size_t,
		const std::string&) const;
	std::weak_ptr<std::vector<T>> wptr;
	std::size_t curr;
};

/*
* Function check wptr is bound to valid shared_ptr and in range
*/
template<typename T>
std::shared_ptr<std::vector<T>> BlobPtr<T>::check(std::size_t i,
	const std::string& msg) const {
	auto sp = wptr.lock();
	if (!sp)
		throw std::runtime_error("unbound weak pointer");
	if (i >= sp->size())
		throw std::out_of_range(msg);

	return sp;
}

/*
* Function operator++, prefix increments curr count
*/
template<typename T>
BlobPtr<T>& BlobPtr<T>::operator++() {
	check(curr, "increment pasted end");
	++curr;
	return *this;
}

/*
* Function operator++, postfix increments curr count
*/
template<typename T>
BlobPtr<T> BlobPtr<T>::operator++(int) {
	BlobPtr ret = *this;
	++* this;//checked by prefix ++

	return ret;
}

/*
* Function operator--, prefix decrements curr count
*/
template<typename T>
BlobPtr<T>& BlobPtr<T>::operator--() {
	--curr;
	check(curr, "decrement pasted begin");
	return *this;
}

/*
* Function operator--, postfix decrements curr count
*/
template<typename T>
BlobPtr<T> BlobPtr<T>::operator--(int) {
	BlobPtr ret = *this;
	--* this;

	return ret;
}

/*
* operator== to compare two BlobPtr<T> objects
*/
template<typename T>
bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs) {
	auto lsp = lhs.wptr.lock();
	auto rsp = rhs.wptr.lock();
	if(!lsp)
		throw std::runtime_error("unbound weak pointer lhs");
	if (!rsp)
		throw std::runtime_error("unbound weak pointer rhs");
	return lsp == rsp && lhs.curr == rhs.curr;
}

template<typename T>
bool operator!=(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs) {
	return !(lhs == rhs);
}

/*
* operator< to compare two BlobPtr<T> objects
*/
template<typename T>
bool operator<(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs) {
	auto lsp = lhs.wptr.lock();
	auto rsp = rhs.wptr.lock();
	if (!lsp)
		throw std::runtime_error("unbound weak pointer lhs");
	if (!rsp)
		throw std::runtime_error("unbound weak pointer rhs");

	if (lsp == rsp)
		return lhs.curr < rhs.curr;
	else {
		//compare two BlobPtr<T> pointing to different Blob<T>
		auto l = lsp->begin(), r = rsp->begin();
		for (; l != lsp->end() && r != rsp->end(); ++l, ++r) {
			if (*l != *r)
				return *l < *r;
		}
		return l == lsp->end() && r != rsp->end();
	}
}

template<typename T>
bool operator>(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs) {
	return rhs < lhs;
}

template<typename T>
bool operator<=(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs) {
	return !(rhs < lhs);
}

template<typename T>
bool operator>=(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs) {
	return !(lhs > rhs);
}


