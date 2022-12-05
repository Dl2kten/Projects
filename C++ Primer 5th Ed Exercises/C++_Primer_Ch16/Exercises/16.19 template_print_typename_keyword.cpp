#include <iostream>
#include <vector>
#include <deque>


/*
* Exercise 16.19 16.20
* Write a function that takes a reference to a container and prints the
* elements in that container, use container's size_type and size members
* to control the loop
* Use iterators return from begin and end to control loop
*/

template<typename T>
void print(const T& container) {
	for (typename T::size_type i = 0; i < container.size(); ++i)
		std::cout << container[i] << " ";
	std::cout << std::endl;

	for(typename T::const_iterator iter = container.cbegin(); 
		iter != container.cend(); ++iter)
		std::cout << *iter << " ";
	std::cout << std::endl;
}

int main() {
	std::vector<int> ivec{ 1, 2, 3, 4 };
	std::deque<std::string> sdq{ "abra", "kadabra" };
	print(ivec);
	print(sdq);

	return 0;
}