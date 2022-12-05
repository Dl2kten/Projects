#pragma once

/*
* U_ptr behaves like Unique_ptr
*/
template<typename T, typename D = void(*)(T*) >
class U_ptr {
	using delete_function = void(*)(T*);
public:
	U_ptr() : t_ptr(nullptr) {}
	//U_ptr(T* ptr) : t_ptr(ptr) {}
	U_ptr(T* ptr, D d = delete_function) : t_ptr(ptr), deleter(d) {}
	U_ptr(const U_ptr&) = delete;
	U_ptr<T>& operator=(const U_ptr&) = delete;
	~U_ptr();

	T& operator*() const { return *get(); }
	T* operator->() const { return get(); }
	T* get() { return t_ptr; }
	U_ptr<T>& swap(U_ptr<T>&);
	void swap(U_ptr<T>&, U_ptr<T>&);

	T* release();
	void reset(T* p = T());

private:
	T* t_ptr;
	delete_function deleter;
};

/*
* Destructor
*/
template<typename T, typename D>
inline U_ptr<T, D>::~U_ptr()
{
	deleter ? deleter(t_ptr) : delete t_ptr;
}

/*
* Swap taking two U_ptr<T> objects
*/
template<typename T, typename D>
inline void U_ptr<T, D>::swap(U_ptr<T>& lhs, U_ptr<T>& rhs)
{
	using std::swap;
	swap(lhs.t_ptr, rhs.t_ptr);
}

/*
* Swap taking one U_ptr<T> objects
*/
template<typename T, typename D>
inline U_ptr<T>& U_ptr<T, D>::swap(U_ptr<T>& rhs)
{
	swap(*this, rhs);
	return *this;
}

/*
* release function returns pointer held
*/
template<typename T, typename D>
inline T* U_ptr<T, D>::release()
{
	//delete?
	T* temp = t_ptr;
	t_ptr = nullptr;
	return temp;
}

/*
* reset function deletes object to which pointer points
*/
template<typename T, typename D>
inline void U_ptr<T, D>::reset(T* p)
{
	//check assign to self? param take ref to ptr?
	delete t_ptr;
	t_ptr = p;
}