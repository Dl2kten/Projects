#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<functional>
#include<list>
#include<deque>

/*
* Exercise 10.28
* Copy a vector that holds the values from 1-9 into three other
* containers, use inserter, back_inserter, front_inserter
*/

using std::cout;
using std::cin;
using std::endl;

/*
* Function print, prints elements in container
* param int
* return void
*/
void print(int a) {
	cout << a << " ";
}

int main() {

	std::vector<int> ivec{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::vector<int> ivec2;
	std::list<int> ilist;
	std::deque<int> idq;

	std::copy(ivec.begin(), ivec.end(), std::back_inserter(ivec2));
	std::copy(ivec.begin(), ivec.end(), 
		std::inserter(ilist, ilist.begin()));
	std::copy(ivec.begin(), ivec.end(), std::front_inserter(idq));

	std::for_each(ivec2.begin(), ivec2.end(), print);
	cout << endl;
	std::for_each(ilist.begin(), ilist.end(), print);
	cout << endl;
	std::for_each(idq.begin(), idq.end(), print);
	cout << endl;


	return 0;
}