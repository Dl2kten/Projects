#include<iostream>
#include<string>
#include<cstddef>
#include<vector>
#include<iterator>

/*
* Exercise  3.35 3.36
* Using pointers set elements in an array to zero
* compare two arrays for equality, compare two vectors as well
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
	//3.35
	constexpr size_t array_size = 5;
	int arrayi[array_size];

	int *beg = begin(arrayi);//begin() under std lib
	int *last = end(arrayi);

	while (beg != last) {
		*beg = 0;
		beg++;
	}

	//print to check
	for (auto i = 0; i < array_size; i++) {
		cout << arrayi[i] << " ";
	}

	cout << endl;

	//3.36
	int arrayj[array_size] = { 0, 0, 0, 1, 0 };
	int arrayk[array_size] = { 0, 0, 0, 0, 0 };

	vector<int> vector1(5, 0);
	vector<int> vector2 = { 0, 0, 1, 0, 0 };

	/* in this case I set the arrays and vectors to be same size
	but if different, check to see which one is smaller and then
	compare the elements up to that point*/

	int* begj = begin(arrayj);
	int* endj = end(arrayj);
	int* begk = begin(arrayk);

	while (begj != endj && *begj == *begk) {
	/*loop goes until pointer to first element points to one past last element
	or the array elements of the two arrays are different*/
			begj++;
			begk++;
	}

	//if point is at one past element that means the arrays are equal
	if (begj == endj) {
		cout << "The two arrays are equal." << endl;
	}
	else {
		cout << "The two arrays are not equal" << endl;
	}

	/*comparing vectors, which already compares the size and elements*/
	if (vector1 == vector2) {
		cout << "The two vectors are equal." << endl;
	}
	else {
		cout << "The two vectors are not equal." << endl;
	}

	return 0;
}