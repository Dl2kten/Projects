#include<iostream>
#include<string>

/*
* Exercises for 3.2.2
* 3.2, write a program to read a line at a time and a 
* word at a time
*/

//namespaces
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() 
{
	/*
	cout << "Please enter lines that wish to be read: " 
		<< endl;//user prompt

	string line;

	while (getline(cin, line)) {//read until end-of-file
		
		cout << "The line entered was: " << endl;
			
		cout << line << endl;
	}

	*/

	//same for words entered
	cout << "Please enter words that wish to be read: "
		<< endl;//user prompt

	string word;

	while (cin >> word) {//read until end-of-file
		
		cout << word << endl;
	}

	return 0;
}