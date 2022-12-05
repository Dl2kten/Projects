#include<iostream>
#include<memory>
#include <vector>
#include<new>
#include <memory>
/*
* Exercise 12.16
* Write a program that contains errors using unique_ptr to see how
* your compiler diagnoses them
*/

using std::cout;
using std::cin;
using std::endl;



int main() {

	std::unique_ptr<std::string> p1(new std::string("Stegosaurus"));
	//std::unique_ptr<std::string> p2(p1);
	std::unique_ptr<std::string> p3;
	//p3 = p2;
	
	/*
	* For copying and assigning unique_ptrs it gave error c2280, 
	* attempting to reference a deleted function, and error c2679 no
	* '=' operator found which takes...
	*/
	return 0;
}


