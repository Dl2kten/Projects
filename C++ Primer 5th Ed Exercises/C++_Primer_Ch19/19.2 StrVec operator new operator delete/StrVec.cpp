#include "StrVec.h"
#include <algorithm>
#include <utility>
#include <iostream>
#include <cstdlib>

/*
* Function alloc_n_copy allocates space for array and copies the elements
* param const std::string*, const std::string*
* return std::pair<std::string*, std::string*>
*/
std::pair<std::string*, std::string*> StrVec::alloc_n_copy(
	const std::string* b, const std::string* e) {
	auto data = alloc.allocate(e - b);
	return { data, std::uninitialized_copy(b, e, data) };
}

/*
* Function free, destroys the elements and deallocates memory
* param
* return void
*/
void StrVec::release() {
	/*if (elements) {
		for (auto p = first_free; p != elements; )
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}*/

	if (elements) {
		std::for_each(elements, first_free,
			[this](std::string& a) { alloc.destroy(&a); });
		alloc.deallocate(elements, cap - elements);
	}
}


/*
* Function reallocate, increases capacity by two and moves elements into
* new memory
* param
* return void
*/
void StrVec::reallocate() {
	auto newCapacity = size() ? 2 * size() : 1;
	auto newData = alloc.allocate(newCapacity);

	auto dest = newData;
	auto elem = elements;

	for (size_t i = 0; i < size(); ++i)
		alloc.construct(dest++, std::move(*elem++));

	release();

	elements = newData;
	first_free = dest;
	cap = elements + newCapacity;
}

/*
* Constructor that takes an initializer-list
*/
StrVec::StrVec(std::initializer_list<std::string> sil): elements(nullptr), 
	first_free(nullptr), cap(nullptr) {
	for (auto iter = sil.begin(); iter != sil.end();
		++iter)
		push_back(*iter);
}
/*
* Copy constructor for StrVec
*/
StrVec::StrVec(const StrVec& sv) {
	auto new_ptrs = alloc_n_copy(sv.begin(),
		sv.end());
	elements = new_ptrs.first;
	first_free = cap = new_ptrs.second;
	//will reallocate if for next element
}

/*
* Copy-assignment operator for StrVec
*/
StrVec& StrVec::operator=(const StrVec& sv) {
	auto new_ptrs = alloc_n_copy(sv.begin(),
		sv.end());
	release(); //self-assignment
	elements = new_ptrs.first;
	first_free = cap = new_ptrs.second;
	return *this;
}

/*
* Move constructor for StrVec
*/
StrVec::StrVec(StrVec&& s) noexcept :elements(s.elements),
first_free(s.first_free), cap(s.cap) {
	s.elements = s.first_free = s.cap = nullptr;
}

/*
* Move-assignment operator for StrVec
*/
StrVec& StrVec::operator=(StrVec&& rhs) noexcept {
	if (this != &rhs) {
		release();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

/*
* Assignment operator for StrVec that takes an initializer_list
*/
StrVec& StrVec::operator=(std::initializer_list<std::string> sil) {
	auto new_data = alloc_n_copy(sil.begin(), sil.end());
	release();
	elements = new_data.first;
	first_free = cap = new_data.second;
	return *this;
}

/*
* Destructor for StrVec
*/
StrVec::~StrVec() {
	release();
}

/*
* Function push_back adds new element
* param const str::string&
* return void
*/
void StrVec::push_back(const std::string& s) {
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

/*
* void resize_helper does the operations needed for the two resize members
* param const std::string&
* return void
*/
void StrVec::resize_helper(unsigned n, const std::string& str) {
	if (n < size()) {
		while (first_free != elements + n)
			alloc.destroy(--first_free);

	}
	else {
		for (auto i = n - size(); i > 0; --i)
			push_back(str);
	}
}

/*
* Function resize makes StrVec size() bigger or smaller
* param unsigned n
* return void
*/
void StrVec::resize(unsigned n) {
	resize_helper(n, "");
}

/*
* Function resize makes StrVec size() bigger or smaller
* param unsigned n, const string&
* return void
*/
void StrVec::resize(unsigned n, const std::string& s) {
	resize_helper(n, s);
}

/*
* Function reserve, reserves specified amount of space
* param unsigned n
* return void
*/
void StrVec::reserve(unsigned n) {
	if (n > capacity()) {
		auto newData = alloc.allocate(n);

		auto dest = newData;
		auto elem = elements;

		for (size_t i = 0; i < size(); ++i)
			alloc.construct(dest++, std::move(*elem++));

		release();

		elements = newData;
		first_free = dest;
		cap = elements + n;
	}
}

/*
* Operator < for StrVec
*/
bool operator<(const StrVec& lhs, const StrVec& rhs) {
	auto l = lhs.begin(), r = rhs.begin();
	for (; l != lhs.end() && r != rhs.end(); ++l, ++r) {
		if (*l != *r)
			return l < r;
	}
	return l == lhs.end() && r != rhs.end();
	//returns true if l reaches end() and r does not,
	//false if r reaches end first or equal
}

/*
* Operator > for StrVec
*/
bool operator>(const StrVec& lhs, const StrVec& rhs) {
	return rhs < lhs;
}

/*
* Operator <= for StrVec
*/
bool operator<=(const StrVec& lhs, const StrVec& rhs) {
	return !(rhs < lhs);
}

/*
* Operator >= for StrVec
*/
bool operator>=(const StrVec& lhs, const StrVec& rhs) {
	return !(lhs < rhs);
}

/*
* Output operator << for StrVec
*/
std::ostream& operator<<(std::ostream& os, const StrVec& stvec) {
	for (auto p = stvec.elements; p != stvec.first_free; ++p)
		os << *p << " ";
	return os;
}

/*
* operator new used in new expression
*/
void* operator new(std::size_t sz) {
	if (void* mem = malloc(sz))
		return mem;
	else
		throw std::bad_alloc();
}

/*
* operator delete used in delete expression
*/
void operator delete(void* mem) noexcept {
	free(mem);
}