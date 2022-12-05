#include <iostream>
#include <string>
#include <bitset>
#include <vector>

/*
* Exercise 17.10
* Using the sequence 1,2,3,5,8,13,21, initialize a bitset that has a
* 1 bit in each position corresponding to a number in this sequence,
* default initialize another bitse and write a small program to turn on
* each of the appropriate bits
*/

int main() {
	//0111010010000100000001
	std::bitset<22> b1("1000000010000100101110");
	std::bitset<22> b2;

	std::vector<int> ivec{ 1, 2, 3, 5, 8, 13, 21 };
	for (int i = 0; i < ivec.size(); ++i) { 
		b2.set(ivec[i]);
	}

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;

	/*
	* At first I reversed the position of the ivec elements but set
	* already sets the bit in the correct position lol
	*/
	return 0;
}