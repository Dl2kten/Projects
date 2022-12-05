#include "StrBlob.h"
#include <iostream>
#include <stdexcept>


/*
* Default constructor
*/
StrBlob::StrBlob() : data(std::make_shared<StrVec>()) {}

/*
* Constructor taking initializer list
*/
StrBlob::StrBlob(std::initializer_list<std::string> sil) : data
(std::make_shared<StrVec>(sil)) {}

/*
* Function check, sees if vector empty
* param
* return void
*/
void StrBlob::check(sz i, const std::string& msg) const {
	if (i >= data->size())
		throw std::out_of_range::out_of_range(msg);
}
/*
* Function pop_back, erase last element
* param
* return void
*/
void StrBlob::pop_back() {
	//check to see if vector empty
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}
/*
* Function front, returns first element
* param
* return string&
*/
std::string& StrBlob::front() {
	check(0, "front on empty StrBlob");
	return data->front();
}
/*
* Function const front, returns first element
* param
* return string&
*/
const std::string& StrBlob::front() const {
	check(0, "const front on empty StrBlob");
	return data->front();
}
/*
* Function back, returns last element
* param
* return string&
*/
std::string& StrBlob::back() {
	check(0, "back on empty StrBlob");
	return data->back();
}
/*
* Function back const, returns last element
* param
* return string&
*/
const std::string& StrBlob::back() const {
	check(0, "const back on empty StrBlob");
	return data->back();
}

/*
* Function deref returns element from vector
* param sz
* return std::string&
*/
const std::string& StrBlob::deref(sz i) const
{
	return (*data)[i];
}

/*
* Function print, prints elements
* param const StrBlob&
* return void
*/
void print(const StrBlob& s) {
	if (s.size() > 0) {
		for (const auto& i : *s.data)
			std::cout << i << " ";
		std::cout << std::endl;
	}
	else {
		std::cout << "StrBlob empty." << std::endl;
	}

}
