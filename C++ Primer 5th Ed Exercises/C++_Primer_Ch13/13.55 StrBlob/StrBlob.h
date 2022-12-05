#pragma once
#include <vector>
#include <string>
#include <memory>
#include <iostream>

/*
* class StrBlob for managing strings
*/
class StrBlob {
public:
	friend class StrBlobPtr;
	friend class ConstStrBlobPtr;
	friend bool operator==(const StrBlob&, const StrBlob&);
	friend bool operator<(const StrBlob&, const StrBlob&);
	friend std::ostream& operator<<(std::ostream&, const StrBlob&);
	friend std::istream& operator>>(std::istream&, StrBlob&);
	using sz = std::vector<std::string>::size_type;
	friend void print(const StrBlob& s);

	StrBlob();
	StrBlob(std::initializer_list<std::string> sil);
	std::string& operator[](std::size_t n) {
		return (*data)[n];
	}
	const std::string& operator[](std::size_t n) const{
		return (*data)[n];
	}
	

	sz size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	void push_back(const std::string& s) {
		std::cout << "lvalue reference" << std::endl;
		data->push_back(s);
	}
	void push_back(std::string&& s) {
		std::cout << "rvalue reference" << std::endl;
		data->push_back(std::move(s));
	}
	void pop_back();

	std::string& front();
	const std::string& front() const;
	std::string& back();
	const std::string& back() const;
	std::vector<std::string>::iterator begin() const {
		return data->begin();
	}
	std::vector<std::string>::iterator end() const {
		return data->end();
	}
	const std::string& deref(sz) const;

private:
	std::shared_ptr <std::vector<std::string> > data;
	void check(sz i, const std::string& msg) const;
};

/*
* Operator == for StrBlob
*/
inline bool operator==(const StrBlob& lhs, const StrBlob& rhs) {
	return lhs.data == rhs.data;
}

/*
* Operator != for StrBlob
*/
inline bool operator!=(const StrBlob& lhs, const StrBlob& rhs) {
	return !(lhs == rhs);
}

std::ostream& operator<<(std::ostream&, const StrBlob&);
std::istream& operator>>(std::istream&, StrBlob&);
bool operator<(const StrBlob&, const StrBlob&);
bool operator>(const StrBlob&, const StrBlob&);
bool operator<=(const StrBlob&, const StrBlob&);
bool operator>=(const StrBlob&, const StrBlob&);