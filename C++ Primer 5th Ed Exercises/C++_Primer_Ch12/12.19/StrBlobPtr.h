#pragma once
#include<memory>
#include<vector>
#include<string>
#include"StrBlob.h"

/*
* Class StrBlobPtr, throws exception on attempts to access a nonexistent
* data element in StrBlobk, operates on the index value stored in curr
*/
class StrBlobPtr {
public:
	StrBlobPtr() : curr(0) {}
	StrBlobPtr(StrBlob& a, size_t sz = 0) : wptr(a.data), curr(sz) {}
	std::string& deref() const;
	StrBlobPtr& incr();

private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t,
		const std::string&) const;
	std::size_t curr;
	std::weak_ptr < std::vector<std::string>> wptr;
	/*
	* Online answers just had class StrBlob over include, that's prob
	* better performance(?)
	*/
};
