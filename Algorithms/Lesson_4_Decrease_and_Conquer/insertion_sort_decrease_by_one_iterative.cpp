#include <iostream>
#include <vector>

/*
* Decrease by 1
* Insertion sort using reiterative bottom up method
*/

/// <summary>
/// iterative insertion_sort to ascending order for vector<int>
/// </summary>
/// <param name="p_ivec"></param>
/// <param name="n"></param>
void insertion_sort(std::vector<int>& p_ivec) {
	for (std::size_t i = 1; i < p_ivec.size(); ++i) {
		int element = p_ivec[i];
		int j = i - 1;
		while (j >= 0 && p_ivec[j] > element) { //if element one before is bigger
			p_ivec[j + 1] = p_ivec[j]; //assign bigger to next element
			--j;
		}
		p_ivec[j + 1] = element; //since ordered once found index of sequence 
		//element is bigger than will no longer decrement j, so element will
		//be placed in right place
	}
}

/// <summary>
/// prints vector<int> elements
/// </summary>
/// <param name="p_svec"></param>
void print(const std::vector<int>& i_svec) {
	for (auto& i : i_svec)
		std::cout << i << " ";
	std::cout << std::endl;
}

int main() {
	
	std::vector<int> ivec{ 4, 1, 2, 3, 5, 9, 7, 8 };
	insertion_sort(ivec);

	print(ivec);

	return 0;
}