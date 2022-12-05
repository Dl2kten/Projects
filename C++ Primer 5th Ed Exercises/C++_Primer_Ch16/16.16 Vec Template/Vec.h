#pragma once
#include <string>
#include <memory>
#include <algorithm>
#include <utility>
#include <iostream>

template<typename T> class Vec;
template<typename T>
std::ostream& operator<<(std::ostream&, const Vec<T>&);
/*
* class Vec is simplified implementation of a vector like class for
* strings
*/
template<typename T>
class Vec {
	friend std::ostream& operator<< <>(std::ostream&, const Vec<T>&);
public:
	Vec() :elements(nullptr), first_free(nullptr), cap(nullptr) {}
	Vec(std::initializer_list<T>);
	Vec(const Vec<T>&);
	Vec& operator=(const Vec<T>&);
	Vec(Vec<T>&&) noexcept;
	Vec& operator=(Vec<T>&&) noexcept;
	Vec& operator=(std::initializer_list<T>);
	T& operator[](std::size_t n) {
		return elements[n];
	}
	const T& operator[](std::size_t n) const {
		return elements[n];
	}
	~Vec();

	void push_back(const T& s);
	void resize(unsigned);
	void resize(unsigned, const T&);
	void reserve(unsigned);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	T* begin() const { return elements; }
	T* end() const { return first_free; }

private:
	std::allocator<T> alloc;
	void chk_n_alloc() {
		if (size() == capacity())
			reallocate();
	}
	void resize_helper(unsigned, const T&);
	//utility functions to help with copy control
	std::pair<T*, T*> alloc_n_copy(const T*,
		const T*);
	void free();
	void reallocate();
	T* elements;
	T* first_free;
	T* cap;
};

/*
* Operator == for Vec
*/
template<typename T>
inline bool operator==(const Vec<T>& lhs, const Vec<T>& rhs) {
	return lhs.size() == rhs.size() &&
		std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

/*
* Function alloc_n_copy allocates space for array and copies the elements
* param const T*, const T*
* return std::pair<T*, T*>
*/
template<typename T>
inline std::pair<T*, T*> Vec<T>::alloc_n_copy(const T* b, const T* e)
{
	auto data = alloc.allocate(e - b);
	return { data, std::uninitialized_copy(b, e, data) };
}

/*
* Function free, destroys the elements and deallocates memory
* param
* return void
*/
template<typename T>
inline void Vec<T>::free() {

	if (elements) {
		std::for_each(elements, first_free,
			[this](T& a) { alloc.destroy(&a); });
		alloc.deallocate(elements, cap - elements);
	}
}


/*
* Function reallocate, increases capacity by two and moves elements into
* new memory
* param
* return void
*/
template<typename T>
inline void Vec<T>::reallocate() {
	auto newCapacity = size() ? 2 * size() : 1;
	auto newData = alloc.allocate(newCapacity);

	auto dest = newData;
	auto elem = elements;

	for (size_t i = 0; i < size(); ++i)
		alloc.construct(dest++, std::move(*elem++));

	free();

	elements = newData;
	first_free = dest;
	cap = elements + newCapacity;
}

/*
* Constructor that takes an initializer-list
*/
template<typename T>
inline Vec<T>::Vec(std::initializer_list<T> sil) {
	for (auto iter = sil.begin(); iter != sil.end();
		++iter)
		push_back(*iter);
}
/*
* Copy constructor for Vec
*/
template<typename T>
inline Vec<T>::Vec(const Vec& sv) {
	auto new_ptrs = alloc_n_copy(sv.begin(),
		sv.end());
	elements = new_ptrs.first;
	first_free = cap = new_ptrs.second;
	//will reallocate if for next element
}

/*
* Copy-assignment operator for Vec
*/
template<typename T>
inline Vec<T>& Vec<T>::operator=(const Vec<T>& v) {
	auto new_ptrs = alloc_n_copy(v.begin(),
		v.end());
	free(); //self-assignment
	elements = new_ptrs.first;
	first_free = cap = new_ptrs.second;
	return *this;
}


/*
* Move constructor for Vec
*/
template<typename T>
inline Vec<T>::Vec(Vec&& s) noexcept :elements(s.elements),
first_free(s.first_free), cap(s.cap) {
	s.elements = s.first_free = s.cap = nullptr;
}

/*
* Move-assignment operator for Vec
*/
template<typename T>
inline Vec<T>& Vec<T>::operator=(Vec<T>&& rhs) noexcept {
	if (this != &rhs) {
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

/*
* Assignment operator for Vec that takes an initializer_list
*/
template<typename T>
inline Vec<T>& Vec<T>::operator=(std::initializer_list<T> sil) {
	auto new_data = alloc_n_copy(sil.begin(), sil.end());
	free();
	elements = new_data.first;
	first_free = cap = new_data.second;
	return *this;
}

/*
* Destructor for Vec
*/
template<typename T>
inline Vec<T>::~Vec() {
	free();
}

/*
* Function push_back adds new element
* param const str::string&
* return void
*/
template<typename T>
inline void Vec<T>::push_back(const T& s) {
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

/*
* void resize_helper does the operations needed for the two resize members
* param const T&
* return void
*/
template<typename T>
inline void Vec<T>::resize_helper(unsigned n, const T& t) {
	if (n < size()) {
		while (first_free != elements + n)
			alloc.destroy(--first_free);
	}
	else {
		for (auto i = n - size(); i > 0; --i) {
			push_back(t);
		}
	}
}

/*
* Function resize makes Vec size() bigger or smaller
* param unsigned n
* return void
*/
template<typename T>
inline void Vec<T>::resize(unsigned n) {
	T t;
	resize_helper(n, t);
}

/*
* Function resize makes Vec size() bigger or smaller
* param unsigned n, const string&
* return void
*/
template<typename T>
inline void Vec<T>::resize(unsigned n, const T& s) {
	resize_helper(n, s);
}

/*
* Function reserve, reserves specified amount of space
* param unsigned n
* return void
*/
template<typename T>
inline void Vec<T>::reserve(unsigned n) {
	if (n > capacity()) {
		auto newData = alloc.allocate(n);

		auto dest = newData;
		auto elem = elements;

		for (size_t i = 0; i < size(); ++i)
			alloc.construct(dest++, std::move(*elem++));

		free();

		elements = newData;
		first_free = dest;
		cap = elements + n;
	}
}

/*
* Operator < for Vec
*/
template<typename T>
inline bool operator<(const Vec<T>& lhs, const Vec<T>& rhs) {
	auto l = lhs.begin(), r = rhs.begin();
	for (; l != lhs.end() && r != rhs.end(); ++l, ++r) {
		if (*l != *r)
			return *l < *r;
	}
	return l == lhs.end() && r != rhs.end();
	
}

/*
* Operator > for Vec
*/
template<typename T>
inline bool operator>(const Vec<T>& lhs, const Vec<T>& rhs) {
	return rhs < lhs;
}

/*
* Operator <= for Vec
*/
template<typename T>
inline bool operator<=(const Vec<T>& lhs, const Vec<T>& rhs) {
	return !(rhs < lhs);
}

/*
* Operator >= for Vec
*/
template<typename T>
inline bool operator>=(const Vec<T>& lhs, const Vec<T>& rhs) {
	return !(lhs < rhs);
}

/*
* Operator != for Vec
*/
template<typename T>
inline bool operator!=(const Vec<T>& lhs, const Vec<T>& rhs) {
	return !(lhs == rhs);
}

/*
* operator<< for Vec
*/
template<typename T>
inline std::ostream& operator<<(std::ostream& os, const Vec<T>& v)
{
	for (auto p = v.elements; p != v.first_free; ++p)
		os << *p << " ";
	return os;
}