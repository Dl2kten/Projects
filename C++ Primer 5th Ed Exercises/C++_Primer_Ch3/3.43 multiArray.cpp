#include<iostream>
#include<vector>
#include<string>

/*
* Exercise 3.43, 3.44, 3.45
* Write three different versions to print multidimensional array ia using for
* loop, subscripts and pointers
* Use type alias
* Use auto
*/

using std::cout;
using std::cin;
using std::endl;

int main() {

	//given from text book
	int ia[3][4] = { // three elements; each element is an array of size 4
		{0, 1, 2, 3}, // initializers for the row indexed by 0
		{4, 5, 6, 7}, // initializers for the row indexed by 1
		{8, 9, 10, 11} // initializers for the row indexed by 2
	};

	//3.43

	//range for loop
	for (int (&row)[4] : ia) {//have to declare the reference is to an array
							  //of ints of size 4, have to be specific
		for (int& col : row) {
			cout << col << " ";
		}
		cout << endl;
	}
	cout << "Range for" << endl;

	//for loop pointers
	for (int(*p)[4] = ia; p != ia + 3; p++) {
		//q points to first element of array of 4 ints
		for (int* q = *p; q != *p + 4; q++) {
			cout << *q << " ";
		}
		cout << endl;
	}
	cout << "For loop with pointers" << endl;

	//for loop subscripts
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cout << ia[i][j] << " ";
		}
		cout << endl;
	}
	cout << "For loop with subscripts" << endl << endl;


	//3.44

	using intArray = int[4];

	for (intArray &row : ia) {
		for (int& col : row) {
			cout << col << " ";
		}
		cout << endl;
	}
	cout << "Range for using type alias" << endl;

	//for loop pointers with type alias
	for (intArray *p = ia; p != ia + 3; p++) {
		//q points to first element of array of 4 ints
		for (int* q = *p; q != *p + 4; q++) {
			cout << *q << " ";
		}
		cout << endl;
	}
	cout << "For loop with pointers using type alias" << endl << endl;

	//3.45

	for (auto & row : ia) {
		for (auto & col : row) {
			cout << col << " ";
		}
		cout << endl;
	}
	cout << "Range for using auto" << endl;

	//for loop pointers with auto
	for (auto p = ia; p != ia + 3; p++) {
		//q points to first element of array of 4 ints
		for (auto q = *p; q != *p + 4; q++) {
			cout << *q << " ";
		}
		cout << endl;
	}
	cout << "For loop with pointers using auto" << endl;
	
	return 0;
}