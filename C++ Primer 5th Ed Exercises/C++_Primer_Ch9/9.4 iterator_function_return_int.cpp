#include<iostream>
#include<vector>
/*
* Exercise 9.4, 9.5
* Function that takes a pair of iterators to a vector<int> and an
* int value, look for that value in the range and return a bool
* Return an iterator to the requested element instead, must handle case
* where the element is not found
*/

/*
* Function findInt finds if a particular int value is within a vector of
* ints
* param two iterators, one int
* return bool
*/
bool findInt(std::vector<int>::const_iterator beg,
	std::vector<int>::const_iterator end, int i) {
	for (auto it = beg; it != end; ++it) {
		if (*it == i)
			return true;
	}

	return false;
	/*
	* First I initialized a vector<int>, but can use iterators as they
	* are
	*/
}

/*
* Function findIterator finds the iterator whose dereference value equals
* to a specified int value
* param two iterators, one int
* return iterator
*/
std::vector<int>::const_iterator findIterator(
	std::vector<int>::const_iterator beg,
	std::vector<int>::const_iterator end, int i) {

	for (auto it = beg; it != end; ++it) {
		if (*it == i)
			return it;
	}

	return end;
}

int main() {

	std::vector<int> vi = { 1, 2, 5, 6, 7 };

	bool find = findInt(vi.cbegin(), vi.cend(), 7);
	std::cout << (find ? "true" : "false") << std::endl;

	std::vector<int>::const_iterator ci = findIterator(vi.begin(),vi.end(), 4);

	std::cout << "The iterator for the int value "
		<< (ci == vi.cend() ? "does not exist." : "exist.") 
		<< std::endl;

	/*
	* can also print its position by subtracting begin
	*/

	return 0;
}