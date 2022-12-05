#include <iostream>
#include <string>

/*
* Exercise 18.18, 18.19
* Given the definition of swap from text, determine which version of swap
* is used if mem1 is a string, what if mem1 is an int, explain how name lookup
* works in both cases
* What if the call to swap was std::swap(v1.mem1, v2.mem1)
*/

/*
void swap(T v1, T v2)
{
	using std::swap;
	swap(v1.mem1, v2.mem1);
}
	18.18
	so swap of some class type whose mem1 is string, because swap contains 
	members of class type string, compiler will look in string for swap 
	function as well as enclosing scopes unless there's a swap defined in
	enclosing scope will use string::swap
	for int uses std::swap
	18.19
	if call to swap was changed to std::swap then uses library version 
	regardless of arguments
*/

int main() {
	
	


	return 0;
}