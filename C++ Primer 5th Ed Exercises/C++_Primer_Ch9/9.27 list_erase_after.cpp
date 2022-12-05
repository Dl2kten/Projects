#include<iostream>
#include<vector>
#include<list>
#include<string>
#include <deque>
#include <forward_list>

/*
* Exercise 9.27
* Write a program to find and remove the odd-valed elements in a
* forward_list<int>
*/

using std::cout;
using std::cin;
using std::endl;

int main() {

	std::forward_list<int> ifl = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };

	std::forward_list<int>::iterator prev = ifl.before_begin();
	std::forward_list<int>::iterator curr = ifl.begin();

	while (curr != ifl.end()) {
		if (*curr % 2 == 1)
			//set curr to equal element after erase_after
			curr = ifl.erase_after(prev);
		else {
			prev = curr++;//increase prev and curr
		}

	}

	for (const auto& i : ifl)
		cout << i << " ";
	cout << endl;

	return 0;
}