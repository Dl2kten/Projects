#pragma once
#include <vector>
#include <string>
#include <iostream>

template<unsigned, unsigned> class Screen;
template<unsigned H, unsigned W>
std::ostream& operator<<(std::ostream&, Screen<H, W>&);
template<unsigned H, unsigned W>
std::istream& operator>>(std::istream&, Screen<H, W>&);
/*
* Class Window_mgr
*/
class Window_mgr {
public:
	using Screen_size = Screen<10, 10>;
	using ScreenIndex = std::vector<Screen_size>::size_type;

	Window_mgr();
	/*
	Window_mgr(Screen_size si) {
		screens.push_back(si);
	}*/
	void clear(ScreenIndex);
	void print(std::ostream& os);
private:
	std::vector<Screen_size> screens;
};

template<unsigned H, unsigned W>
class Screen {

	friend void Window_mgr::clear(ScreenIndex);
	friend std::ostream& operator<< <>(std::ostream&, Screen<H, W>&);
	friend std::istream& operator>> <>(std::istream&, Screen<H, W>&);

public:
	using pos = std::string::size_type;

	//constructors
	Screen(char c = '*') :
		height(H), width(W), contents(height* width, c) {}

	const Screen& display(std::ostream& os) const;
	
private:
	void do_display(std::ostream& os) const;
	pos cursor = 0;
	pos height = 0;
	pos width = 0;
	std::string contents;
};

template<unsigned H, unsigned W>
inline void Screen<H, W>::do_display(std::ostream& os) const {
	for (decltype(contents.size()) i = 0; i != contents.size(); ++i) {
		os << contents[i];
		if ((i + 1) % width == 0 && i + 1 != contents.size())
			os << "\n";
	}
}

template<unsigned H, unsigned W>
inline const Screen<H, W>& Screen<H, W>::display(std::ostream& os) const {
	do_display(os);
	return *this;
}

/*
* Function clear, clears Screen
*/
void Window_mgr::clear(ScreenIndex si) {
	Screen_size& s = screens[si];
	s.contents = std::string(s.height * s.width, ' ');
}

/*
* Constructor for Window_mgr
*/
Window_mgr::Window_mgr() : screens{ Screen_size()} {};

/*
* Function print, prints screens
*/
void Window_mgr::print(std::ostream& os) {
	for (const auto& i : screens) {
		i.display(os);
	}
	std::cout << std::endl;
}


template<unsigned H, unsigned W>
inline std::ostream& operator<<(std::ostream& os, Screen<H, W>& s)
{
	s.display(os);
	return os;
}

template<unsigned H, unsigned W>
inline std::istream& operator>>(std::istream& is, Screen<H, W>& s)
{
	char ch;
	unsigned h, w;
	is >> h >> w >> ch;
	s.height = h;
	s.width = w;
	s.contents = std::string(h * w, ch);
	return is;
}