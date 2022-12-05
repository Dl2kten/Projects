#include<iostream>
#include<string>

/*
* Exercises 3.2.3
* 3.6 Use range for to change chars in string to X
* 3.8 Using other loops
*/

//namespaces
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() 
{
	
	string s1;

	//user prompt
	cout << "Please enter a string: " << endl;

	cin >> s1;

	//using range for
	for (auto& c : s1)//need reference to convert the string
		c = 'X';//uppercase

	cout << "Using range for: " << s1 << endl;

	//using while loop
	auto last = s1.size();
	decltype(s1.size()) count = 0;

	while (count < last) {
		s1[count] = 'Y';
		++count;
	}

	cout << "Using  while loop: " << s1 << endl;

	//using for loop
	for (decltype(s1.size()) index = 0; index != s1.size();
		++index) {
		s1[index] = 'Z';
	}

	cout << "Using  for loop: " << s1 << endl;
	
	return 0;
}