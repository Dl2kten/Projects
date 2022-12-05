#include<iostream>
#include<vector>
#include<list>
#include<string>
#include <deque>
#include <forward_list>

/*
* Exercise 9.38
* Explore how vectors grow
*/

using std::cout;
using std::cin;
using std::endl;


int main() {

	std::vector<int> ivec;
	// size should be zero; capacity is implementation defined
	cout << "ivec: size: " << ivec.size()
		<< " capacity: " << ivec.capacity() << endl;
	// give ivec 24 elements
	for (std::vector<int>::size_type ix = 0; ix != 24; ++ix)
		ivec.push_back(ix);
	cout << "ivec: size: " << ivec.size()
		<< " capacity: " << ivec.capacity() << endl;

	ivec.reserve(50); 
	cout << "ivec: size: " << ivec.size()
		<< " capacity: " << ivec.capacity() << endl;

	while (ivec.size() != ivec.capacity())
		ivec.push_back(0);
	// capacity should be unchanged and size and capacity are now equal
	cout << "ivec: size: " << ivec.size()
		<< " capacity: " << ivec.capacity() << endl;

	ivec.push_back(42); // add one more element
// size should be 51; capacity will be >= 51 and is implementation defined
	cout << "ivec: size: " << ivec.size()
		<< " capacity: " << ivec.capacity() << endl;

	ivec.shrink_to_fit(); // ask for the memory to be returned
// size should be unchanged; capacity is implementation defined
	cout << "ivec: size: " << ivec.size()
		<< " capacity: " << ivec.capacity() << endl;

	/*
	* shrink_to_fit request accepted, overall more conservative with
	* space then the example from text
	*/
	return 0;
}