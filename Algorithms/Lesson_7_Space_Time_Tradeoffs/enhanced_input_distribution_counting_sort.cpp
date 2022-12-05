#include <iostream>
#include <vector>

/*
* Space and time tradeoffs
* Input enhancement, preprocess input to store some info
* Distribution counting sort
*/

/// <summary>
/// This is like the counting sort using frequency and cumulative sum I've 
/// found on line, there were a couple of similar but slightly different 
/// implementations online, this one too is slightly different using k as 
/// difference between max and min, is this an optimization? online ones just
/// set range to be known or k = max + 1
/// time complexity very good 0(n) but range of input needs to be in similar
/// range to number of input elements or else possible for k to be n^2 or above
/// in which case O is equivalent to n^2 or above
/// </summary>
/// <param name="p_ivec"></param>
void distribution_counting_sort(std::vector<int>& p_ivec) {
	int max = p_ivec[0], min = p_ivec[0], k = 0; //k is size of vector used
	//to store frequency of occuring elements in p_ivec, the algorithm examples
	//all called it k

	for (const auto& i : p_ivec) {
		if (i > max)
			max = i;
		if (i < min)
			min = i;
	}

	k = max - min + 1;
	std::vector<int> element_frequency(k);//all elements 0

	//counts frequency of each element
	for (std::vector<int>::size_type i = 0; i != p_ivec.size(); ++i) {
		element_frequency[p_ivec[i] - min] = element_frequency[p_ivec[i] - min]
			+ 1;
	}

	//compute cumulative sum add frequency of left and right pair together
	for (std::vector<int>::size_type j = 1; j != k; ++j) {
		element_frequency[j] += element_frequency[j - 1];
	}

	std::vector<int> sorted(p_ivec.size()); //contains sorted values
	for (int i = p_ivec.size() - 1; i >= 0; --i) {
		auto j = p_ivec[i] - min;
		sorted[element_frequency[j] - 1] = p_ivec[i];
		element_frequency[j] = element_frequency[j] - 1;//after assigning
		//decrement original value by 1
	}

	p_ivec = sorted;
}


/// <summary>
/// prints elements of vector
/// </summary>
/// <param name="p_ivec"></param>
void print(const std::vector<int>& p_ivec) {
	for (auto& i : p_ivec)
		std::cout << i << " ";
	std::cout << std::endl;
}


int main() {
	std::vector<int> ivec{ 4, 1, 3, 4, 3 };

	print(ivec);
	distribution_counting_sort(ivec);
	print(ivec);

	return 0;
}