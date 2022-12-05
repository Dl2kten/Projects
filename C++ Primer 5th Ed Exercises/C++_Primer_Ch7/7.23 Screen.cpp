#include<iostream>

/*
* Exercise 7.23, 7.24
* Write the Screen class
* Write 3 constructors for Screen, default constructor, constructor that
* takes values for height and width and initializes the contents to 
* hold the given number of blanks, and a constructor that takes height,
* width, and a character to use as the contents of screen
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
		contents(ht * wd, c) {}

private:
	pos cursor = 0;
	pos height = 0;
	pos width = 0;
	string contents;
};


int main() {

	

	return 0;
}