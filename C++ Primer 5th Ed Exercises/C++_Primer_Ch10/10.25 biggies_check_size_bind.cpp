#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<functional>

/*
* Exercise 10.24
* Use bind and check_size to find the first element in vector int that
* has a value greater than the length of a specified string value
*/

using std::cout;
using std::cin;
using std::endl;

/*
* Function check_size, checks to see if an int has a value bigger than
* size
* param int, sting::size_type
* return bool
*/
bool check_size(const std::string& s, std::string::size_type sz) {
	return s.size() > sz;
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
* Function biggies, find strings with length bigger than specified size
* param vector<string>, vector<string>::size_type
*/
void biggies(std::vector<std::string>& words, std::string::size_type sz) {

	elimDupes(words);
	std::stable_sort(words.begin(), words.end(), [](const std::string& a,
		const std::string& b) {return a.size() < b.size(); });

	auto wlast = std::stable_partition(words.begin(), words.end(), 
		std::bind(check_size, std::placeholders::_1, sz));

	auto count = wlast - words.begin();
	cout << "There are " << count << " words of length " << sz
		<< " or longer." << endl;

	std::for_each(words.begin(), wlast, [](const std::string& s)
		{cout << s << " "; });
	cout << endl;

}

int main() {
	std::vector<std::string> wordCollection{ "dkjafofj", "da", "dafdfakj",
	"a", "eijf", "optpjkwp", "eiafojop;", "fdj", "fanfoan" };

	biggies(wordCollection, 6);
	return 0;
}