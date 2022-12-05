#include<iostream>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<algorithm>


/*
* Exercise 11.20
* Rewrite to use insert instead of subscripting
*/

using std::cout;
using std::cin;
using std::endl;

/*
* Function changeWord, eliminates punctuation and transforms to lowercase
* param std::string&
* return void
*/
void changeWord(std::string& s) {
	std::string punctuation{ ",.?!:;\"\'()" };
	std::string::size_type pos = 0;

	while ((pos = s.find_first_of(punctuation, pos))
		!= std::string::npos) {
		s.erase(s.begin() + pos);
	}

	std::transform(s.begin(), s.end(), s.begin(), ::tolower);
	/*
	* hmm maybe a for loop and check for capital letters and continue
	* might be faster?
	*/
}

int main() {

	std::map<std::string, size_t> words_count;
	std::set<std::string> exclude{ "The", "And", "But", "Or", "the",
	"and", "but", "or" };
	std::string word;

	while (cin >> word) {
		changeWord(word);
		if (exclude.find(word) == exclude.end()) {
			auto present = words_count.insert({ word, 1 });
			if (!present.second)
				++present.first->second;
		}
	}

	for (const auto& i : words_count)
		cout << i.first << " occurs " << i.second
		<< ((i.second > 1) ? " times.\n" : " time.\n");
	cout << endl;

	return 0;
}