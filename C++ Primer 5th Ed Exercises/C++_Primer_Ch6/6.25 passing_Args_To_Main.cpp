#include<iostream>


/*
* Exercise 6.25, 6.26
* Main function take two arguments, concatenate the supplied arguments
* and print the resulting string
* Accept the options presented in this section and print the values
* of the arguments passed to main
*/

using namespace std;


int main(int argc, char *argv[]) {
	if (argc < 3)
		return -1;

	string argsTotal = "";

	cout << "The entered arguments are: " << endl;

	for (int i = 0; i < argc; ++i) {
		cout << argv[i] << endl;//6.25
		argsTotal = argsTotal + argv[i] + " ";//6.26
	}

	cout << "The concatenated form is: " << argsTotal << endl;

	return 0;
}

