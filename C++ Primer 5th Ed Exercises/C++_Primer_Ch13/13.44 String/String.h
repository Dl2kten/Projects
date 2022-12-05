#pragma once
#include <cstring>
#include <memory>

/*
* class string is a simplified version of Library String
*/

class String {
public:
	friend std::ostream& operator<<(std::ostream&, const String&);
	friend bool operator==(const String&, const String&);
	friend bool operator!=(const String&, const String&);

	String() : first_char(nullptr), first_free(nullptr), maxcap(nullptr) {}
	String(const char*);
	String(const String&);
	String& operator=(const String&);
	String(String&&) noexcept;
	String& operator=(String&&) noexcept;
	char& operator[](std::size_t n) {
		return first_char[n];
	}
	const char& operator[](std::size_t n) const {
		return first_char[n];
	}
	~String();

	size_t size() const { return first_free - first_char; }
	size_t capacity() const { return maxcap - first_char; }
	char* begin() const { return first_char; }
	char* end() const { return first_free; }
	void push_back(const char&);

private:
	std::allocator<char> alloc;
	void chk_n_alloc() {
		auto a = size();
		auto b = capacity();
		if (size() == capacity())
			reallocate();
	}

	std::pair<char*, char*> alloc_n_copy(const char* b, const char* e);
	void free();
	void reallocate();
	char* first_char;
	char* first_free;
	char* maxcap;
};

/*
* Operator == for String
*/
inline bool operator==(const String& lhs, const String& rhs) {
	return lhs.size() == rhs.size() &&
		std::equal(lhs.begin(), lhs.end(), rhs.begin());
	//the size comparison comes first as equal compares two sequences
	//of equal size
}

/*
* Operator != for String
*/
inline bool operator!=(const String& lhs, const String& rhs) {
	return !(lhs == rhs);
}

bool operator<(const String&, const String&);
bool operator>(const String&, const String&);
bool operator<=(const String&, const String&);
bool operator>=(const String&, const String&);