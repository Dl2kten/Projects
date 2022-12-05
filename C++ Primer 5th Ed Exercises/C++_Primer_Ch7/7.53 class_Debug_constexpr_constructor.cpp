#include<iostream>
#include<vector>

/*
* Exercise 7.53
* Define own version of class Debug
*/

using namespace std;

/*
* Class Debug
*/
class Debug {
	bool hw;
	bool io;
	bool other;

public:
	constexpr Debug(bool b = false) : hw(b), io(b), other(b) {}
	constexpr Debug(bool h, bool i, bool o) : hw(h), io(i),
		other(o) {}
	constexpr bool any() { return hw || io || other; }
	void set_io(bool b) { io = b; }
	void set_hw(bool b) { hw = b; }
	void set_other(bool b) { hw = b; }
	constexpr bool get_hw() { return hw; }
	constexpr bool get_io() { return io; }
	constexpr bool get_other() { return other; }
};

int main() {

	Debug db;
	Debug db2(true, false, false);

	return 0;
}