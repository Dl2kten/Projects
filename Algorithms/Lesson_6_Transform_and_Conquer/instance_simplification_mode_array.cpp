#include <iostream>
#include <array>
#include <algorithm>

/*
* Transform and conquer
* Instance simplification, computing a mode
*/

/// <summary>
/// Computes the mode value of an array
/// </summary>
/// <param name="p_iarr"></param>
/// <returns>pair containg mode value and frequency</returns>
std::pair<unsigned, unsigned> presort_mode(std::array<int, 10>& p_iarr) {
	std::sort(p_iarr.begin(), p_iarr.end());
	unsigned mode_frequency = 0, run_length = 0, run_value = p_iarr.at(0),
		mode_value = p_iarr.at(0);

	for (decltype(p_iarr.size())i = 0; i != p_iarr.size(); ++i) {
		if (p_iarr.at(i) == run_value) {
			++run_length;
		}
		else {
			if (run_length > mode_frequency) {
				mode_frequency = run_length;
				mode_value = run_value;
			}
			run_value = p_iarr.at(i);
			run_length = 1;
		}
	}

	return std::make_pair(mode_value, mode_frequency);
}




int main() {
	std::array<int, 10> iarr = { 5, 1, 6, 7, 6, 5, 7, 6 }; //rest filled to 0

	auto mode = presort_mode(iarr);
	std::cout << "The mode value is: " << mode.first << " The frequency is: "
		<< mode.second << std::endl;

	return 0;
}