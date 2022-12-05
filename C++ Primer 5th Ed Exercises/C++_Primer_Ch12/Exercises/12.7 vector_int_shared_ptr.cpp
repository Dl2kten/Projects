#include<iostream>
#include<memory>
#include <vector>
#include<new>
#include <memory>
/*
* Exercise 12.7
* Redo previous exercise, this time using shared_ptr
*/

using std::cout;
using std::cin;
using std::endl;

/*
* Function vector_factory creates a vector<int> in dynamic memory
* param
* return vector<int>*
*/
std::shared_ptr<std::vector<int>> vector_factory() {
	return std::make_shared<std::vector<int>>();
}

/*
* Function add_to_vec, adds elements from standard input
* param
* return vector<int>*
*/
std::shared_ptr<std::vector<int>> add_to_vec() {
	int element;
	auto pivec = vector_factory();
	cout << pivec.use_count() << endl;
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
void print_ivec(std::shared_ptr<std::vector<int>> ivec) {
	for (const auto& i : *ivec)
		cout << i << " ";
	cout << "\n" << ivec.use_count() << endl;
}

int main() {

	print_ivec(add_to_vec());

	return 0;
}


