#include <iostream>

/*
* Exercise 19.11, 19.12, 19.13
* What is the difference between an ordinary data pointer and a pointer to a
* data member
* Define a pointer to member that can point to the cursor member of class 
* Screen, fetch the value of Screen::cursor through that pointer
* Define the type that can represent a pointer to the bookNo member of the
* Sales_data class
*/
class Screen {
public:
	typedef std::string::size_type pos;
	//char get_cursor() const { return contents[cursor]; }
	char get() const { }
	char get(pos ht, pos wd) const {}
	static const pos Screen::* get_pos_cursor() {
		return &Screen::cursor;
	}
private:
	std::string contents = " ";
	pos cursor = 0;
	pos height = 0, width = 0;
};

int main() {
	
	const std::string::size_type Screen::* posData = Screen::get_pos_cursor();
	Screen myScreen;
	std::cout << myScreen.*posData << std::endl;

	/*
	* A pointer to a data member is declared differently, type class::*, after
	* initializing with class member of specified type it still does not point
	* to data so need to deref and then be accessed by object of class
	* 19.13
	* const std::string Sales_data::* p_bookNo
	*/
	return 0;
}