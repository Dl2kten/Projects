#include <iostream>
#include "Binary_tree.h"

/*
* Divide and conquer
* Binary Tree Search
*/




int main() {

	Binary_tree bt1;
	bt1.insert(10);
	bt1.insert(9);
	bt1.insert(15);
	bt1.insert(7);
	bt1.insert(6);
	bt1.insert(14);
	bt1.insert(20);

	std::cout << bt1.height() << std::endl;
	std::cout << bt1.leaves() << std::endl;


	return 0;
}
