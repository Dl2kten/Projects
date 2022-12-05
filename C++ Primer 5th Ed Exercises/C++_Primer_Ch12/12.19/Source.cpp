#include<iostream>
#include<memory>
#include<vector>
#include<fstream>
#include"StrBlob.h"
#include"StrBlobPtr.h"
#include"ConstStrBlobPtr.h"

/*
* Exercise 12.19, 12.20, 12.22
* Define own version of StrBlobPtr and update with appropriate friend
* decalaration and begin and end members
* Read an input file a line at a time into StrBlob and uses StrBlobPtr
* to print each element in StrBlob
* Add ConstStrBlobPtr class that can point to a const StrBlob
*/


int main() {
	
	std::ifstream in_file("Test.txt");
	if (!in_file) {
		std::cerr << "Couldn't open file." << std::endl;
		return -1;
	}

	std::string line;
	StrBlob sb;
	while (getline(in_file, line)) {
		sb.push_back(line);
	}

	StrBlobPtr beg(sb.begin());
	//StrBlobPtr end(sb.end());

	std::cout << "The contents of the input file are: " << std::endl;
	for (decltype(sb.size()) i = 0; i < sb.size(); ++i, beg.incr()) {
		std::cout << beg.deref() << "\n";
	}
	std::cout << std::endl;

	const StrBlob csb({ "a", "b" });
	ConstStrBlobPtr csbp(csb);
	std::cout << "The contents of a const StrBlob are: " << std::endl;
	for (decltype(csb.size()) i = 0; i < csb.size(); ++i, csbp.incr()) {
		std::cout << csbp.deref() << "\n";
	}
	std::cout << std::endl;

	/*
	* Alot more test cases to go through based on constructor
	*/
	return 0;
}