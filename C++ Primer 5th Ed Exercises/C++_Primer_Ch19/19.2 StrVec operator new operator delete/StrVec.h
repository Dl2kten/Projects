#pragma once
#include <string>
#include <memory>

/*
* class StrVec is simplified implementation of a vector like class for
* strings
*/
class StrVec {
public:
	friend bool operator==(const StrVec&, const StrVec&);
	friend std::ostream& operator<<(std::ostream&, const StrVec&);
	StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(std::initializer_list<std::string>);
	StrVec(const StrVec&);
	StrVec& operator=(const StrVec&);
	StrVec(StrVec&&) noexcept;
	StrVec& operator=(StrVec&&) noexcept;
	StrVec& operator=(std::initializer_list<std::string>);
	std::string& operator[](std::size_t n) {
		return elements[n];
	}
	const std::string& operator[](std::size_t n) const {
		return elements[n];
	}
	~StrVec();

	void push_back(const std::string& s);
	void resize(unsigned);
	void resize(unsigned, const std::string&);
	void reserve(unsigned);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	std::string* begin() const { return elements; }
	std::string* end() const { return first_free; }

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
	void release();
	void reallocate();
	std::string* elements;
	std::string* first_free;
	std::string* cap;
};

/*
* Operator == for StrVec
*/
inline bool operator==(const StrVec& lhs, const StrVec& rhs) {
	return lhs.size() == rhs.size() &&
		std::equal(lhs.begin(), lhs.end(), rhs.begin());
	//equal take two sequences of equal size
	//had to make this inline to avoid link2005 error
	//can also declare once more here and then define in StrVec.cpp(?)
}

/*
* Operator != for StrVec
*/
inline bool operator!=(const StrVec& lhs, const StrVec& rhs) {
	return !(lhs == rhs);
}

bool operator<(const StrVec&, const StrVec&);
bool operator>(const StrVec&, const StrVec&);
bool operator<=(const StrVec&, const StrVec&);
bool operator>=(const StrVec&, const StrVec&);
std::ostream& operator<<(std::ostream&, const StrVec&);