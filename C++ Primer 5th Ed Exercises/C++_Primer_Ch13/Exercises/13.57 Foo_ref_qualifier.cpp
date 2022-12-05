
#include <iostream>
#include <iostream>
#include <algorithm>
#include <vector>
/*
* Exercise 13.56, 13.57
* Run code from text to see what happens
*/

class Foo {
public:
	Foo(std::initializer_list<int> sil) : data(sil) {}
	Foo sorted()&&;
	Foo sorted() const&;
private:
	std::vector<int> data;
};

Foo Foo::sorted()&& {
	std::sort(data.begin(), data.end());
	return *this;
}
/*
//13.56
Foo Foo::sorted() const& {
	std::cout << "ret" << std::endl;
	Foo ret(*this);
	return ret.sorted();
}*/


//13.57
Foo Foo::sorted() const& {
	std::cout << "Foo(*this)" << std::endl;
	return Foo(*this).sorted();
}

int main() {
	Foo a{ 2, 4, 1 };
	a.sorted();

	/*
	* 13.56 kept running until error, 13.57 ran once using sorted()&&
	*/
	return 0;
}