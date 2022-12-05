#include<iostream>
#include<vector>
#include<list>
#include<string>
#include <deque>



/*
* Exercise 9.26
* Copy ia into a vector and into a list, use the single-iterator form of
* erase to remove elements with odd values from your list and even values
* from your vector
*/

using std::cout;
using std::cin;
using std::endl;

int main() {

	int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };

	std::vector<int> ivec;
	std::list<int> ilist;

	for (const auto& i : ia) {
		ivec.push_back(i);
		ilist.push_back(i);
	}

	std::vector<int>::iterator vit = ivec.begin();
	std::list<int>::iterator sit = ilist.begin();
	
	while (vit != ivec.end()) {
		if (*vit % 2 == 0) {//even
			vit = ivec.erase(vit);
			++sit;//increase ilist interator to next
		}
		else {
			sit = ilist.erase(sit);
			++vit;//increase ivec iterator to next
		}
	}

	for (const auto& i : ivec)
		cout << i << " ";
	cout << endl;

	for (const auto& i : ilist)
		cout << i << " ";
	cout << endl;

	/*
	* can use begin(ia), end(ia) to copy into vector and list
	*/
	return 0;
}