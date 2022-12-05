#include<iostream>
#include<string>
#include<cstddef>
#include<vector>

/*
* Exercise 3.31 3.32
* Define array of ten ints and give value equal to its position
* Copy array into another array, use vectors
* 
*/

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main()
{
	const size_t array_size = 10;
	int arrayi[array_size];

	for (size_t i = 0; i < array_size; i++) {
		arrayi[i] = i;//assign value equal to position
	}

	int arrayj[array_size];

	for (size_t i = 0; i < array_size; i++) {
		arrayj[i] = arrayi[i];//copy value from ai array to aj array
	}

	vector<int> vector1;
	
	for (size_t i = 0; i < array_size; i++) {
		vector1.push_back(i);//assign value equal to position
	}

	vector<int> vector2 = vector1;

	vector2[0] = 10;

	cout << vector1[0] << " " << vector2[0] << endl;

	for (auto i : arrayi) {//check values for arrayi
		cout << i;
	}

	cout << endl;

	for (auto i : arrayj) {//check values for arrayj
		cout << i;
	}

	cout << endl;

	return 0;
}