#include "Ch12StrVec.h"
#include <memory>

namespace Ch12 {
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
	void StrVec::free() {
		if (elements) {
			for (auto p = first_free; p != elements; )
				alloc.destroy(--p);
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

		free();

		elements = newData;
		first_free = dest;
		cap = elements + newCapacity;
	}

	/*
	* Constructor that takes an initializer-list
	*/
	StrVec::StrVec(std::initializer_list<std::string> sil) {
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
		free(); //self-assignment
		elements = new_ptrs.first;
		first_free = cap = new_ptrs.second;
		return *this;
	}

	/*
	* [] operator for StrVec
	*/
	const std::string& StrVec::operator[](
		std::vector<std::string>::size_type vs_size) {
		return *(elements + vs_size);
	}

	/*
	* Destructor for StrVec
	*/
	StrVec::~StrVec() {
		free();
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
	* Function pop_back erases last element
	* param
	* return void
	*/
	void StrVec::pop_back() {
		if (size())
			alloc.destroy(--first_free);
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

			free();

			elements = newData;
			first_free = dest;
			cap = elements + n;
		}
	}

	/*
	* Function empty returns whether there are elements
	* param
	* return bool
	*/
	bool StrVec::empty() {
		return size();
	}
}
