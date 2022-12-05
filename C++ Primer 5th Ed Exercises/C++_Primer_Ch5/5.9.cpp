#include<iostream>
#include<vector>

/*
* Exercise 5.9, 5.10, 5.11, 5.12
* Count the number of vowels in text read from cin using a series of if
* statements
* Change vowel-counting program to include capitals in the vowel count
* Count blank spaces, tabs, and newlines as well
* Modify vowel-counting program to count two character sequences: ff,
* fl, and fi
*/

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main() {

	//5.9

	char c;
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;

	//user prompt
	cout << "Please enter some words(using if statements to parse, "
		<< "enter 0 in a new line to stop):" << endl;

	//read in values and add vowels counts if present
	while (cin >> c && c != '0') {//needs to be '0' or won't read to c
		if (c == 'a')
			++aCnt;
		if (c == 'e')
			++eCnt;
		if (c == 'i')
			++iCnt;
		if (c == 'o')
			++oCnt;
		if (c == 'u')
			++uCnt;
	}
	
	cout << "Number of vowel a: \t" << aCnt << '\n'
		<< "Number of vowel e: \t" << eCnt << '\n'
		<< "Number of vowel i: \t" << iCnt << '\n'
		<< "Number of vowel o: \t" << oCnt << '\n'
		<< "Number of vowel u: \t" << uCnt << endl;

	//5.10, 5.11
	aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	unsigned spaceCnt = 0, tabCnt = 0, newLCnt = 0;

	//user prompt
	cout << "Please enter some words(using switch statement to parse, "
		<< "enter 0 in a new line to stop):" << endl;

	//read in values and add vowels counts if present
	while (cin.get(c) && c != '0') {//need get() to read white spaces
		switch (c) {
		case 'a': case 'A' ://either small or capital of vowel
			++aCnt;//increase count
			break;
		case 'e': case 'E' :
			++eCnt;
			break;
		case 'i': case 'I' :
			++iCnt;
			break;
		case 'o': case 'O' :
			++oCnt;
			break;
		case 'u': case 'U' :
			++uCnt;
			break;
		case ' ':
			++spaceCnt;
			break;
		case '\t':
			++tabCnt;
			break;
		case '\n':
			++newLCnt;
			break;
		default:
			;//nothing needs to be done

		}//end of switch block
	}//end of while block

	cout << "Number of vowel a: \t" << aCnt << '\n'
		<< "Number of vowel e: \t" << eCnt << '\n'
		<< "Number of vowel i: \t" << iCnt << '\n'
		<< "Number of vowel o: \t" << oCnt << '\n'
		<< "Number of vowel u: \t" << uCnt << '\n'
		<< "Number of spaces: \t" << spaceCnt << '\n'
		<< "Number of tabs: \t" << tabCnt << '\n'
		<< "Number of new lines: \t" << newLCnt << '\n'
		<<endl;

	//5.12
	/*
	* Should incorporate with vowel-counting program can use a bool flag
	* to check if 'f' is the previous character or use a pointer to
	* peak next char to see if it fits as done by answers from web
	*/
	unsigned ffCnt = 0, flCnt = 0, fiCnt = 0;

	//User prompt
	cout << "Please enter some words(checking for \"ff\", \"fl\", \"fi\", "
		<< "enter 0 in a new line to stop):" << endl;
	while (cin.get(c) && c != '0') {
		if (c == 'f') {
			cin.get(c); //get the following char
			switch (c) {
			case 'f':
				++ffCnt;
				break;
			case 'l':
				++flCnt;
				break;
			case 'i':
				++fiCnt;
				break;
			default:
				;//nothing needs to be done
			}//end of switch block
		}//end of if block
	}//end of while block

	cout << "Number of ff sequence: \t" << ffCnt << '\n'
		<< "Number of fl sequence: \t" << flCnt << '\n'
		<< "Number of fi sequence: \t" << fiCnt << '\n'
		<< endl;

	return 0;
}