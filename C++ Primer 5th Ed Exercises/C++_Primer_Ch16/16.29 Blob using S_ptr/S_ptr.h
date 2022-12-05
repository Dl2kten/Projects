#pragma once
#include <iostream>
#include <stdexcept>

/*
* Class S_ptr behaves like shared_ptr
*/
template<typename T>
class S_ptr {
	using delete_function = void(*)(T*);
public:
	S_ptr() : t_ptr(nullptr), counter(new std::size_t(1)) {}
	S_ptr(T* ptr) : t_ptr(ptr), counter(new std::size_t(1)) {}
	S_ptr(T* ptr, delete_function df) : t_ptr(ptr), deleter(df) {}
	S_ptr(const S_ptr<T>&);
	S_ptr(S_ptr<T>&&);
	S_ptr<T>& operator=(const S_ptr<T>&);
	S_ptr<T>& operator=(S_ptr<T>&&);
	~S_ptr();

	T& operator*() const {
		if (get() == nullptr) {
			throw std::runtime_error("Trying to dereference nullptr");
		} else 
			return *get(); }
	T* operator->() const {
		if (get() == nullptr) {
			throw std::runtime_error("Trying to dereference nullptr");
		} else
		return get(); }
	bool one() { return ((*counter == 1) ? true : false); }
	std::size_t u_count() { return *counter; }
	T* get() const { return t_ptr; }
	S_ptr<T>& swap(S_ptr<T>&);
	void swap(S_ptr<T>&, S_ptr<T>&);
private:
	void free();
	T* t_ptr;
	std::size_t* counter;
	delete_function deleter;
};

/*
* Copy constructor for S_ptr
*/
template<typename T>
S_ptr<T>::S_ptr(const S_ptr<T>& operand) : t_ptr(operand.t_ptr),
counter(operand.counter), deleter(operand.deleter) {
	++* counter;
}

/*
* Move constructor for S_ptr
*/
template<typename T>
S_ptr<T>::S_ptr(S_ptr<T>&& operand) : t_ptr(operand.t_ptr),
counter(operand.counter), deleter(operand.deleter)
{
	operand.t_ptr = nullptr;
	operand.counter = new std::size_t(1);
}

/*
* Copy-assignment operator for S_ptr
*/
template<typename T>
S_ptr<T>& S_ptr<T>::operator=(const S_ptr<T>& rhs) {
	++* rhs.counter;
	free();
	t_ptr = rhs.t_ptr;
	counter = rhs.counter;
	deleter = rhs.deleter;
	return *this;
}


/*
* Move-assignment operator
*/
template<typename T>
S_ptr<T>& S_ptr<T>::operator=(S_ptr<T>&& rhs)
{
	if (this->t_ptr != rhs.t_ptr) {
		free();
		t_ptr = rhs.t_ptr;
		counter = rhs.counter;
		deleter = rhs.deleter;

		rhs.t_ptr = nullptr;
		rhs.counter = new std::size_t(1);
	}
	return *this;
}

/*
* Destructor
*/
template<typename T>
S_ptr<T>::~S_ptr()
{
	if (-- * counter == 0) {
		deleter ? deleter(t_ptr) : delete t_ptr;
		delete counter;
	}
}

/*
* free resources
*/
template<typename T>
void S_ptr<T>::free()
{
	if (-- * counter == 0) {
		delete t_ptr;
		delete counter;
	}
}

/*
* swap function taking two S_ptr<T>
*/
template<typename T>
void S_ptr<T>::swap(S_ptr<T>& lhs, S_ptr<T>& rhs)
{
	using std::swap;
	swap(lhs.t_ptr, rhs.t_ptr);
	swap(lhs.counter, rhs.counter);
}

/*
* swap function taking one S_ptr<T>
*/
template<typename T>
S_ptr<T>& S_ptr<T>::swap(S_ptr<T>& rhs)
{
	swap(*this, rhs);
	return *this;
}