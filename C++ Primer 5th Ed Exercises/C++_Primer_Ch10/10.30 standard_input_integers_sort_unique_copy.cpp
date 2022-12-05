#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<functional>

/*
* Exercise 10.30, 10.31
* Use stream iterators, sort, and copy to read a sequence of integers
* from standard input, sort, and then write back to standard output
* Update to print only unique elements
*/

using std::cout;
using std::cin;
using std::endl;



int main() {

	//user prompt
	cout << "Please enter some integers: " << endl;

	std::istream_iterator<int> intin_it(cin), intin_eof;
	std::ostream_iterator<int> intout_it(cout, " ");

	std::vector<int> ivec(intin_it, intin_eof);

	std::sort(ivec.begin(), ivec.end());
	std::unique_copy(ivec.cbegin(), ivec.cend(), intout_it);
	cout << endl;

	return 0;
}