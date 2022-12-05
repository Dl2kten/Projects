#include<iostream>
#include<vector>

/*
* Exercise 5.21
* Revise 5.20 to only look for duplicates that start with an uppercase
* letter
*/

using namespace std;

int main() {


	/*
	* 5.21
	* string s, sTemp for comparison
	* read in to s
	* check if capital, store and if next is capital compare for equality
	*/

	string s, sTemp;

	//user prompt
	cout << "Please enter words to be read, same word occuring twice "
		<< "will end program (enter 0 to end program): " << endl;

	while (cin >> s && s != "0") {
		if (!isupper(s[0]))
			continue;

		if (s == sTemp) {
			cout << s << " has occured twice in succession." << endl;
			break;
		}

		sTemp = s;
	}

	if (s == "0")
		cout << "No repeating words." << endl;

	return 0;
}