#include<iostream>
#include<vector>
#include<list>
#include<string>
#include <deque>



/*
* Exercise 9.20
* Copy elements from list<int> into two deque<int>, even valued elements
* should go into one and the odd ones into the other
*/

using std::cout;
using std::cin;
using std::endl;

int main() {
	/*
	* one list<int>, two deque<int>
	* read values into list<int>, while
	* for loop, two indexes, one to get value another to see even or odd
	*/

	std::list<int> ilist;
	int temp;
	std::deque<int> idEven, idOdd;

	//user prompt
	cout << "Please enter integers: " << endl;

	while (cin >> temp) {
		ilist .push_back(temp);
	}

	int i = 0;
	for (std::list<int>::const_iterator iter = ilist.begin(); 
		iter != ilist.cend(); ++iter, ++i) 
	{
		if (i % 2 == 0) // if even
			idEven.push_back(*iter);
		else
			idOdd.push_back(*iter);
	}
	cout << endl;

	for (const auto& i : idEven)
		cout << i << " ";
	cout << endl;

	for (const auto& i : idOdd)
		cout << i << " ";
	cout << endl;

	/*
	* Thought it was even indexed elements, even and odd value elements
	* can just use *iter mod 2 to separate the elements
	*/
	return 0;
}