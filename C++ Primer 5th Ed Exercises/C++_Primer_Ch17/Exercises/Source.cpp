#include <iostream>
#include <string>
#include <fstream>

/*
* Exercise 17.39
* Write your own version of the seek program presented in this section
*/


int main() {
	
	std::fstream inOut("17.39.txt", std::fstream::ate | std::fstream::in
		| std::fstream::out);
	if (!inOut) {
		std::cerr << "Unable to opern file!" << std::endl;
		return EXIT_FAILURE;
	}

	auto end_mark = inOut.tellg();
	inOut.seekg(0, std::fstream::beg);
	std::size_t cnt = 0;
	std::string line;

	while (inOut && inOut.tellg() != end_mark && getline(inOut,
		line)) {
		cnt += line.size() + 1;
		auto mark = inOut.tellg();
		inOut.seekp(0, std::fstream::end);
		inOut << cnt;
		if (mark != end_mark)
			inOut << " ";
		inOut.seekg(mark);
	}

	inOut.seekp(0, std::fstream::end);
	inOut << "\n";

	/*
	* Need newline after j or u get j5 9 12 instead of j\n5 9 12 14
	*/
	return 0;
}
