#include<iostream>
#include<memory>
#include <vector>
#include<new>
/*
* Exercise 12.6
* Write a function that returns a dynamically allocated vector of ints,
* pass that vector to another function that reads from standard input
* to give values to elements, pass that to another function to print the
* values that were read, delete at right time
*/

using std::cout;
using std::cin;
using std::endl;

/*
* Function vector_factory creates a vector<int> in dynamic memory
* param
* return vector<int>*
*/
std::vector<int>* vector_factory() {
	return new std::vector<int>();
}

/*
* Function add_to_vec, adds elements from standard input
* param
* return vector<int>*
*/
std::vector<int>* add_to_vec() {
	int element;
	std::vector<int>* pivec = vector_factory();

	//user prompt
	cout << "Please enter int values to add to vector: " << endl;
	while (cin >> element) {
		pivec->push_back(element);
	}

	return pivec;
}

/*
* Function print_ivec, prints contents of vector<int>
* param vector<int>*
* return void
*/
void print_ivec(std::vector<int>* ivec) {
	for (const auto& i : *ivec)
		cout << i << " ";
	cout << endl;

	delete ivec;//remember to delete
}

int main() {

	print_ivec(add_to_vec());

	return 0;
}


