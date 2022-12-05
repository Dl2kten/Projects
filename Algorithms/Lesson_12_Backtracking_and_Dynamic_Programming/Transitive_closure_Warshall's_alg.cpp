#include <iostream>
#include <array>

/*
* Dynamic Programming - general design for solving optimization problems
* Transitive closure(Warshall's alg) - find all vertices vi that have paths to
* any other vertex vj in a directed unweighted graph, can be applied to see if
* any two airports are connected, reachability testing
* refer to Warshall's.odt for problem
* 
* Step 1 - decompose into simpler sub problems
* select row1, column1, see if there's any connection between vertices that
* travel through vertex 1
* for all i, j
* if(i, 1) = 1 and (i, j) = 1
*	(i,j) = 1
* 
* Step 2 - express solution in terms of sub problem
* Repeat for row2, column2... til rowN, columnN
* 
* Step 3 - use table to compute optimal value bottom up
* Create a table showing all present connections, change after new connections
* formed due to previous steps
* 
* Step 4 - find optimal solution based on step 1-3
* return solution
*/

/// <summary>
/// Finds all paths available between any two vertices
/// </summary>
/// <param name="p_matrix"></param>
void Warshall_alg(std::array<std::array<unsigned, 4>, 4>& p_matrix) {
	for (decltype(p_matrix.size())k = 0; k != p_matrix.size(); ++k) {
		for (decltype(p_matrix.size())i = 0; i != p_matrix.size(); ++i) {
			for (decltype(p_matrix.size())j = 0; j != p_matrix.size(); ++j) {
				if (p_matrix[i][k] == 1 && p_matrix[k][j] == 1)
					p_matrix[i][j] = 1;
			}
		}
	}
	//efficiency O(n^3) time, in place
}

int main() {
	std::array<std::array<unsigned, 4>, 4> adjacency_matrix{ {
		{0, 0, 1, 0},
		{1, 0, 0, 1},
		{0, 0, 0, 0},
		{0, 1, 0, 0},
		}
	};

	Warshall_alg(adjacency_matrix);

	std::cout << "All possible connections between any two vertices is shown"
		<< " in adjacency matrix below:\n";
	
	for (const auto& i : adjacency_matrix) {
		for (const auto& j : i)
			std::cout << j << " ";
		std::cout << std::endl;
	}

	return 0;
}