#include <iostream>
#include <vector>

/*
* Bubble sort
* use bubble sort on vector of ints
*/

/// <summary>
/// sorts vector<int> into ascending order using bubble sort, moves largest
/// value to end each iteration
/// </summary>
/// <param name="p_ivec"></param>
void bubble_sort(std::vector<int>& p_ivec) {
	for (std::vector<int>::size_type i = 0; i < p_ivec.size() - 1; ++i) {
		for (auto j = 0; j < p_ivec.size() - 1 - i; ++j) {
			if (p_ivec[j + 1] < p_ivec[j])
				std::swap(p_ivec[j + 1], p_ivec[j]);
		}
	}
}

/// <summary>
/// prints contents of vector<int>
/// </summary>
/// <param name="p_ivec"></param>
void print(const std::vector<int>& p_ivec) {
	for (auto& i : p_ivec)
		std::cout << i << " ";
	std::cout << std::endl;
}

int main() {
	std::vector<int> ivec{ 2, 4, 3, 1, 5, 1, 6, 3, 0, 2 };
	print(ivec);
	bubble_sort(ivec);
	print(ivec);


	//O(n^2)
	return 0;
}