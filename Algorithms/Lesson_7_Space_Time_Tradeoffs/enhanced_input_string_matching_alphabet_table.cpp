#include <iostream>
#include <vector>
#include <string>

/*
* Space and time tradeoffs
* Input enhancement, preprocess input to store some info that can be used
* to help with solving problem
* String matching
*/

/// <summary>
/// String matching using a table to see how far each letter in alphabet is
/// from the last char of p_pattern and then jumps over according number
/// of characters before next comparison, called Horspool's algorithm, time
/// complexity from my implementation is O(n^2)
/// </summary>
/// <param name="p_text"></param>
/// <param name="p_pattern"></param>
/// <returns></returns>
int string_match(std::string p_text, std::string p_pattern) {
	std::vector<unsigned> table(26); //alphabet letters
	const auto sz = p_pattern.size();
	bool found = false;

	//populate table with how far each alphabet is from last char of p_pattern
	for (std::vector<unsigned>::size_type i = 0; i != table.size(); ++i) {
		for (int j = sz - 1; j != -1; --j) {
			auto value = int(p_pattern[j]) - 97; //change char ascii value
			//to position in alphabet 

			if (i == value && j != sz - 1) {//populate table with how far each alphabet
			//is to the last char in p_pattern
				table[i] = sz - 1 - j;
				found = true;
				break;
			}
		}
		if (!found)
			table[i] += sz; //if not equal or equal to last char the distance
							//to be skipped is the length of entire char
		else
			found = false;
	}

	//search for p_pattern in p_text
	for (std::string::size_type i = sz - 1; i < p_text.size();) {
		auto temp_index = i; //needed to compare chars of p_text at 
		//different points of string with p_pattern
		
		for (int j = sz - 1; j != -1; --j) {
			if (p_text[temp_index] != p_pattern[j]) {
				auto value = int(p_text[temp_index]) - 97;
				int jump = 0;
				if (value < 0) //in case converting from ' ' to ascii
					jump = sz;
				else
					jump = table[value];
				i += jump;
				break;
			}
			--temp_index;
			if (j == 0)
				found = true;
		}

		if (found)
			return i;
	}

	return -1;
}


int main() {
	std::string text{ "there once was a man who had a hen" }, pattern{ "onces" };
	auto match = string_match(text, pattern);
	if (match != -1)
		std::cout << "Pattern found at index: " << match << "\nPrinting string"
		<< " from found index to end: " << text.substr(match - pattern.size())
		<< std::endl;
	else
		std::cout << "Pattern not found." << std::endl;
	
	/*
	* Does space matter besides giving negative value when converting from ascii?
	* If it hits a space, algorithm just jumps pattern length
	* and if next set of chars is pattern it's gonna match, never jumps over
	*/
	return 0;
}