#pragma once
#include <string>
#include <vector>

namespace Ch12 {
	/*
	* class StrVec is simplified implementation of a vector like class for
	* strings
	*/
	class StrVec {
	public:
		StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr) {}
		StrVec(std::initializer_list<std::string>);
		StrVec(const StrVec&);
		StrVec& operator=(const StrVec&);
		const std::string& operator[](std::vector<std::string>::size_type);
		~StrVec();

		void push_back(const std::string& s);
		void pop_back();
		void resize(unsigned);
		void resize(unsigned, const std::string&);
		void reserve(unsigned);
		size_t size() const { return first_free - elements; }
		size_t capacity() const { return cap - elements; }
		std::string* begin() const { return elements; }
		std::string* end() const { return first_free; }
		std::string& front() const { return *elements; }
		std::string& back() const { return *(first_free - 1); }
		bool empty();
	private:
		std::allocator<std::string> alloc;
		void chk_n_alloc() {
			if (size() == capacity())
				reallocate();
		}
		void resize_helper(unsigned, const std::string&);
		//utility functions to help with copy control
		std::pair<std::string*, std::string*> alloc_n_copy(const std::string*,
			const std::string*);
		void free();
		void reallocate();
		std::string* elements;
		std::string* first_free;
		std::string* cap;
	};

}
