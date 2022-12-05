#include <iostream>
#include <string>
#include <memory>

/*
* Exercise 16.61
* Define own version of make_shared
*/

template<typename T, typename...Args>
std::shared_ptr<T> make_s(Args&&... args){
	return std::shared_ptr<T>(new T(args...));
}


int main() {
	
	std::shared_ptr<int> is = make_s<int>(10);
	std::cout << *is << std::endl;
	std::shared_ptr<std::string> ss = make_s<std::string>(10, 'c');
	std::shared_ptr<std::pair<double, double>> dds =
		make_s<std::pair<double, double>>(1.2, 0.5);
	std::cout << *ss << std::endl;
	std::cout << dds->first << " " << dds->second << std::endl;

	return 0;
}