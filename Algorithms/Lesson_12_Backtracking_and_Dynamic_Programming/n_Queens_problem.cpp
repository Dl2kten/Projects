#include <iostream>
#include <vector>
#include <string>
#include "Tree.h"

/*
* Backtracking - methodical process of trying out various sequences of decisions
* until find one that works
* n-Queens Problem - Place n queens on an n by n chessboard so that no pair
* of them are in the same row, column, or diagonal
*/


/// <summary>
/// backtrack algorithm
/// </summary>
/// <param name="p_tree"></param>
/// <param name="n"></param>
void backtrack(Tree& p_tree, std::size_t n) {

	for (unsigned i = 0; i != n; ++i) {
		for (unsigned j = 0; j != n; ++j) {
			if (p_tree.get_dead_end().first) {
				i = 0;
				p_tree.set_dead_end();
				j = p_tree.get_dead_end().second;
			}
			p_tree.insert(i, j);
		}
	}

}


int main() {
	std::string word;
	std::cout << "Please enter a number for n of the n-Queens problem"
		<< "(n needs to be >= 4, enter q to quit):\n";

	while (std::cin >> word && word != "q") {
		auto n = std::stoul(word);
		if (n < 4) {
			std::cout << "Please enter a number for n of the n-Queens problem"
				<< "(n needs to be >= 4, enter q to quit):\n";
			continue;
		}
		Tree tree(n);
		backtrack(tree, n);
		tree.print(std::cout);
		std::cout << "Please enter a number for n of the n-Queens problem"
			<< "(enter q to quit):\n";
	}

	//efficiency is linear, for space I used a map in node to store the invalid
	//squares that were added each time a node(Queen) was added as well as a 
	//general map that stored the current invalid squares... hmm actually maybe
	//able to take out the general map, it kind of functions as a temp right now
	//prob better to set it up that way next time

	return 0;
}