#include <iostream>
#include <vector>

/*
* Selection sort
* use selection sort on vector of ints
*/

/// <summary>
/// sorts vector<int> into ascending order using selection sort
/// </summary>
/// <param name="p_ivec"></param>
void selection_sort(std::vector<int>& p_ivec) {
	for (std::vector<int>::size_type i = 0; i < p_ivec.size() - 1; ++i) {
		int min = i;
		for (auto j = i + 1; j < p_ivec.size(); ++j) {
			if (p_ivec[j] < p_ivec[min])
				min = j;
		}

		std::swap(p_ivec[i], p_ivec[min]);
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
	selection_sort(ivec);
	print(ivec);

	//O(n^2)
	return 0;
}