#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

/*
* Exercise 8.13
* Rewrite phone number program from this section to read from a named
* file, (finished and run ostringstream program as well)
*/

using namespace std;

struct PersonInfo {
	string name;
	vector<string> phones;
};

/*
* Function valid, checks to see if phone number is valid
* param const string&
* return bool
*/
bool valid(const string& s) {
	//set valid phone number to 10, area code + number 
	return (s.size() == 10) ? true : false;
}

/*
* Function format, format phone number to area code + number
* param const string& 
* return const string&
*/
string format(const string& s) {
	//we know s has 10 chars
	string area = "(";
	string total;
	for (decltype(s.size()) i = 0; i < 3; ++i) {
		area += s[i];
	}
	
	total = area + ")"; //should be (###)
	
	string threeDigits;
	for (decltype(s.size()) i = 3; i < 6; ++i) {
		threeDigits += s[i];
	}

	total += threeDigits;//(###)###

	string fourDigits = "-";
	for (decltype(s.size()) i = 6; i < s.size(); ++i) {
		fourDigits += s[i];
	}

	total += fourDigits;//(###)###-####

	return total;
}

int main() {
	string line, word;
	vector<PersonInfo> people;
	istringstream record;

	ifstream inputFile("phoneNumbers.txt");

	if (inputFile) {
		while (getline(inputFile, line)) {
			PersonInfo info; //create an object to hold this record's data

			record.clear();
			record.str(line); // bind record to the line we just read

			record >> info.name; // read the name

			while (record >> word) // read the phone numbers
				info.phones.push_back(word);
			people.push_back(info); // append this record to people
		}
	}
	else {
		cerr << "Couldn't open/find file." << endl;
		return -1;
	}
	

	for (const auto& entry : people) { // for each entry in people
		ostringstream formatted, badNums; // objects created on each loop
		for (const auto& nums : entry.phones) { // for each number
			if (!valid(nums)) {
				badNums << " " << nums; // string in badNums
			}
			else
				// ''writes'' to formatted's string
				formatted << " " << format(nums);
		}
		if (badNums.str().empty()) // there were no bad numbers
			cout << entry.name << " " // print the name
			<< formatted.str() << endl; // and reformatted numbers
		else // otherwise, print the name and bad numbers
			cerr << "input error: " << entry.name
			<< " invalid number(s) " << badNums.str() << endl;
	}

	/*
	* From online answers, probably better to set phone number length
	* as a const, should've checked to see the chars in num were digits,
	* string has substr function
	*/
	return 0;
}