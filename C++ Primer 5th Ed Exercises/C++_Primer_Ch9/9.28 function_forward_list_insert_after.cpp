#include<iostream>
#include<vector>
#include<list>
#include<string>
#include <deque>
#include <forward_list>

/*
* Exercise 9.28
* Write a function that takes a forward_list<string> and two string args,
* find the first string and insert the second immediately following the
* first, if first not found, then insert second string at end of list
*/

using std::cout;
using std::cin;
using std::endl;

/*
* Function findString looks for string inside forward_list
* param forward_list<string>, two string
* return void
*/
void findString(std::forward_list<std::string>& sfl,
	const std::string& s1, const std::string& s2) {

	auto curr = sfl.begin();
	auto next = sfl.begin();
	bool found = false;

	++next;//want next to denote the element after curr

	while (curr != sfl.end()) {

		if (next != sfl.end()) {
			if (*curr == s1) {
				found = true;
				curr = sfl.insert_after(curr, { s1, s2 });
				//curr = sfl.insert_after(curr, s2);
				++curr;
				++next;
			}
			else {
				++curr;//increment curr and next
				++next;
			}
		}
		else {//case for last element
			if (*curr == s1) {
				found = true;
				curr = sfl.insert_after(curr, { s1, s2 });
			}

			if (!found) {//if s1 was not a match
				curr = sfl.insert_after(curr, s2);
			}

			++curr;
		}
		
	}//end of while

}

int main() {

	std::forward_list<std::string> sflist1{ "a", "b", "c", "d" };
	std::forward_list<std::string> sflist2{ "a", "b", "c", "d" };

	findString(sflist1, "b", "hello");

	for (const auto& i : sflist1)
		cout << i << " ";
	cout << endl;

	findString(sflist2, "hi", "hello");

	for (const auto& i : sflist2)
		cout << i << " ";
	cout << endl;

	/*
	* thought question meant to add both strings to forward_list,
	* use of return or break could've made code simpler, instead of 
	* next can also use pre to denote the element before end
	*/

	return 0;
}