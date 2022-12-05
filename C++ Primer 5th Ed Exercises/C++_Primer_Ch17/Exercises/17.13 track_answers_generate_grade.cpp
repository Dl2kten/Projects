#include <iostream>
#include <string>
#include <bitset>
#include <vector>


/*
* Exercise 17.13
* Write an integral object that contains the correct answers for the
* quiz and use it to generate grades on the quiz for the data structure
* from previous two exercises
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
void track_answers<N>::update_answer(std::size_t q_n, bool correct) {
	correct ? track.set(q_n - 1) : track.reset(q_n - 1);
}

int main() {

	track_answers <10> quiz10;
	unsigned correct_answers = 0;
	std::vector<std::string> scores{ "F", "D", "C", "B", "A", "A++" };

	for (decltype(quiz10.track.size()) i = 0; i < quiz10.track.size();
		++i) {
		std::cout << "Quiz question " << i + 1 << ", enter 1 for correct"
			<< " answer, 0 for incorrect answer, q to quit:\n";
		std::string answer;
		std::cin >> answer;
		if (answer == "1") {
			quiz10.track.set(i);
			++correct_answers;
		}
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
		std::cout << "Question " << i + 1 << ": "
		<< (quiz10.track[i] ? "correct\n" : "incorrect\n");
	std::cout << std::endl;

	std::cout << "Letter grade is: " << scores[(correct_answers * 10 -
		50) / 10] << std::endl;

	return 0;
}