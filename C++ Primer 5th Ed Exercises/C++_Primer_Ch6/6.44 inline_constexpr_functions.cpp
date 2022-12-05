#include<iostream>
#include <vector>


/*
* Exercise 6.44, 6.45
* Change isShorter function to be inline
* Can isShorter be defined as constexpr
*/

using namespace std;

/*
* Function compare strings
* parameter 2 const string refs
* return bool
*/

inline bool isShorter(const string& s1, const string& s2)
{
	return s1.size() < s2.size();
	/*
	* the size() is not constexpr so can't be constexpr, size() called
	* at runtime
	*/
}

int main() {
	

	return 0;
}

