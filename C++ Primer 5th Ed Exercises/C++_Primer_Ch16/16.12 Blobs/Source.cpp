#include "Blob.h"
#include "BlobPtr.h"
#include <iostream>
#include <list>

/*
* Exercise 16.12, 16.13
* Write own version of Blob and BlobPtr templates, include const members
* Which friendship for operator== and operator<
*/

int main() {
	Blob<int> b1, b2{ 1, 2, 3, 4 };

	std::cout << b1.size() << std::endl;
	std::cout << b2.size() << std::endl;

	std::cout << b1.empty() << std::endl;
	std::cout << b2.empty() << std::endl;

	int i = 5;
	b1.push_back(i);
	b1.push_back(0);
	b2.push_back(i);
	b2.push_back(0);

	std::cout << b1.front() << std::endl;
	std::cout << b1.back() << std::endl;
	std::cout << b2.front() << std::endl;
	std::cout << b2.back() << std::endl;

	b1.pop_back();
	b2.pop_back();

	std::cout << b1.back() << std::endl;
	std::cout << b2.back() << std::endl;

	std::cout << b1[0] << std::endl;
	std::cout << b2[0] << std::endl;

	BlobPtr<int> bp1(b1), bp2(b2), bp3 = ++bp2;
	std::cout << *bp1 << std::endl;
	std::cout << *bp3 << std::endl;
	bp3 = bp2++;
	std::cout << *bp3 << std::endl;
	bp3 = --bp2;
	std::cout << *bp1 << std::endl;
	bp3 = bp2--;

	std::cout << (bp3 == bp2 ? "true" : "false") << std::endl;
	std::cout << (bp3 != bp2 ? "true" : "false") << std::endl;

	std::cout << (bp3 < bp2 ? "true" : "false") << std::endl;
	std::cout << (bp1 < bp2 ? "true" : "false") << std::endl;

	int ia[] = { 0,1,2,3,4,5,6,7,8,9 };
	std::list<std::string> slist{ "abra", "kadabra" };
	Blob<int> ib(std::begin(ia), std::end(ia));
	Blob<std::string> sb(slist.begin(), slist.end());
	std::cout << ib.front() << std::endl;
	std::cout << sb.back() << std::endl;

	/*
	* chose one to one friendship because wouldn't make sense to use
	* the operators across different instantiations, like int == string
	*/
	return 0;
}
