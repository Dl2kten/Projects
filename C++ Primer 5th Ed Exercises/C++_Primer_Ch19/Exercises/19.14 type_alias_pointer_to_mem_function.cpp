#include <iostream>

/*
* Exercise 19.14, 19.15, 19.16, 19.17
* Is the text code legal, if so what does it do? If not, why?
* What is the difference between an ordinary funciton pointer and a pointer
* to a member function
* Write a type alias that is a synonym for a pointer that cna point to the 
* avg_price member of Sales_data
* Define a type alias for each distinct Screen member function type
*/
class Screen {
public:
	//19.17
	typedef std::string::size_type pos;
	using Action = Screen& (Screen::*)();
	using p_get = char(Screen::*)() const;
	using p_get_2param = char(Screen::*)(Screen::pos, Screen::pos) const;
	using p_get_cursor = const pos Screen::* (Screen::*)();
	char get_cursor() const { return contents[cursor]; }
	char get() const { return 0; }
	char get(pos ht, pos wd) const { return 0; }
	static const pos Screen::* get_pos_cursor() {
		return &Screen::cursor;
	}

	Screen& home() {}
	Screen& forward() {}
	Screen& back() {}
	Screen& up() {}
	Screen& down() {}
private:
	std::string contents = " ";
	pos cursor = 0;
	pos height = 0, width = 0;

	static Action Menu[];
};

int main() {

	//19.14
	auto pmf = &Screen::get_cursor;//type is char(Screen::*)
	//() const
	pmf = &Screen::get; //ok, same function type, resets pmf to point to get

	/*
	* 19.15
	* Need to declare pointer to member function with classname::*, need
	* to access with class object, and no implicit conversion from function 
	* to pointer
	* 19.16 double Sales_data::avg_price() const
	* using p_avg_price = double(Sales_data::*)() const;
	*/
	return 0;
}