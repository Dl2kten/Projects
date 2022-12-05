#include<iostream>
#include<string>
#include<cstddef>
#include<vector>
#include<iterator>
#include<cstring>

/*
* Exercise  3.37 3.39 3.40
* Run code for 3.37, compare 2 c-style strings, use strcpy and stcat
*/

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::begin;
using std::end;

int main()
{
	//3.37

	const char ca[] = { 'h', 'e', 'l', 'l', 'o' };
	const char* cp = ca;
	while (*cp) {/*This printed several other chars after hello, may also
				 cause undetermined result? Need better while condition*/
		cout << *cp << endl;
		++cp;
	}

	//3.39

	string s1("token");
	string s2 = { "tokien" };

	if (s1 < s2) {
		cout << "String 1 is bigger than string 2." << endl;
	}
	else {
		cout << "String 1 is smaller or equal to string 2." << endl;
	}

	const char ca1[] = "token";
	const char ca2[] = { 't', 'o', 'k', 'i', 'e', 'n', '\0' };

	if (strcmp(ca1, ca2) < 0) {
		cout << "C-style character array 1 is bigger than array 2." << endl;
	}
	else {
		cout << "C-style character array 1 is smaller or equal to "
			"array 2." << endl;
	}


	//3.40

	const char ca3[] = "Copy";
	const char ca4[] = " concatenate";

	//in total need 17 spaces to add ca3 and ca4
	char largeCa[17];

	strcpy_s(largeCa, ca3);

	cout << largeCa << endl;

	strcat_s(largeCa, ca4);

	cout << largeCa << endl;

	/*Error, needed to use strcpy_s instead of strcpy
	* Used a literal to define largeCa not sure how to use strlen here as
	* errors were shown saying needed a const value
	*/

	return 0;
}