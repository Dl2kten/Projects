#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<functional>
#include<list>

/*
* Exercise 10.42
* Reimplement the program that eliminated duplicate words to use a list
* instead of a vector
*/

using std::cout;
using std::cin;
using std::endl;

/*
* Function print, prints the elements in a vector
* param ostream&, vector<sting>
* return void
*/
void print(std::ostream& os, std::list<std::string> stringlist) {
	for (const auto& i : stringlist) {
		cout << i << " ";
	}
	cout << endl;
}

/*
* Function elimDupes eliminates duplicate words
* param vector<string>
* return void
*/
void elimDupes(std::list<std::string>& slist) {
	print(cout, slist);

	slist.sort();
	print(cout, slist);

	slist.unique();
	print(cout, slist);
}

int main() {

	std::list<std::string> words{ "a", "b", "a", "c", "d", "e", "b" };
	elimDupes(words);


	return 0;
}