#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

/*
* Exercise 10.21
* Write a lambda that captures a local int variable and decrements until
* it reaches 0, once 0 additional calls should no longer decrement the
* variable, lambda should return bool that indicates if int is 0
*/

using std::cout;
using std::cin;
using std::endl;


int main() {
	int i = 5;

	auto f = [&i]() -> bool {
		if (i == 0)
			return true;
		else {
			--i;
			return false;
		}
	};

	while (!f()) {
		cout << i << " ";
	}
	cout << endl;

	/*
	* if want to use mutable need to return the copied capture value
	*/

	return 0;
}