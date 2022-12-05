#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

/*
* Exercise 10.20
* Use count_if to rewrite the program that counted string size
*/

using std::cout;
using std::cin;
using std::endl;


/*
* Function print, prints the elements in a vector
* param ostream&, vector<sting>
* return void
*/
void print(std::ostream& os, std::vector<std::string>& stringvec) {
	for (const auto& i : stringvec) {
		cout << i << " ";
	}
	cout << endl;
}


/*
* Function elimDupes eliminates duplicate words
* param vector<string>
* return void
*/
void elimDupes(std::vector<std::string>& svec) {
	print(cout, svec);

	std::sort(svec.begin(), svec.end());

	auto iter = std::unique(svec.begin(),
		svec.end());
	print(cout, svec);

	svec.erase(iter, svec.end());
	print(cout, svec);
}

/*
* Function biggies, find strings with length bigger than specified size
* param vector<string>, vector<string>::size_type
*/
void biggies(std::vector<std::string>& words,
	std::vector<std::string>::size_type sz) {

	elimDupes(words);
	std::stable_sort(words.begin(), words.end(), [](const std::string& a,
		const std::string& b) {return a.size() < b.size(); });
	
	auto count = std::count_if(words.cbegin(), words.cend(),
		[=](const std::string& a) {return a.size() >= sz; });

	cout << "There are " << count << " words of length " << sz
		<< " or longer." << endl;

	auto wlast = std::stable_partition(words.begin(), words.end(), [sz]
	(const std::string& a) {return a.size() >= sz; });

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