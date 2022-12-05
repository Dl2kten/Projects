#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <stdexcept>
#include <cstdlib>

template<typename> class BlobPtr;


template<typename T>
class Blob {
	friend class BlobPtr<T>;
public:
	using value_type = T;
	using sz = typename std::vector<T>::size_type;

	Blob() try: data(std::make_shared<std::vector<T>>()) {
	}
	catch (const std::bad_alloc& be) {
		std::cerr << be.what() << std::endl;
		abort();
	}
	Blob(std::initializer_list<T> il) try: data(std::make_shared<std
		::vector<T>>(il)) {
	}
	catch (const std::bad_alloc& be) {
		std::cerr << be.what() << std::endl;
		abort();
	}
	template<typename Iter>
	Blob(const Iter, const Iter);

	std::size_t size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	void push_back(const T& t) { data->push_back(t); }
	void push_back(T&& t) { data->push_back(std::move(t)); }
	void pop_back();

	T& front();
	T& front() const;
	T& back();
	T& back() const;
	T& operator[](sz i);
	T& operator[](sz i) const;

private:
	std::shared_ptr<std::vector<T>> data;
	void check(sz i, const std::string& msg) const;
};

/*
* Template constructor taking two iterators
*/
template<typename T>
template<typename Iter>
inline Blob<T>::Blob(const Iter b, const Iter e) try: data(
	std::make_shared<std::vector<T>>(b, e)) {
}
catch (...) {
	std::cerr << "Error" << std::endl;
	abort();
}

/*
* check function to see if index out of range
*/
template <typename T>
void Blob<T>::check(sz i, const std::string& msg) const {
	if (i >= data->size())
		throw std::out_of_range(msg);
}

/*
* front() function returns front element of data
*/
template <typename T>
T& Blob<T>::front() {
	check(0, "front on empty Blob");
	return data->front();
}

/*
* front() function returns front element of data, const version
*/
template <typename T>
T& Blob<T>::front() const {
	check(0, "front on empty Blob");
	return data->front();
}

/*
* back() function returns back element of data
*/
template <typename T>
T& Blob<T>::back() {
	check(0, "back on empty Blob");
	return data->back();
}

/*
* back() function returns back element of data, const version
*/
template <typename T>
T& Blob<T>::back() const {
	check(0, "back on empty Blob");
	return data->back();
}

/*
* operator[] function returns element at i of data
*/
template <typename T>
T& Blob<T>::operator[](sz i) {
	check(i, "subscript out of range");
	return (*data)[i];
}

/*
* operator[] function returns element at i of data, const version
*/
template <typename T>
T& Blob<T>::operator[](sz i) const {
	check(i, "subscript out of range");
	return (*data)[i];
}

/*
* pop_back() function erases last element of data
*/
template <typename T>
void Blob<T>::pop_back() {
	check(0, "pop_back on empty Blob");
	data->pop_back();
}