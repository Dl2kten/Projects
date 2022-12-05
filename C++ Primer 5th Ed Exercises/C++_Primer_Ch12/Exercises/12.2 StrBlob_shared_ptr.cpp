#include<iostream>
#include<memory>
#include <vector>

/*
* Exercise 12.2
* Write own version of StrBlob class
*/

using std::cout;
using std::cin;
using std::endl;

/*
* class StrBlob for managing strings
*/
class StrBlob {
public:
	using sz = std::vector<std::string>::size_type;
	friend void print(const StrBlob& s);
	StrBlob();
	StrBlob(std::initializer_list<std::string> sil);

	sz size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	void push_back(const std::string& s) { data->push_back(s); }
	void pop_back();

	std::string& front();
	const std::string& front() const;
	std::string& back();
	const std::string& back() const;

private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(sz i, const std::string& msg) const;
};

/*
* Default constructor
*/
StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}

/*
* Constructor taking initializer list
*/
StrBlob::StrBlob(std::initializer_list<std::string> sil) : data
(std::make_shared<std::vector<std::string>>(sil)) {}

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
const std::string& StrBlob::back() const{
	check(0, "const back on empty StrBlob");
	return data->back();
}
/*
* Function print, prints elements
* param const StrBlob&
* return void
*/
void print(const StrBlob& s) {
	if (s.size() > 0) {
		for (const auto& i : *s.data)
			cout << i << " ";
		cout << endl;
	}
	else {
		cout << "StrBlob empty." << endl;
	}
	
}


int main() {

	StrBlob sb1({ "a", "b", "c", "d", "e" });
	StrBlob sb2;
	print(sb1);
	print(sb2);
	sb1.push_back("f");
	sb2.push_back("f");
	print(sb1);
	print(sb2);
	sb1.pop_back();
	sb2.pop_back();
	print(sb1);
	print(sb2);
	cout << sb1.front() << " " << sb1.back() << endl;
	//cout << sb2.front();

	/*
	* pros of non explicit second constructor is that can initialize
	* and assign using = {...}, and can use initializer list in params
	* that require a StrBlob object, cons are if unintended implicit
	* creations of StrBlob object
	*/
	return 0;
}


