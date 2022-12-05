#include<iostream>
#include<vector>
#include<list>
#include<string>
#include <deque>
#include <forward_list>

/*
* 9.43
* Write a function that takes three strings, s, oldVal, newVal, using
* iterators and the insert and erase functions replace all instances of
* oldVal that appear in s by newVal, test by replacing common 
* abbreviations as tho by though and thru by through
*/

using std::cout;
using std::cin;
using std::endl;

/*
* Function replaceWord, replaces certain words with others
* param, three string
* return void
*/
void replaceWord(std::string& s, const std::string& oldVal,
	const std::string& newVal) {

	auto begin = s.begin();
	bool match = true;

	while (begin != s.end()) {
		if (*begin == *(oldVal.begin())) {//the char match
			
			for (auto ob = oldVal.begin();
				ob != oldVal.end(); ++ob, ++begin) {//compare rest of chars
				if (*begin != *ob) {
					match = false;
					break;
				}
			}//end of inner for

			if (match) {//erase and add
				begin -= oldVal.size();
				begin = s.erase(begin, begin + oldVal.size());
				begin = s.insert(begin, newVal.begin(),
					newVal.end());
				++begin;
			}
			else {
				++begin;
				match = true;
			}
		}
		else {
			++begin;
		}
	}


}

int main() {
	
	std::string str{ "I tho thru a tho though." };

	replaceWord(str, "tho", "though");
	cout << str << endl;

	replaceWord(str, "thru", "through");
	cout << str << endl;

	/*
	* Program doesn't consider words that contain the oldVal, like
	* if you had though as a word it would give thoughugh
	*/
	return 0;
}