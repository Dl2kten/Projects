#include <iostream>
#include <vector>

/*
* Decrease by 1
* Insertion sort using recursive top down method
*/

void insertion_sort(std::vector<int>& p_ivec, std::size_t n) {
	int key, i;
	if (n > 1)
		insertion_sort(p_ivec, n - 1);
		
	key = p_ivec[n - 1];
	i = n - 2;

	while (i >= 0 && (p_ivec[i] > key)) {
		p_ivec[i + 1] = p_ivec[i];
		--i;
	}

	p_ivec[i + 1] = key;
}

int main() {
	std::vector<int> ivec{ 4, 1, 2, 3, 5, 9, 7, 8 };
	insertion_sort(ivec, ivec.size());

	for (const auto& i : ivec)
		std::cout << i;
	std::cout << std::endl;

	return 0;
}