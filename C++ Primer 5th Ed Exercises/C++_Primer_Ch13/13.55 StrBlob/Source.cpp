#include "StrBlob.h"
#include "StrBlobPtr.h"
#include "ConstStrBlobPtr.h"
#include "StrBlobPtrPtr.h"
#include <iostream>
#include <algorithm>
#include <fstream>
/*
* Ch 14 Exercises
*/

int main() {
	
	StrBlob sb;
	std::string a = "a";
	for (size_t i = 0; i < 4; ++i)
		sb.push_back(a);

	sb.push_back("Hello");
	sb.push_back("Hi");

	StrBlob sb2(sb), sb3;
	if (sb == sb2)
		std::cout << "Equal";
	if (sb3 != sb2)
		std::cout << "\nNot equal" << std::endl;
	sb3.push_back("a");
	sb3.push_back("b");

	if (sb < sb3)
		std::cout << "HelloHi smaller than ab" << std::endl;
	sb[0] = "Bonjour";
	std::cout << sb << std::endl;
	
	std::ifstream in_file("Test.txt");
	if (!in_file) {
		std::cerr << "Couldn't open file." << std::endl;
		return -1;
	}

	std::string line;
	StrBlob sb5;
	while (getline(in_file, line)) {
		sb5.push_back(line);
	}

	StrBlobPtr beg(sb5);
	std::cout << "The contents of the input file are: " << std::endl;
	for (decltype(sb5.size()) i = 0; i < sb5.size() ; ++i, ++beg) {
		std::cout << beg.deref() << "\n";
	}
	std::cout << std::endl;

	StrBlobPtr sbp1(sb5);
	std::cout << (sbp1 += 2).deref() <<std::endl;
	std::cout << (sbp1 + 1).deref() << std::endl;
	std::cout << (sbp1 -= 1).deref() << std::endl;
	std::cout << (sbp1 - 1).deref() << std::endl;
	std::cout << sbp1.deref() << std::endl;
	
	//exercise 14.30
	std::cout << *sbp1 << std::endl;
	std::cout << sbp1->size() << std::endl;

	//exercise 14.32
	StrBlobPtrPtr sbpp1(sbp1);
	std::cout << *sbpp1 << std::endl;
	std::cout << sbpp1->size() << std::endl;
	return 0;
}