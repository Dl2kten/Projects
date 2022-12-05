#include <iostream>
#include <string>
#include <bitset>
#include <vector>

/*
* Exercise 17.12
* Using the data structure from the previous
* question, write a function that takes a question number and a
* value to indicate a true/false answer and updates the quiz
* results accordingly.
*/

template<std::size_t N>
struct track_answers {
	std::bitset<N> track;
	void update_answer(std::size_t, bool);
};

/*
* Takes a question number and a bool indicating true/false and updates
* quiz results
*/
template<std::size_t N>
void track_answers<N>::update_answer(std::size_t q_n, bool correct){
	correct ? track.set(q_n - 1): track.reset(q_n - 1);
}

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

	quiz10.update_answer(1, false);
	quiz10.update_answer(10, true);
	std::cout << "Question 1: "
		<< (quiz10.track[1 - 1] ? "correct\n" : "incorrect\n")
		<< std::endl; //did 1-1 for consistency
	std::cout << "Question 10: "
		<< (quiz10.track[10 - 1] ? "correct\n" : "incorrect\n")
		<< std::endl;

	return 0;
}