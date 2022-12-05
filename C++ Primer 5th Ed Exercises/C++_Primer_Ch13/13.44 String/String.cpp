#include "String.h"
#include <utility>
#include <iostream>
/*
* Constructor that takes const char*
*/
String::String(const char* p): first_char(nullptr), first_free(nullptr),
maxcap(nullptr) {
	auto length = strlen(p);
	for (size_t i = 0; i < length; ++i, ++p)
		push_back(*p);
}

/*
* Function alloc_n_copy, allocates new memory and copies elements
* param const char*, const char*
* return pair<char*, char*>
*/
std::pair<char*, char*> String::alloc_n_copy(const char* b, const char* e) {
	auto data = alloc.allocate(e - b);
	return { data, std::uninitialized_copy(b, e, data)};
}

/*
* Function free, destroys elements and frees memory
*/
void String::free() {
	if (first_char) {
		for (auto p = first_free; p != first_char;)
			alloc.destroy(--p);
		alloc.deallocate(first_char, maxcap - first_char);
	}
}

/*
* Function reallocate, allocates more space if needed
* param
* return void
*/
void String::reallocate() {
	auto new_capacity = size() ? 2 * size() : 1;
	auto new_data = alloc.allocate(new_capacity);
	auto dest = new_data;
	auto elem = first_char;
	for (size_t i = 0; i < size(); ++i)
		alloc.construct(dest++, std::move(*elem++));

	free();
	first_char = new_data;
	first_free = dest;
	maxcap = first_char + new_capacity;
}

/*
* Copy constructor for String
*/
String::String(const String& s) {
	std::cout << "Copy constructor" << std::endl;
	auto new_data = alloc_n_copy(s.begin(), s.end());
	first_char = new_data.first;
	first_free = maxcap = new_data.second;
}

/*
* Copy-assignment operator for String
*/
String& String::operator=(const String& rhs) {
	std::cout << "Copy-assignement operator" << std::endl;
	auto new_data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	first_char = new_data.first;
	first_free = maxcap = new_data.second;
	return *this;
}

/*
* Move constructor for String
*/
String::String(String&& s) noexcept: first_char(s.first_char),
first_free(s.first_free), maxcap(s.maxcap) {
	std::cout << "Move constructor" << std::endl;
	s.first_char = s.first_free = s.maxcap = nullptr;
}

/*
* Move-assignment operator for String
*/
String& String::operator=(String&& rhs) noexcept {
	std::cout << "Move-assignment operator" << std::endl;
	if (this != &rhs) {
		free();
		first_char = rhs.first_char;
		first_free = rhs.first_free;
		maxcap = rhs.maxcap;
		rhs.first_char = rhs.first_free = rhs.maxcap = nullptr;
	}
	return *this;
}

/*
* Destructor for String
*/
String::~String() {
	free();
}

/*
* Function push_back adds char
* param const char&
* return void
*/
void String::push_back(const char& c) {
	chk_n_alloc();
	alloc.construct(first_free++, c);
}

/*
* << Operator for String
*/
std::ostream& operator<<(std::ostream& os, const String& s) {
	for (auto p = s.first_char; p != s.first_free; ++p)
		os << *p;
	return os;
}

/*
* Operator < for String
*/
bool operator<(const String& lhs, const String& rhs) {
	auto l = lhs.begin(), r = rhs.begin();
	for (; l != lhs.end() && r != rhs.end(); ++l, ++r) {
		if (*l != *r)
			return l < r;
	}
	return l == lhs.end() && r != rhs.end();
}

/*
* Operator > for String
*/
bool operator>(const String& lhs, const String& rhs) {
	return rhs < lhs;
}

/*
* Operator <= for String
*/
bool operator<=(const String& lhs, const String& rhs) {
	return !(rhs < lhs);
}

/*
* Operator >= for String
*/
bool operator>=(const String& lhs, const String& rhs) {
	return !(lhs < rhs);
}

