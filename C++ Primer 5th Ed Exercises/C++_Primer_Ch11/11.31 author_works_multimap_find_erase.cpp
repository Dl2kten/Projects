#include<iostream>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<algorithm>


/*
* Exercise 11.31
* Use find to find an element in the multimap of authors and their works,
* erase that element, ensure program works correctly if the element
* is not in the map
*/

using std::cout;
using std::cin;
using std::endl;


/*
* Function findAndDelete, finds and deletes element from multimap
* param std::multimap<std::string, std::string>&, const std::string&
* return void
*/
void findAndDelete(std::multimap<std::string, std::string>& mss,
	const std::string& work) {
	auto element = mss.find(work);
	auto count = mss.count(work);
	
	if (element != mss.end())
		while (count) {
			mss.erase(element++);
			--count;
		}
	else
		cout << "Author not found." << endl;
}


/*
* Function print, prints contents of multimap
* param const std::multimap<std::string, std::string>&
* return void
*/
void print(const std::multimap < std::string, std::string>& mss) {
	for (const auto& i : mss)
		cout << "Author: " << i.first << " works: " << i.second << "\n";
	cout << endl;
}

int main() {

	std::multimap<std::string, std::string> works{{"Dickens",
		"Oliver"}, {"Dickens", "Two Cities"}, {"Rowling","Harry Potter"},
		{"Tolkien", "Lotr"}, {"Tolkien", "Hobbit"}};
	print(works);
	findAndDelete(works, "Dickens");
	print(works);
	findAndDelete(works, "Poe");
	print(works);

	return 0;
}