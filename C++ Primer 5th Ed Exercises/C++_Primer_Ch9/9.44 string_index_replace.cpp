#include<iostream>
#include<vector>
#include<list>
#include<string>
#include <deque>
#include <forward_list>

/*
* Exercise 9.44
* Rewrite replaceWord using index and replace
*/
using std::cout;
using std::cin;
using std::endl;

/*
* Function indexReplaceWord, replaces certain words with others
* param, three string
* return void
*/
void indexReplaceWord(std::string& s, const std::string& oldVal,
	const std::string& newVal) {
	bool match = true;

	std::string::size_type i = 0;
	while (i < s.size()) {
		if (s[i] == oldVal[0]) {//the char match
			auto j = i + 1;
			for (std::string::size_type k = 1; k < oldVal.size();
				++k, ++j) {//compare rest of chars
				if (s[j] != oldVal[k]) {
					match = false;
					break;
				}

			}//end of inner for

			if (match) {
				s.replace(i, oldVal.size(), newVal);
				i += newVal.size();
			}
			else {
				i = ++j;//missing increment here need to have increment in
				//all cases
				match = true;
			}
		}
		else {
			++i;
		}
	}

}

int main() {
	
	std::string str{ "I tho thru a tho." };

	indexReplaceWord(str, "tho", "though");
	cout << str << endl;

	indexReplaceWord(str, "thru", "through");
	cout << str << endl;

	/*
	* could've compare words using substr instead
	*/
	return 0;
}