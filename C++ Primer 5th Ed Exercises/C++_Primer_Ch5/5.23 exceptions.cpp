#include<iostream>
#include<vector>
#include<stdexcept>
#include<exception>

/*
* Exercise 5.23, 5.24, 5.25
* Read two integers from standard input and print result of dividing
* first number by the second
* Revise to throw an exception if the second number is 0
* Revise to use a try block to catch exception, catch clause prints 
* message to user to supply a new number, repeat the code inside try
*/

using namespace std;

int main() {


	/*
	* 5.23
	* 2 ints to store read in values
	* divide 1st by 2nd
	*/

	int num1, num2;

	//user prompt
	cout << "Please enter two numbers for division: " << endl;

	cin >> num1;

	while (cin >> num2) {
		try {
			if (num2 == 0)
				throw runtime_error("Second number can not be 0.");
			break;
		}
		catch (runtime_error err) {
			cout << err.what() << endl
				<< "Please enter a new number: " << endl;

		}
	}

	/*
	* A do while loop might express the intent of the question better
	*/

	cout << "The result is: " << num1 / num2 << endl;


	return 0;
}