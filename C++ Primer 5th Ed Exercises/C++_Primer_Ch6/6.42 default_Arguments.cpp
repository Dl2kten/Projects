#include<iostream>
#include <vector>


/*
* Exercise 6.42
* Change second string parameter of make_plural to a default agrument
* with value "s" and test by printing singular and plural version of
* the words success and failure
*/

using namespace std;

/*
* Function make word plural
* parameters, siz_t, const string reference, const string reference
* with default argument
* return string
*/
string make_plural(size_t ctr, const string& word,
	const string& ending = "s")
{
	return (ctr > 1) ? word + ending : word;
}

int main() {
	
	cout << make_plural(1, "success") << endl;
	cout << make_plural(2, "success", "es") << endl;
	cout << make_plural(1, "failure") << endl;
	cout << make_plural(2, "failure") << endl;

	return 0;
}

