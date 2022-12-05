#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <algorithm>
/*
* Exercise 14.38, 14.39
* Write a class that tests whether the length of a given string matches
* a given bound, use that object to write a program to report how many
* words in an input file are of sizes 1 - 10 inclusive
* Revise to report the count of words that are sizes 1-9 and 10+
*/

struct Length_match {
	Length_match(std::size_t l, std::size_t u) : lower_bound(l),
		upper_bound(u) {}
	bool operator()(const std::string& s) {
		return s.size() >= lower_bound && s.size() <= upper_bound;
	}
	
private:
	std::size_t lower_bound;
	std::size_t upper_bound;
};

int main() {
	std::ifstream in("Three_Musketeers.txt");
	if (!in) {
		std::cerr << "Unable to open file" << std::endl;
		return -1;
	}

	std::vector<std::string> svec;
	std::string word;
	while (in >> word) {
		svec.push_back(word);
	}

	std::cout << "The number of words of size 1 - 9: "<< std::count_if(
		svec.cbegin(), svec.cend(), Length_match(1, 9)) 
		<< "\nThen number of words of size 10+: "
		<< std::count_if( svec.cbegin(), svec.cend(), Length_match(10, -1)) 
		<< std::endl;
	/*
	* Changed to 6 cause 10 included too many words, from online can use
	* stream_iter, wouldn't need vector
	*/
	return 0;
}