#include<iostream>
#include <vector>
//#define NDEBUG

/*
* Exercise 6.47
* Revise printVector program to conditionally print size of the vector
* on each call, compile with debugging turned on and again with it off
*/

using namespace std;

/*
* Function print vector elements
* parameter vector<int>
* return void
*/
void printVector(const vector<int>& iv) {
#ifndef NDEBUG
	//__func__ as opposed to func in textbook, local static defined
	//by compiler
	cerr << __func__ << " vector size is: " << iv.size() << endl;
#endif
	vector<int> temp = iv;
	//print the last element
	auto index = iv.size() - 1;
	if (temp.size() > 1) {
		temp.pop_back();
		printVector(temp);
	}

	cout << iv[index] << endl;

	/*
	* void printVecInt(const std::vector<int>::iterator bg,
				 const std::vector<int>::iterator ed) {
		if (bg == ed)
		return;
		std::cout << *bg << " ";
		printVecInt(bg + 1, ed);
	}
	better cause only copies the pointers at beg and end
	*/

}


int main() {

	vector<int> iv{ 1, 2, 3, 4 };
	printVector(iv);

	return 0;
}
