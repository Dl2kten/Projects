#include<iostream>
#include<vector>
#include<list>
#include<string>
#include <deque>
#include <forward_list>

/*
* Exercise 9.31
* Revise the program from 9.3.6 to work on list and forward_list
*/

using std::cout;
using std::cin;
using std::endl;


int main() {
	//program from text book
	std::vector<int> vi = { 0,1,2,3,4,5,6,7,8,9 };
	auto iter = vi.begin(); 
	while (iter != vi.end()) {
		if (*iter % 2) {
			iter = vi.insert(iter, *iter); 
			iter += 2;
		}
		else
			iter = vi.erase(iter);
	}

	cout << "The contents of vector<int> is:\n";
	for (const auto& i : vi)
		cout << i << " ";
	cout << endl;

	//list
	std::list<int> ilist = { 0,1,2,3,4,5,6,7,8,9 };
	auto iter2 = ilist.begin();
	while (iter2 != ilist.end()) {
		if (*iter2 % 2) {//if odd, have remainder
			iter2 = ilist.insert(iter2, *iter2);
			++iter2;
			++iter2;
		}
		else
			iter2 = ilist.erase(iter2);
	}
	cout << "The contents of list<int> is:\n";
	for (const auto& i : ilist)
		cout << i << " ";
	cout << endl;

	//forward_list
	std::forward_list<int> iflist = { 0,1,2,3,4,5,6,7,8,9 };
	auto curr = iflist.begin();
	auto prev = iflist.before_begin();
	while (curr != iflist.end()) {
		if (*curr % 2) {//if odd, have remainder
			//need to insert after curr rather than prev as adding new
			//element
			curr = iflist.insert_after(curr, *curr);
			prev = curr++;
		}
		else {
			curr = iflist.erase_after(prev);
			prev = iflist.before_begin();
		}
	}
	cout << "The contents of forward_list<int> is:\n";
	for (const auto& i : iflist)
		cout << i << " ";
	cout << endl;
	return 0;
}