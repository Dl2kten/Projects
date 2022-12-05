#include<iostream>
#include<vector>

/*
* Exercise 5.20
* Read in strings until same word occurs twice consecutively or all
* words read, use while loop, use break to stop if same word occurs,
* print that word or that no word was repeated
*/

using namespace std;

int main() {


	/*
	* 5.20
	* string s for input, sTemp for comparison
	* read in using while
	* break if same word occurs twice
	*/

	string s, sTemp;

	//user prompt
	cout << "Please enter words to be read, same word occuring twice "
		<< "will end program (enter 0 to end program): " << endl;

	while (cin >> s && s != "0") {
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