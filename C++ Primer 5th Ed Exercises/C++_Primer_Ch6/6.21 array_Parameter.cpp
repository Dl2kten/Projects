#include<iostream>


/*
* Exercise 6.21, 6.22, 6.23
* Write a function that takes an int and a pointer to an int and returns
* the larger int value or the value to which the pointer points(?)
* Function to swap two int pointers
* Write own version of the print functions from book
*/

using namespace std;

/*
* Function larger int value
* parameter, int and const pointer to const int
* return the larger int value
*/

int isLargerInt(int i, const int* ip) {
	return (i > *ip) ? i : *ip;
	/*
	* why don't we use const int* const?
	*/
}

/*
* Function swap two int pointers
* parameter, 2 int pointers
* return void
*/

void swap(int* ip, int* ip2) {
	int temp = *ip;
	*ip = *ip2;
	*ip2 = temp;
}

/*
* Function print int
* parameter, const int
* return void
*/
void print(const int i) {
	cout << i << endl;
}

/*
* Function print chars
* parameter, const char pointer
* return void
*/
void print(const char* c) {
	while (*c) {
		cout << *c++;
	}
}

/*
* Function print array with 2 pointers
* parameter, 2 const int pointers
* return void
*/
void print(const int* beg, const int* end) {
	for (; beg != end; ++beg) {
		cout << *beg << " ";
	}
	cout << endl;
}

/*
* Function print array while passing a size parameter
* parameter, const int pointer, size_t
* return void
*/
void print(const int* beg, size_t s) {
	for (size_t i = 0; i < s; ++i) {
		cout << *beg++ << " ";
	}
	cout << endl;
}

/*
* Function print ref to array
* parameter, ref to array of 10 const int
* return void
*/
void print(const int(&ira)[2]) {
	for (auto i : ira) {
		cout << i << " ";
	}
	cout << endl;
}

/*
* Function print multidimensional array
* parameter, pointer to array of 10 ints const, size_t rowSize
* return void
*/
void print(const int(*ipa)[2], size_t rowSize) {
	for (size_t i = 0; i < rowSize; ++i) {
		for (auto j : ipa[i]) {
			cout << j << " ";
		}
		cout << endl;
	}
}

int main() {

	int num1 = 1, num2 = 2, i = 0, j[2] = { 0, 1 };
	cout << isLargerInt(1, &num2) << endl;

	int* ip1 = &num1;
	int* ip2 = &num2;
	swap(ip1, ip2);
	cout << "Num1: " << *ip1 << "\nNum2: " << *ip2 << endl;

	print(i);
	print(begin(j), end(j));
	print(begin(j), sizeof(j) / sizeof(j[0]));
	print(j);

	return 0;
}

