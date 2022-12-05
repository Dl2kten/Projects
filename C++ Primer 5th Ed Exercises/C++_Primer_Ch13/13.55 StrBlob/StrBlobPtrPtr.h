#pragma once
#include "StrBlobPtr.h"
/*
* Class StrBlobPtrPtr holds a pointer to a StrBlobPtr
*/

class StrBlobPtrPtr {
public:
	StrBlobPtrPtr() : str_blob_ptr(nullptr) {}
	StrBlobPtrPtr(StrBlobPtr& a) : str_blob_ptr(&a) {}

	std::string& operator*() const {
		return str_blob_ptr->operator*();
	}
	std::string* operator->() {
		return &this->operator*();
	}
private:
	StrBlobPtr* str_blob_ptr;
};
