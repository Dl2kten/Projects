#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <algorithm>
/*
* Exercise 14.40
* Rewrite biggies function from 10.3.2 to use function objects instead
* of lambdas
*/

struct Larger_than {
	bool operator()(const std::string& a, const std::string& b) {
		return a.size() < b.size();
	}
};


struct Larger_than_size {
	Larger_than_size(std::vector<std::string>::size_type s) : sz(s) {}
	bool operator()(const std::string& a) { return a.size() >= sz; }
private:
	std::vector<std::string>::size_type sz;
};


struct Print_elements {
	void operator()(const std::string& s)
	{
		std::cout << s << " ";
	}
};

/*
* Function print, prints the elements in a vector
* param ostream&, vector<sting>
* return void
*/
void print(std::ostream& os, std::vector<std::string>& stringvec) {
	for (const auto& i : stringvec) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}


/*
* Function elimDupes eliminates duplicate words
* param vector<string>
* return void
*/
void elimDupes(std::vector<std::string>& svec) {
	print(std::cout, svec);

	std::sort(svec.begin(), svec.end());

	auto iter = std::unique(svec.begin(),
		svec.end());
	print(std::cout, svec);

	svec.erase(iter, svec.end());
	print(std::cout, svec);
}

/*
* Function biggies, find strings with length bigger than specified size
* param vector<string>, vector<string>::size_type
*/
void biggies(std::vector<std::string>& words,
	std::vector<std::string>::size_type sz) {

	elimDupes(words);
	std::stable_sort(words.begin(), words.end(), Larger_than());

	//auto wfirst = std::find_if(words.begin(), words.end(), [sz]
	//(const std::string& a) {return a.size() >= sz; });

	auto wlast = std::stable_partition(words.begin(), words.end(),
		Larger_than_size(sz));

	auto count = wlast - words.begin();
	std::cout << "There are " << count << " words of length " << sz
		<< " or longer." << std::endl;

	std::for_each(words.begin(), wlast, Print_elements());
	std::cout << std::endl;

}


int main() {

	std::vector<std::string> wordCollection{ "dkjafofj", "da", "dafdfakj",
	"a", "eijf", "optpjkwp", "eiafojop;", "fdj", "fanfoan" };

	biggies(wordCollection, 6);

	return 0;
}