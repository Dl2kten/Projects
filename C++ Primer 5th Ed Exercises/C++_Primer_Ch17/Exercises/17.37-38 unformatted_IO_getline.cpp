#include <iostream>
#include <string>
#include <fstream>

/*
* Exercise 17.37, 17.38
* Use the unformatted version of getline to read a file aline at a time,
* test by giving it a file that contains empty lines as well as lines
* that are longer than the char array
* Extend program to pirnt each word you read onto its own line
*/


int main() {
	
	std::ifstream in("getline_test.txt");
	if (!in) {
		std::cerr << "could not open file" << std::endl;
		return -1;
	}

	std::size_t sz = 25;
	char c_array[25];
	char ch;

	while (in.getline(c_array, 25, '\n')) {
		//std::cout.write(c_array, 25) << std::endl;
		for (decltype(sizeof(c_array)) i = 0; i < sizeof(c_array); ++i) {
			if (c_array[i] != ' ')
				std::cout << c_array[i];
			else
				std::cout << std::endl;
		}
	}
	return 0;

	/*
	* If line is longer than char array it just exits out of while loop,
	* blank lines replace the first char with \0
	* blanks replace chars same as number of blanks
	*/
}
