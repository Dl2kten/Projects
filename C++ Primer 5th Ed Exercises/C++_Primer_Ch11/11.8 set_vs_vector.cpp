#include<iostream>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<vector>
#include<sstream>

/*
* Exercise 11.8
* Write a program that stores excluded words in a vector instead of set,
* what are advantages of set
*/

using std::cout;
using std::cin;
using std::endl;



int main() {

	std::map<std::string, size_t> words_count;
	std::vector<std::string> exclude{ "The", "And", "But", "Or", "the",
	"and", "but", "or" };
	std::string word;

	while (cin >> word) {
		//if (exclude.find(word) == exclude.end())
			//++words_count[word];
		if (std::find(exclude.cbegin(), exclude.cend(), word) ==
			exclude.end())
			++words_count[word];
	}

	for (const auto& i : words_count)
		cout << i.first << " occurs " << i.second
		<< ((i.second > 1) ? " times.\n" : " time.\n");
	cout << endl;

	/*
	* set has own find, also removes duplicates, not applicable here but 
	* online answers
	*/
	return 0;
}