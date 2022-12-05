#include<iostream>
#include<vector>
#include<list>
#include<string>
#include <deque>
#include <forward_list>

/*
* Exercise 9.33, 9.34
* Write a program to omit assigning the result of insert to begin and
* see results
* Test text code and correct
*/

using std::cout;
using std::cin;
using std::endl;


int main() {

	std::vector<int> v{1, 2, 3, 4};
	auto begin = v.begin();

	while (begin != v.end()) {
		
		++begin; // advance begin because we want to insert after this element
		begin = v.insert(begin, 42); // insert the new value
		++begin; // advance begin past the element we just added
	}

	for (const auto& i : v) {
		cout << i << " ";
	}

	/*
	* if not assign it would be error as there's reallocation for 
	* vector
	*/

	//9.34
	std::vector<int> vi{ 1, 2, 3, 4 };

	auto iter = vi.begin();
	while (iter != vi.end()) {
		if (*iter % 2) {
			iter = vi.insert(iter, *iter);
			++iter; 
			++iter;//added as insert returns iter to element added
		}
		else
			++iter;//account for case where element not odd
	}
	/*
	* Needed to add the changes above denoted by comments
	*/
	return 0;
}