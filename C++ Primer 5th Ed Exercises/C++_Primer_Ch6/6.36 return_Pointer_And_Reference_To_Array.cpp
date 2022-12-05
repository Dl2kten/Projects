#include<iostream>
#include <vector>

/*
* Exercise 6.36, 6.37, 6.38
* Write declaration for a function that returns a reference to array
* of ten ints without using type alias, trailing return, or decltype
* Write it now with type alias, trailing return, and decltype
* Revise the arrPtr function to return a reference to the array
*/

using namespace std;

/*
* string (&func(param))[10]
*
* using arrR = string[10];
* arrR &function(){};
*
* auto function() -> string(&)[10]
*
* string arrT[10];
* decltype(arrT) &function() {};
*
* int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};
// returns a pointer to an array of five int elements
decltype(odd) &arrPtr(int i)
{
return (i % 2) ? odd : even; // returns reference to array of 5 ints
}

* checked with online answers
*/

int main() {

	return 0;
}

