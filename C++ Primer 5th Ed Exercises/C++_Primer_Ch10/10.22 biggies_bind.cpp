#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<functional>

/*
* Exercise 10.22
* Rewrite program to count words of size 6 or less using functions
* in place of lambdas
*/

using std::cout;
using std::cin;
using std::endl;

/*
* Function print, prints the elements in a vector
* param ostream&, vector<sting>
* return void
*/
void print(std::ostream& os, const std::string& s) {
		cout << s << " ";
}


/*
* Function elimDupes eliminates duplicate words
* param vector<string>
* return void
*/
void elimDupes(std::vector<std::string>& svec) {
	std::sort(svec.begin(), svec.end());

	auto iter = std::unique(svec.begin(),
		svec.end());

	svec.erase(iter, svec.end());
}


/*
* Function lesser, finds words with letter counts of 6 or less
* param const string&
* return bool
*/
bool lesser(const std::string& a, std::string::size_type size) {
	return a.size() <= size;
}


/*
* Function compareString, compares two strings
* param two const string&
* return bool
*/
bool compareString(const std::string& a,
	const std::string& b) {
	return a.size() < b.size();
}


/*
* Function biggies, find strings with length bigger than specified size
* param vector<string>, vector<string>::size_type
*/
void biggies(std::vector<std::string>& words, std::string::size_type sz) {

	elimDupes(words);
	std::stable_sort(words.begin(), words.end(), compareString);

	auto wlast = std::stable_partition(words.begin(), words.end(),
		std::bind(lesser, std::placeholders::_1, sz));

	auto count = wlast - words.begin();
	cout << "There are " << count << " words of length " << sz
		<< " or lesser." << endl;

	std::for_each(words.begin(), wlast, std::bind(print, std::ref(cout), 
		std::placeholders::_1));
	cout << endl;

}


int main() {

	std::vector<std::string> wordCollection{ "dkjafofj", "da", "dafdfakj",
	"a", "eijf", "optpjkwp", "eiafojop;", "fdj", "fanfoan" };

	biggies(wordCollection, 6);

	return 0;
}