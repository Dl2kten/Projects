#include<iostream>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>

/*
* Exercise 11.12, 11.13
* Read a sequence of strings and ints, storing each into a pair,
* store the pairs in a vector
* Write three versions to create pair for the vector
*/

using std::cout;
using std::cin;
using std::endl;



int main() {

	std::vector<std::pair<std::string, int>> pvec;

	std::ifstream in("data.txt");
	if (!in) {
		std::cerr << "Couldn't open file." << endl;
		return -1;
	}

	std::string temp;
	while (getline(in, temp)) {
		std::istringstream iss(temp);
		std::string s1, s2;
		int i;
		iss >> s1 >> s2;
		i = std::stoi(s2);
		//pvec.push_back(std::pair<std::string, int>{ s1, i });
		//pvec.push_back(make_pair(s1, i));
		pvec.push_back({ s1, i });
	}

	for (const auto& p : pvec) {
		cout << p.first << " " << p.second << "\n";
	}
	cout << endl;

	return 0;
}