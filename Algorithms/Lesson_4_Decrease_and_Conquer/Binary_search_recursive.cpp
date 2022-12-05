#include <iostream>
#include <vector>

/*
* Decrease by half
* Binary Search recursive implementation
*/

/// <summary>
/// binary search for a vector<int>
/// </summary>
/// <param name="p_ivec"></param>
/// <param name="key"></param>
/// <returns></returns>
int binary_search(const std::vector<int>::const_iterator& first, 
	const std::vector<int>::const_iterator& last, const int key) {

	auto mid = first + (last - first) / 2;
	if (key > *mid) {
		return binary_search(mid + 1, last, key);;
	}
	else if (key < *mid) {
		return binary_search(first, mid - 1, key);
	}
	else {
		return *mid;
	}

	return -1;
}


int main() {
	std::vector<int> ivec{ 6, 7, 9, 9, 13, 17, 22, 25, 41, 43, 47, 61, 62, 64,
		78, 81, 88, 90, 91, 92, 93 };
	int index = binary_search(ivec.cbegin(), ivec.cend(), 81);
	std::cout << (index >= 0 ? index : -1) << std::endl;
	index = binary_search(ivec.cbegin(), ivec.cend(), 22);
	std::cout << (index >= 0 ? index : -1) << std::endl;
	
	return 0;
}