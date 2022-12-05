#include<iostream>


/*
* Exercise 6.27
* Write a function that takes an initializer_list<int>, find sum of
* the elements
*/

using namespace std;

/*
* Function sum
* parameter, initilizer_list<int>
* return int
*/
int sum(initializer_list<int> ii) {
	int sum = 0;
	for (auto &i : ii) {//no need to copy if reference
		sum += i;
	}

	return sum;
}

int main() {

	cout << "The sum of the ints 2 4 5 9 12 43 is: "
		<< sum({ 2, 4, 5, 9, 12, 43 }) << endl;

	return 0;
}

