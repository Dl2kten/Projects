#include <iostream>
#include <string>
#include <vector>
#include <list>

/*
* Exercise 16.63, 16.64
* Define a function template to count the number of occurrences of a given
* value in  a vector, passing it vector of doubles, ints, and strings
* Write a specialized version of the template for vector<const char*>
*/

template<typename T, typename U>
std::size_t value_count(const T& t, const U& u) {
	std::cout << "no specialization" << std::endl;
	std::size_t count = 0;
	for (const auto& i : t) {
		if (i == u)
			++count;
	}
	return count;
}

template<>
std::size_t value_count(const std::vector<double>& dvec, const double& d)
{
	std::cout << "double specialization" << std::endl;
	std::size_t count = 0;
	for (const auto& i : dvec) {
		if (i == d)
			++count;
	}
	return count;
}

template<>
std::size_t value_count(const std::vector<std::string>& svec,
	const std::string& s) {
	std::cout << "string specialization" << std::endl;
	std::size_t count = 0;
	for (const auto& i : svec) {
		if (i == s)
			++count;
	}
	return count;
}

template<>
std::size_t value_count(const std::vector<const char*>& cvec,
	const char* const& c) {
	std::cout << "const char specialization" << std::endl;
	std::size_t count = 0;
	for (const auto& i : cvec) {
		if (i == c)
			++count;
	}
	return count;
}

template<>
std::size_t value_count(const std::vector<int>& ivec, const int& n)
{
	std::cout << "int specialization" << std::endl;
	std::size_t count = 0;
	for (const auto& i : ivec) {
		if (i == n)
			++count;
	}
	return count;
}
int main() {
	std::vector<std::string> svec{ "a", "b" };
	std::vector<int> ivec{ 1, 2, 3, 2, 4 };
	std::vector<double> dvec{ 0.1, 0.2, 0.3, 0.4 };
	std::list<int> lvec{ 1, 2, 3, 4 };
	std::vector<const char*> cvec{ "abra", "kadabra", "alakazam" };
	std::string word{ "abra" };
	std::cout << value_count(svec, word) << std::endl;//string special
	std::cout << value_count(ivec, 2) << std::endl;
	std::cout << value_count(dvec, 0.1) << std::endl;
	std::cout << value_count(lvec, 1) << std::endl;
	std::cout << value_count(svec, "c") << std::endl;//original
	std::cout << value_count(cvec, "alakazam") << std::endl;//original
	const char* p = "alakazam";
	std::cout << value_count(cvec, p) << std::endl;//const char*
	//if looking at compare, the specialized version takes two const
	//char* variables, the unsigned is enough for string literals


	return 0;
}
