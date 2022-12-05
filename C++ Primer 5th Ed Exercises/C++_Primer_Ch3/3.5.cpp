#include<iostream>
#include<string>

/*
* Exercises for 3.2.2
* 3.5 concatenating strings
*/

//namespaces
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() 
{
	string s1, cString;

	//user prompt
	cout << "Please enter strings: " << endl;

	while (cin >> s1) {
		cString += s1 + " ";/*concatenates strings
							together*/
	}

	cout << "The concatenated string is: " << cString
		<< endl;

	return 0;
}