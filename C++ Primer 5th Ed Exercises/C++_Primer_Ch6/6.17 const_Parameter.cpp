#include<iostream>


/*
* Exercise 6.17
* Write one function to determine whether a string contains any capital
* letters, another function to change a string to all lowercase
*/

using namespace std;

/*
* Capital function
* const ref parameter
* returns true if there's a capital letter
*/
bool isCapital(const string& s) {
	for (decltype(s.size()) i = 0; i != s.size(); ++i) {
		if (isupper(s[i]))
			return true;
	}

	return false;
}

/*
* Lowercase function
* non const ref parameter, change all letters to lower
*/
void toLowerCase(string& s) {
	for (decltype(s.size()) i = 0; i < s.size(); ++i) {
		s[i] = tolower(s[i]);
	}
}



int main() {

	string word;
	//user prompt
	cout << "Please enter a word to be checked for any capitals and "
		"to be changed to all lowercase." << endl;
	cin >> word;

	cout << (isCapital(word) ? "There are one or more capital "
		"letters." : "There are no capital letters.") << endl;

	toLowerCase(word);
	cout << "\nThe word entered in all lower case is: " << word << endl;

	/*
	* Need non const for lowercase function as we want to change the
	* string, issues with isupper and tolower?
	*/

	return 0;
}

