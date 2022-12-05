#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

/*
* Exercise 8.11
* For PersonInfo program from text, define istringstream outside of 
* loop and make the necessary changes
*/

using namespace std;

struct PersonInfo {
	string name;
	vector<string> phones;
};

int main() {

	string line, word; 
	vector<PersonInfo> people; 
	istringstream record;

	while (getline(cin, line)) {
		PersonInfo info; // create an object to hold this record's data

		record.clear();
		record.str(line); // bind record to the line we just read
		
		record >> info.name; // read the name
		
		while (record >> word) // read the phone numbers
			info.phones.push_back(word); // and store them
		people.push_back(info); // append this record to people
	}

	for (const auto& p : people) {
		cout << p.name << " "; //print name
		for (const auto& n : p.phones)
			cout << n << " ";//print the phone numbers
		cout << endl;
	}

	/*
	* Needed to clear istringstream first after moving object outside of
	* loop, why according to online answers is stream state is eof, can't
	* do operations while stream state not good, all inherits from io
	*/
	return 0;
}