#include <iostream>
#include <vector>

/*
* Divide and conquer
* Merge sort
*/

using iter = std::vector<int>::iterator;

/// <summary>
/// merges two mergesorted sequences
/// </summary>
/// <param name="beg1"></param>
/// <param name="beg2"></param>
/// <param name="end2"></param>
/// <param name="p_ivec"></param>
void merge(iter beg1, iter beg2, iter end,
	std::vector<int>& p_ivec) {
	auto merged_iter = beg1;
	while (beg1 != end) { //before had && beg2 != end but there was a case
		//where beg2 == end2 but not at one past last element so changed to
		if (beg2 == p_ivec.end() || beg1 == beg2) //this, also case where
		//beg1 actually increments past beg2
			break;

		if (*beg1 <= *beg2) {
			if(*beg1 <= *(beg1 + 1))
				++beg1;
			else { //another case...
				auto temp = *beg1;
				auto temp_next = *(beg1 + 1);
				*beg1 = temp_next;
				*++beg1 = temp;
			}
		}
		else {
			auto temp_value = *beg1;
			auto temp_next_value = *(beg1 + 1);
			*merged_iter = *beg2;
			++beg2;
			*++beg1 = temp_value;
			auto curr = beg1;
			//auto next = beg1 + 1;
			
			while (curr != (beg2-1)) {
				temp_value = temp_next_value;
				if ((curr + 1) != p_ivec.end())
					temp_next_value = *(curr + 1);
				*++curr = temp_value;
			}

		}
		++merged_iter;
	}

	

}


void merge_sort(iter beg, iter end, std::vector<int>& ivec) {
	
	if ((end - beg) > 1) {
		std::size_t diff = std::round((end - beg) / 2.0);//need to know odd/even
		auto i = (end - beg) / 2.0;
		auto mid = beg + diff;
		merge_sort(beg, mid, ivec);
		merge_sort(mid, end, ivec);

		
		beg = mid - diff;
		merge(beg, mid, end, ivec);
	}
}


void print(const std::vector<int>& p_ivec) {
	for (auto& i : p_ivec)
		std::cout << i << " ";
	std::cout << std::endl;
}

int main() {

	std::vector<int> ivec{ 99, 6, 86, 15, 58, 35, 86, 4, 0, 1 };
	
	print(ivec);
	auto begin = ivec.begin(), end = ivec.end();
	merge_sort(begin, end, ivec);//needs lvalue
	print(ivec);
	//passing ivec to the merge functions really helped with keeping track
	//of the elements, also used to compare with vector end, seems to be
	//working but could have other cases that spring up already had like 5+
	//different cases
	return 0;
}