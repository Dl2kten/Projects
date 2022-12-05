#include <iostream>
#include <algorithm>
#include <vector>

/*
* Transform and conquer
* Representation change from array to heap
*/

void compare_switch_parent(const int, const int, const int, std::vector<int>&);

/// <summary>
/// Checks to see if after parent and child node switch, if there's a case
/// where the child node of the new child node is bigger in value, eg if 7
/// switched with 2, check to see if left or right child of 2 has bigger value,
/// if so need to switch
/// </summary>
/// <param name="p_child"></param>
/// <param name="p_ivec"></param>
void compare_switch_child(const int p_child, std::vector<int>& p_ivec) {
	const auto left = p_child * 2,
		right = p_child * 2 + 1;
	compare_switch_parent(p_child - 1, left, right, p_ivec);
}

/// <summary>
/// Switch parent node with largest child starting with rightmost node in 
/// lowest level
/// </summary>
/// <param name="p_e"></param>
/// <param name="p_left"></param>
/// <param name="p_right"></param>
/// <param name="p_ivec"></param>
void compare_switch_parent(const int p_e, const int p_left, const int p_right,
	std::vector<int>& p_ivec) {
	if (p_left <= p_ivec.size()) { //have left child?
		if (p_right <= p_ivec.size()) { //right?
			if (p_ivec[p_left - 1] <= p_ivec[p_right - 1] && p_ivec[p_e]
				< p_ivec[p_right - 1]) { //swap with largest child
				std::swap(p_ivec[p_e], p_ivec[p_right - 1]);
				
				//after swap compare the switched value to see if
				//there's child with value bigger than parent
				compare_switch_child(p_right,  p_ivec);
			}
		}

		if (p_ivec[p_e] < p_ivec[p_left - 1]) {
			std::swap(p_ivec[p_e], p_ivec[p_left - 1]);
			compare_switch_child(p_left, p_ivec);
		}

	}
}

/// <summary>
/// Changes collection of ints into heap structure
/// </summary>
/// <param name="p_levels"></param>
/// <param name="p_ivec"></param>
void construct_heap(int p_levels, std::vector<int>& p_ivec) {
	for (std::size_t i = 0, j = p_levels; j > 0; --j) {//compare starting with rightmost
		//parent node and its children

		while (i < j) {
			int e = pow(2, j) - (i + 1);

			//find left child and right child index
			const auto left = e * 2, right = e * 2 + 1;
			compare_switch_parent(e - 1, left, right, 
				p_ivec);
			
			++i;
		}

		i = 0; //reset i, i value used to process all parent nodes of the level
	}
}

/// <summary>
/// Sorts heap into ordered collection of ints, in this case contained in vector
/// </summary>
/// <param name="p_ivec"></param>
/// <returns>vector<int> copy</returns>
std::vector<int> remove_max(std::vector<int> p_ivec) {
	std::swap(p_ivec[0], p_ivec[p_ivec.size() - 1]); //switch root and
	//rightmost leaf
	std::vector<int> ret, ret2;
	ret.push_back(p_ivec[p_ivec.size() - 1]);
	
	p_ivec.pop_back();//delete last element
	
	
	if (p_ivec.size() > 0) {
		int levels = log2(p_ivec.size());
		construct_heap(levels, p_ivec); //reorder elements 
		//to proper heap
		ret2 = remove_max(p_ivec);
	}
	
	ret.insert(ret.end(), ret2.begin(), ret2.end());
	return ret;
}

/// <summary>
/// Sorts vector<int> using heap sort
/// </summary>
/// <param name="p_ivec"></param>
void heap_sort(std::vector<int>& p_ivec) {
	int levels = log2(p_ivec.size()); 
	construct_heap(levels, p_ivec);
	p_ivec = remove_max(p_ivec);
}

/// <summary>
/// Prints elements of vector<int>
/// </summary>
/// <param name="p_ivec"></param>
void print(const std::vector<int>& p_ivec) {
	for (auto& i : p_ivec)
		std::cout << i << " ";
	std::cout << std::endl;
}



int main() {
	
	std::vector<int> ivec{ 2, 9, 7, 6, 5, 8 };
	print(ivec);
	heap_sort(ivec);
	print(ivec);

	return 0;
}