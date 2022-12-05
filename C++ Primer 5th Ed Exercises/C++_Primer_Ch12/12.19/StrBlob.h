#pragma once
#include<memory>
#include<string>
#include<vector>

class StrBlobPtr;
class ConstStrBlobPtr;
/*
* class StrBlob for managing strings
*/
class StrBlob {
public:
	using sz = std::vector<std::string>::size_type;
	friend void print(const StrBlob& s);
	friend class StrBlobPtr;
	friend class ConstStrBlobPtr;
	StrBlob();
	StrBlob(std::initializer_list<std::string> sil);
	StrBlob(const StrBlob& a) :
		data(std::make_shared<std::vector<std::string>>(*a.data)) {}
	StrBlob& operator=(const StrBlob&);
	sz size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	void push_back(const std::string& s) { data->push_back(s); }
	void pop_back();

	std::string& front();
	const std::string& front() const;
	std::string& back();
	const std::string& back() const;
	StrBlobPtr begin();
	StrBlobPtr end();
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(sz i, const std::string& msg) const;
};
