#include<iostream>

/*
* Exercise 7.27
* Add the move, set, and display operations to Screen
*/

using namespace std;

/*
* Screen class, represents window on a display
*/
class Screen {
public:
	using pos = string::size_type;

	//constructors
	Screen() = default;
	Screen(pos ht, pos wd, pos blanks) : height(ht), width(wd),
		contents(blanks, ' ') {}
	Screen(pos ht, pos wd, char c) : height(ht), width(wd),
		contents(ht* wd, c) {}

	//functions
	Screen& set(char);
	Screen& set(pos, pos, char);
	Screen& move(pos, pos);
	Screen display(ostream& os) {
		do_display(os);
		return *this;
	}
	const Screen display(ostream& os) const{
		do_display(os);
		return *this;
	}

private:
	pos cursor = 0;
	pos height = 0;
	pos width = 0;
	string contents;

	void do_display(ostream& os) const { os << contents; }
};

/*
* Screen move function, moves cursor
*/
inline Screen& Screen::move(pos r, pos c) {
	pos row = r * width; //row location
	cursor = row + c; //cursor to column within that row
	return *this;
}

/*
* Screen set function, sets new value at cursor
* param char c
*/
inline Screen& Screen::set(char c) {
	contents[cursor] = c;//set the new value at cursor
	return *this;
}

/*
* Screen set function, sets new value at given position
* param pos, pos, char
*/
inline Screen& Screen::set(pos r, pos col, char c) {
	contents[r * width + col] = c;
	return *this;
}

int main() {
	Screen myScreen(5, 5, 'X');
	myScreen.move(4, 0).set('#').display(cout);
	cout << "\n";
	myScreen.display(cout);
	cout << "\n";

	return 0;
}