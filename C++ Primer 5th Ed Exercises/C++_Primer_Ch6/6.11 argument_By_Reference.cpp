#include<iostream>


/*
* Exercise 6.1
* Write and test own version of reset function that takes a reference
*/

using namespace std;

/*
* Reset function
* resets int value to 0
*/

void reset(int &i) {
	i = 0;

	return;
}


int main() {

	int num1;
	//user prompt
	cout << "Please enter an integer to be reset: " << endl;
	cin >> num1;
	reset(num1);

	cout << "After using reset function, integer is: " 
		<< num1 << endl;
	
	return 0;
}

