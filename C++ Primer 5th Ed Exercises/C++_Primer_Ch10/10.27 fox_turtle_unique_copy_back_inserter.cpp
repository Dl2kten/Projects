#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<functional>
#include<list>

/*
* Exercise 10.27
* Use unique_copy to copy the unique elements from a vector into an
* initially empty list
*/

using std::cout;
using std::cin;
using std::endl;

int main() {
	std::vector<std::string> svec{ "the", "quick", "red", "fox", "jumps",
	"over", "the", "slow", "red", "turtle" };
	std::list<std::string> slist;

	std::sort(svec.begin(), svec.end());
	std::unique_copy(svec.begin(), svec.end(), std::back_inserter(slist));

	for (const auto& i : slist)
		cout << i << " ";
	cout << endl;

	return 0;
}