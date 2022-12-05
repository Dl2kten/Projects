#include<iostream>
#include <vector>


/*
* Exercise 6.33
* Write a recursive function to print the contents of a vector
*/

using namespace std;

/*
* Function print vector elements
* parameter vector<int>
* return void
*/
void printVector(const vector<int> &iv) {
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

	vector<int> iv{ 1, 2, 3, 4};
	printVector(iv);

	return 0;
}

