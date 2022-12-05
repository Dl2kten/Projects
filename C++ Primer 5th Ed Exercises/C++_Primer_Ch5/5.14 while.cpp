#include<iostream>
#include<vector>

/*
* Exercise 5.14
* Read strings from standard input, look for consecutive duplicate words,
* keep track of the largest consecutive streak, print it or print no word
* was repeated
*/

using namespace std;

int main() {

	/*
	* 5.14
	* string s for input, bool flag, int cnt
	* read in input using while loop
	* check s to see if repeating
	* increment count
	*/

	string s = "", sTemp = "";
	vector<string> most;
	int cnt = 1, mostCnt = 1;

	//user prompt
	cout << "Please enter some words to test for repetition"
		<<"(enter 0 ont new line to end): " << endl;

	while (cin >> s) {
		
		if (s == sTemp) {//if word repeats
			++cnt;
		}
		else {
			if (cnt == mostCnt) {//this needs to be executed first
				most.push_back(sTemp);
			}
			
			if (cnt > mostCnt) {//check if cnt if the highest
				mostCnt = cnt;
				vector<string>().swap(most);//should clear
				most.push_back(sTemp);
			}
			

			sTemp = s;//sTemp assigned current word
			cnt = 1; // reset cnt
		}//end of else

		if (s == "0")
			break;//can be done using do while loop

	}//end of while

	if (mostCnt == 1)
		cout << "No word was repeated." << endl;
	else {
		cout << "The most consecutive repetitions is: " << mostCnt
			<< "." << endl << "The words are: ";
		for (string si : most) {//print all words with most repetitions
			cout << si << " ";
		}
		cout << "." << endl;
	}

	/*
	* Reflection, didn't need a bool flag, didn't account for mostCnt,
	* and multiple words with same number of repetitions
	*/
	return 0;
}