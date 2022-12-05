#include<iostream>
#include<string>
#include<vector>
#include<cctype>

/*
* Exercise 3.3.2
* 3.20 vector of ints, print sum of adjacent elements,
* print sum of first and last, second and second last, etc.
*/

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::toupper;

int main() 
{

	vector<string> words;
	string s1;
	//user prompt
	cout << "Please enter some words: " << endl;

	while (cin >> s1) {
		words.push_back(s1);
	}

	int wordsLine = 0;//counts how many words per line

	for (auto& i : words) {//i is reference to string
		for (auto& c : i) {//c is reference to char
			c = toupper(c);
		}
		if (wordsLine < 7) {//first seven words
			cout << i << " ";
			++wordsLine;
		}
		else {//last word, ends line, change wordsLine to 0
			cout << i << endl;
			wordsLine = 0;
		}
	}//outer for loop*/
	return 0;
}