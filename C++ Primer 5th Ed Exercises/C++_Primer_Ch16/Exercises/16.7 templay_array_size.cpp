#include <iostream>
#include <list>
#include <vector>

/*
* Exercise 16.7
* Write a constexpr template that returns size of a given array
*/

template<typename T, unsigned N>
void print(const T(&arr)[N]) {
	for (const auto& i : arr)
		std::cout << i << " ";
	std::cout << std::endl;
}

template<typename T, unsigned N>
T* begin_ptr(T(&arr)[N]) {
	return &arr[0];
}

template<typename T, unsigned N>
T* end_ptr(T(&arr)[N]) {
	return &arr[N - 1];
}

template<typename T, std::size_t N>
constexpr std::size_t arr_size(const T(&arr)[N]) {
	return N;
}

int main() {

	int iarr[] = { 1, 2, 3, 4, 5, 6 };
	std::string sarr[] = { "abra", "kadabra", "alakazam", "sim sala bim" };
	print(iarr);
	print(sarr);

	auto ptr = begin_ptr(iarr);
	auto ptr2 = end_ptr(sarr);
	std::cout << *ptr << " " << *ptr2 << std::endl;
	std::cout << arr_size(iarr) << std::endl;
	std::cout << arr_size(sarr) << std::endl;

	return 0;
}