#include<iostream>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<algorithm>


/*
* Exercise 11.32
* Use program from previous exercise, print the list of authors and 
* their works alphabetically
*/

using std::cout;
using std::cin;
using std::endl;
using authorBook = std::multimap<std::string, std::string>;

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
* Function sortWorks, sorts pairs based on second
* param std::multimap<std::string, std::string>&
* return void
*/
void sortWorks(std::multimap<std::string, std::string>::iterator& iter1,
	std::multimap<std::string, std::string>::iterator& iter2) {
	std::string temp;
	//sort based on second string, the books
	
		if (iter1->second > iter2->second) {
			temp = iter1->second;
			iter1->second = iter2->second;
			iter2->second = temp;
		}

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
	for (auto beg = works.begin(); beg != works.end(); ++beg) {

		auto element = works.find(beg->first);
		auto count = works.count(beg->first);
		while (count > 1) {
			//this condition rather than > 0 makes sure that we don't
			//try to access one-past-end element and keeps the third
			//arg of for loop ++beg, if > 0 then all the increments to
			//beg should be in this loop only
			auto curr = element++;
			sortWorks(curr, element);
			--count;
			++beg;
		}		
	}
	
	print(works);

	findAndDelete(works, "Dickens");
	print(works);
	findAndDelete(works, "Poe");
	print(works);



	return 0;
}