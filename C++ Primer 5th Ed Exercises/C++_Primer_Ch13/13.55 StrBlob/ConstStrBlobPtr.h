#pragma once
#include"StrBlob.h"

class ConstStrBlobPtr {
public:
	ConstStrBlobPtr() : curr(0) {}
	ConstStrBlobPtr(const StrBlob& a, size_t sz = 0) :
		wptr(a.data), curr(sz) {}
	std::string& deref() const;
	ConstStrBlobPtr& incr();

private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t,
		const std::string&) const;
	std::size_t curr;
	std::weak_ptr < std::vector<std::string>> wptr;
};