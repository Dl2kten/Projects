#include <iostream>
#include <vector>

/*
* Decrease by a third
* Fake coin problem, assume have n coins, one is fake and lighter, can use
* scale, find the fake coin
*/
using iter = std::vector<int>::const_iterator;

int value(iter begin, iter end) {
	int total = 0;
	while (begin != end) {
		total += *begin++;
	}
	return total;
}

int check(iter begin, iter first, iter second) {
	if (value(begin, first) < value(first, second))
		return 1; //fake in first section
	if (value(begin, first) > value(first, second))
		return -1;
	return 0; //piles equal	
}

iter find_fake_coin(iter begin, iter end) {
	int n = end - begin;

	if (n == 1)
		return begin;

	if (n == 2) {
		return (*begin < *(end - 1) ? begin : (end - 1));
	}

	
	auto first = begin + n / 3;
	auto second = first + n / 3;
	if (check(begin, first, second) > 0)
		return find_fake_coin(begin, first);
	else if (check(begin, first, second) < 0)
		return find_fake_coin(first, second);
	else
		return find_fake_coin(second, end);
}

int main() {
	
	std::vector<int> ivec{ 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,};
	iter found = find_fake_coin(ivec.cbegin(), ivec.cend());

	int index = 0;
	for (const auto& i : ivec) {
		if (*found == i)
			break;
		else
			++index;
	}
	
	std::cout << "The fake coin is located at the " << index << " position." 
		<< std::endl;

	return 0;
}