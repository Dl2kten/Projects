#include<iostream>
#include <vector>
#include <string>

/*
* Exercise 4.21, 4.22, 4.23
* Use conditional operator to find element in a vector<int> that have odd
* value and double the value
* Extend the grade pass program with low pass for grades 60 - 75 using
* conditional operators and then using if statements
* Fix operator precedence of an expression
*/

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int main() {

	//4.21
	vector<int> vInt = { 0, 1, 2, 3, 4, 5, 6 };

	for (auto& i : vInt) {
		//if there's remainder when i divided by 2, double that value
		i = (i % 2 != 0) ? i * 2 : i;
		cout << i << " ";
	}
	cout << endl;

	//4.22

	int grade = 72;

	string finalGrade = (grade > 90) ? "high pass" ://above 90
		(grade > 75 ) ? "pass" ://90 - 76 
		(grade < 60) ? "fail" : "low pass";//75 - 60 low pass, else fail

	cout << finalGrade << endl;

	//compared to multiple if else statements
	if (grade < 60) {
		finalGrade = "fail";
	}
	else {
		if (grade < 76) {
			finalGrade = "low pass";
		}//1st nested if
		else {
			if (grade < 90) {
				finalGrade = "pass";
			}//2nd nest if
			else {
				finalGrade = "high pass";
			}
		}
	}
	cout << finalGrade << endl;

	//4.23

	string s = "word";
	//added 2 brackets, without brackets it's error
	//the expression checks to see if last letter is s
	string pl = s + ((s[s.size() - 1] == 's') ? "" : "s");

	return 0;
}