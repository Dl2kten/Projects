#include<iostream>
#include<string>

/*
* Exercises for 3.2.2
* 3.4 comparing strings
*/

//namespaces
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() 
{
	string s1, s2;

	//user prompt
	cout << "Please enter two strings: " << endl;

	//reads in the two strings
	cin >> s1 >> s2;

	if (s1 == s2) {//if the two strings are equal
		cout << "The strings are equal." << endl;
	}
	else {
		if (s1 > s2)//if first string larger
			cout << "The first string is larger" << endl;
		else //second string is larger
			cout << "The second string is larger" << endl;
	}

	//find the length of the two strings
	auto s1Len = s1.size();
	auto s2Len = s2.size();

	if (s1Len == s2Len) {//if equal length
		cout << "The two strings are of equal size"
			<< endl;
	}
	else {
		if (s1Len > s2Len)//if first string is longer
			cout << "The first string is longer." << endl;
		else//second string is longer
			cout << "The second string is longer." << endl;
	}

	return 0;
}