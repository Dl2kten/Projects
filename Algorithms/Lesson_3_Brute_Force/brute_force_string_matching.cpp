#include <iostream>
#include <string>

/*
* Brute force for string matching
*/

/// <summary>
/// Sees if pattern is a substring of text
/// </summary>
/// <param name="text"></param>
/// <param name="pattern"></param>
/// <returns></returns>
int brute_force_string_match(const std::string& text,
	const std::string& pattern) {
	for (std::string::size_type i = 0; i < text.size() - pattern.size(); ++i) {
		std::string::size_type j = 0;
		while (j < pattern.size() && pattern[j] == text[j + i])
			++j;
		if (j == pattern.size())
			return i;
	}

	return -1;
}


int main() {
	std::string line;
	std::cout << "Enter text and a pattern to search for, q to quit: "
		<< std::endl;
	while (getline(std::cin, line) && line != "q") {
		std::string pattern;
		getline(std::cin, pattern);
		int index = brute_force_string_match(line, pattern);
		if (index != -1) {
			std::cout << "There is matching substring in text and it starts"
				<< " at index: " << index << std::endl;
		}
		else {
			std::cout << "There is no matching substring in text."
				<< std::endl;
		}
		std::cout << "Enter text and a pattern to search for, q to quit: "
			<< std::endl;
		
	}

	//let's say m is pattern.size() and n is text.size(), O((n-m+1)m)
	return 0;
}