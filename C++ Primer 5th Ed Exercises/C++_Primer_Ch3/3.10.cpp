#include<iostream>
#include<string>

/*
* Exercises 3.2.3
* 3.10 Remove punctuation from string
*/

//namespaces
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() 
{
	string s1;

	//user prompt
	cout << "Please enter a string: " << endl;

	cin >> s1;

	cout << "Punctuations removed: " << endl;

	for (auto c : s1) {//go through string
		if (!ispunct(c))//if not punctuation print
			cout << c;
	}
	
	cout << endl;

	return 0;
}