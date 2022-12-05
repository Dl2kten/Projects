#include <iostream>
#include <vector>

/*
* Decrease by half
* Binary Search iterative implementation
*/

/// <summary>
/// binary search for a vector<int>
/// </summary>
/// <param name="p_ivec"></param>
/// <param name="key"></param>
/// <returns></returns>
int binary_search(const std::vector<int>& p_ivec, const int key) {
	auto first = p_ivec.begin(),
		last = p_ivec.end();
	while (first <= last) {
		auto mid = first + (last - first) / 2;
		if (key > *mid) {
			first = mid + 1;
		}
		else if (key < *mid) {
			last = mid - 1;
		}
		else {
			return mid - p_ivec.begin();
		}
	}

	return -1; //if not found
}


int main() {
	std::vector<int> ivec{ 6, 7, 9, 9, 13, 17, 22, 25, 41, 43, 47, 61, 62, 64,
		78, 81, 88, 90, 91, 92, 93 };
	int index = binary_search(ivec, 81);
	std::cout << (index >= 0 ? ivec[index] : -1) << std::endl;
	index = binary_search(ivec, 22);
	std::cout << (index >= 0 ? ivec[index] : -1) << std::endl;
	
	return 0;
}