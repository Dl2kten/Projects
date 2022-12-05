#include <iostream>
#include <string>
#include <bitset>
#include <vector>

/*
* Exercise 17.11
* Define data structure that contains an integral object to track
* responses to a true/false quiz containing 10 questions, what changes,
* if any, would need to be made if the quiz had 100 questions
*/

template<std::size_t N>
struct track_answers {
	std::bitset<N> track;
};

int main() {
	
	track_answers <10> quiz10;

	for (decltype(quiz10.track.size()) i = 0; i < quiz10.track.size();
		++i) {
		std::cout << "Quiz question " << i + 1 << ", enter 1 for correct"
			<< " answer, 0 for incorrect answer, q to quit:\n";
		std::string answer;
		std::cin >> answer;
		if (answer == "1")
			quiz10.track.set(i);
		else if (answer == "0")
			;
		else if (answer == "q")
			break;
		else
			throw std::runtime_error("Not acceptable value.");
	}

	std::cout << "Quiz results:\n";
	for (decltype(quiz10.track.size()) i = 0; i < quiz10.track.size();
		++i)
		std::cout << "Question " << i+1  << ": " 
		<< (quiz10.track[i] ? "correct\n" : "incorrect\n");
	std::cout << std::endl;

	/*
	* if 100 questions need to define track_answers<100> object
	*/
	return 0;
}