#include<iostream>
#include<vector>

/*
* Exercise 7.32
* Define own version of class Screen and Class Wndow_mgr, clear is a
* member of Window_mgr and a friend of Screen
*/

using namespace std;

/*
* Interdependancies important
* - Window_mgr with clear declaration
* - Screen with friend clear
* - clear
*/

class Screen;
/*
* Class Window_mgr
*/
class Window_mgr {
public:
	using ScreenIndex = vector<Screen>::size_type;

	/*
	* From online answers, this counts as special member function(?),
	* still a constructor? If =default then gets compiler error, maybe
	* just define a constructor that takes a screen object and add to
	* screens, can't Screen undefined
	*/
	Window_mgr();
	//Window_mgr(Screen si) : screens(0, si) {}
	void clear(ScreenIndex);

private:
	vector<Screen> screens;//Screen undefined, can't initialize
};

/*
* Class Screen
*/
class Screen {
	friend void Window_mgr::clear(ScreenIndex);
public:
	using pos = string::size_type;

	//constructors
	Screen() = default;
	Screen(pos ht, pos wd, pos blanks) : height(ht), width(wd),
		contents(blanks, ' ') {}
	Screen(pos ht, pos wd, char c) : height(ht), width(wd),
		contents(ht* wd, c) {}

private:
	pos cursor = 0;
	pos height = 0;
	pos width = 0;
	string contents;
};

/*
* Function clear, clears Screen
*/
void Window_mgr::clear(ScreenIndex si) {
	Screen& s = screens[si];
	s.contents = string(s.height * s.width, ' ');
}

//Can just add element like this? From online answers
Window_mgr::Window_mgr() : screens{ Screen(24, 80, ' ') } {};

int main() {
	Window_mgr wm;
	wm.clear(0);

	return 0;
}