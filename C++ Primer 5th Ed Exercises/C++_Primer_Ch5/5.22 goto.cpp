#include<iostream>
#include<vector>

/*
* Exercise 5.22
* Revise to use loop instead of goto
* begin:
	int sz = get_size();
	if (sz <= 0) {
	goto begin;
	}
*/

using namespace std;

int main() {


	/*
	* 5.22
	* while loop
	* if sz <= 0 reinitialize variable
	*/

	/*
	int sz = get_size();

	while (sz <= 0) {
		sz = get_size();
	}

	not reinitialize, reassign
	
	int sz;
	while ((sz = get_size()) <= 0) ;

	could shorten and make the function call 1 less
	*/

	return 0;
}