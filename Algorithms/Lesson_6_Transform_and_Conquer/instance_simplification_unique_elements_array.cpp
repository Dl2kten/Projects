#include <iostream>
#include <array>
#include <algorithm>

/*
* Transform and conquer
* Instance simplification
*/

/// <summary>
/// Checks given array for unique elements
/// </summary>
/// <param name="p_iarr"></param>
/// <returns></returns>
bool presort_element_uniqueness(std::array<int, 10>& p_iarr) {
	std::sort(p_iarr.begin(), p_iarr.end()); //nlogn

	for (decltype(p_iarr.size())i = 0; i != p_iarr.size() - 1; ++i) {
		if (p_iarr.at(i) == p_iarr.at(i + 1))
			return false;
	}

	return true;
}



int main() {
	std::array<int, 10> iarr = { 32, 234, 1, 151, 135, 152, 51, 2, 3 };
	//last element is 0
	std::cout << std::boolalpha << presort_element_uniqueness(iarr)
		<< std::noboolalpha << std::endl;

	return 0;
}