#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
/*
* Exercise 16.40, 16.41
* Is text from book legal, restrictions on argument type, what is return
* type
* Write a version of sum with a return tpe that is guaranteed to be large
* enough to hold the result of addition
*/

template <typename It>
auto fcn3(It beg, It end) -> decltype(*beg + 0)
{
	// process the range, iterators should be from same sequence
	return *beg; // return a copy of an element from the range
}



template<typename P>
struct promote;

template<> 
struct promote<bool> { 
	using type = int; 
};

template<>
struct promote<int> {
	using type = long long;
};

template<>
struct promote<long> {
	using type = long long;
};

template<>
struct promote<float> {
	using type = double;
};

template<typename T>
auto sum(T a, T b) -> typename promote<T>::type {
	return static_cast<typename promote<T>::type>(a) + b;
}

int main() {
	std::vector<int> ivec{ 1, 2 };
	auto result = fcn3(ivec.begin(), ivec.end());
	result = 0;
	//err it's legal and I suppose the book is trying to differentiate
	//between rvale and lvalue but I got an int type from both *beg and
	//*beg + 0 ...

	auto b = std::numeric_limits<int>::max();
	auto q = sum(b, b);

	return 0;
}