#include <iostream>
#include <vector>
#include <math.h>
/*
* Decrease by 1
* Generate all subsets iterative implementation
*/

std::vector<std::string> generate_subsets(std::vector<std::string>& p_svec) {
	std::vector<std::string> ret{" "};
	for (std::size_t i = 0; i < p_svec.size(); ++i) {
		std::vector<std::string> temp(ret);
		for (std::size_t j = 0; j < pow(2, i); ++j) {//doubles
			//every time
			if (ret[j] == " ")
				temp.push_back(p_svec[i]);
			else
				temp.push_back(ret[j] + p_svec[i]);
		}

		ret = temp;
	}

	return ret;
}


/// <summary>
/// prints vector<int> elements
/// </summary>
/// <param name="p_svec"></param>
void print(const std::vector<std::string>& p_svec) {
	for (auto& i : p_svec)
		std::cout << i << " ";
	std::cout << std::endl;
}

int main() {

	std::vector<std::string> svec{ "A", "B", "C", "D"};
	svec = generate_subsets(svec);
	print(svec);
	return 0;
}