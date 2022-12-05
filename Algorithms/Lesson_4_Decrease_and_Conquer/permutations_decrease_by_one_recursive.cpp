#include <iostream>
#include <vector>

/*
* Decrease by 1
* Generating permutation using recursion
*/

/// <summary>
/// Generates all permutations of a set of given letters
/// </summary>
/// <param name="p_svec"></param>
/// <param name="n"></param>
/// <returns></returns>
std::vector<std::string> generate_permutation(std::vector<std::string>& p_svec, std::size_t n) {
	std::vector <std::string> ret;
	
	if (n > 1)
		ret = generate_permutation(p_svec, n - 1);
	else
		return std::vector<std::string>{p_svec[n - 1]};
	
	std::vector < std::string> temp; //since
	for (std::size_t i = 0; i < ret.size(); ++i) {
		for (std::size_t j = 0; j < n; ++j) { //add letter to make new permutation
			std::string string_permutation(n, ' '); //empty string of size n

			//take ab for example want to add c to cab, acb, abc, need to move
			//chars, should be separate function?
			for (std::size_t k = 0; k < ret[i].size(); k++) {
				if (k >= j) 
					string_permutation[k + 1] = ret[i][k];
				else
					string_permutation[k] = ret[i][k];
			}
			string_permutation[j] = p_svec[n - 1][0]; //place c in right place

			temp.push_back(string_permutation);
		}
	}

	return temp;
	
}

/// <summary>
/// prints contents of vector<string>
/// </summary>
/// <param name="p_svec"></param>
void print(const std::vector<std::string>& p_svec) {
	for (auto& i : p_svec)
		std::cout << i << " ";
	std::cout << std::endl;
}

int main() {
	
	std::vector<std::string> svec{ "A", "B", "C", "D"};
	svec = generate_permutation(svec, svec.size());
	print(svec);

	return 0;
}