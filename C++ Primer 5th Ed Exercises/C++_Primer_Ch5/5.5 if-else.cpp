#include<iostream>
#include<vector>

/*
* Exercise 5.5, 5.6
* Write a program to generate letter grade from a numeric grade using
* if-else statement
* Rewrite the program from 5.5 using conditional operator over if-else
*/

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main() {

	//5.5
	vector<string> letterGradeMarks = { "F", "D", "C", "B", "A" };
	int grade = 0;
	string letterGrade;

	//ask user for a numeric grade and read into variable
	cout << "Please enter a numeric grade: " << endl;
	cin >> grade;

	//basically the same as text book, could have asked a different
	//question for a different take on if-else usage
	if (grade < 60) {
		letterGrade = letterGradeMarks[0];
		cout << "The letter grade is: " << letterGrade << endl;
	}
	else {
		letterGrade = letterGradeMarks[grade / 10 - 5];
		cout << "The letter grade is: " << letterGrade << endl;
	}

	//5.6
	letterGrade = grade < 60 ? letterGradeMarks[0] :
		letterGradeMarks[grade / 10 - 5];

	cout << "Using conditional operator: " << letterGrade << endl;
	
	return 0;
}