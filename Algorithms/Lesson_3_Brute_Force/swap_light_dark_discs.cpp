#include <iostream>
#include <string>
#include <vector>

/*
* Consider the following problem:
* You have 1 row of n disks of 2 colors, n dark and n light.  They alternate 
* dark, light, dark, light, dark, and so on. You want to get all the dark 
* disks on the right hand side and all  the light disks on the left.
* The only moves you are allowed to make are those that interchange the 
* position of two neighboring disks.
*/


/*
* Can use bubble sort but that has O(n^2)
* Or can instead do this: since alternating can define dark disks as even 
* indexed elements and light disks as odd indexed elements and just switch
* even and odd each time, each time after first ignoring the first and last
* elements, 012345, 103254, 130524, 135024 
*/

/// <summary>
/// uses method described above
/// </summary>
/// <param name="p_svec"></param>
void switch_dark_light(std::vector<std::string>& p_svec) {
	int count = 0;
	for (decltype(p_svec.size()) i = 0; i < p_svec.size() / 2; ++i) {
		//since reducing elements by 2 each iteration only needs half of size
		for (auto j = i; j < p_svec.size() - i; j+=2) {
			++count;
			std::swap(p_svec[j], p_svec[j + 1]);
		}
	}

	std::cout << "Total number of dark and light disks: " << p_svec.size()
		<< "\nTotal number of swaps: " << count << std::endl;
}

/// <summary>
/// prints contents of vector<string>
/// </summary>
/// <param name="p_svec"></param>
void print(const std::vector<std::string>& p_svec) {
	for (auto& i : p_svec)
		std::cout << i;
	std::cout << std::endl;
}

int main() {

	std::vector<std::string> svec{ "d", "l", "d", "l", "d", "l", "d", "l",
	"d", "l", "d", "l", "d", "l", "d", "l", "d", "l", "d", "l",
	"d", "l", "d", "l", "d", "l", "d", "l", "d", "l", "d", "l" };

	switch_dark_light(svec);
	print(svec);

	//so O is n/2 * (n-i)/2, for 32 disks that's 132 swaps vs 32^2 if using
	//bubble sort
	return 0;
}