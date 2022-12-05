#include <iostream>
#include <vector>

/*
* Space and time tradeoffs
* Input enhancement, preprocess input to store some info
* Comparison Counting sort
*/

/// <summary>
/// Sort a collection of ints by counting how many elements each element is
/// bigger than, time complexity O(n^2)
/// </summary>
/// <param name="p_ivec"></param>
void comparison_counting_sort(std::vector<int>& p_ivec) {
	std::vector<int> count(p_ivec.size()), output(p_ivec.size());

	//count how many elements each element is bigger than
	for (decltype(p_ivec.size()) i = 0; i != p_ivec.size() - 1; ++i) {
		for (auto j = i + 1; j != p_ivec.size(); ++j) {
			if (p_ivec[i] < p_ivec[j]) {
				count[j]++;
			}
			else {
				count[i]++;
			}
		}
	}

	//order elements to their right place
	for (decltype(p_ivec.size()) i = 0; i != p_ivec.size(); ++i) {
		output[count[i]] = p_ivec[i];//p_ivec[i]'s right place is index returned
		//from count[i]
	}

	p_ivec = output;
}

/// <summary>
/// prints elements in a vector
/// </summary>
/// <param name="p_ivec"></param>
void print(const std::vector<int>& p_ivec) {
	for (auto& i : p_ivec)
		std::cout << i << " ";
	std::cout << std::endl;
}


int main() {
	std::vector<int> ivec{ 121, 9106, 213, 7185, 6, 9978, 6111, 43, 8290, 136 };

	print(ivec);
	comparison_counting_sort(ivec);
	print(ivec);

	return 0;
}