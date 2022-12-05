#include <iostream>
#include <array>

/*
* Dynamic Programming - general design for solving optimization problems
* Floyd's algorithm - given a directed weighted graph, find the shortest path
* between any two vertices
* Applications - games for movement
* Refer to Floyd's.odt for problem
* 
* Step 1 - decompose into simpler sub problems
* Similar to Warshall's except using weigted edges and if there's an alternative
* path through another vertex that gives shorter path then add that one
* for all i, j
* if(i,k) + (k,j) < (i,j)
*	(i,j) = (i,k) + (k,j)
* 
* Step 2 - express solution in terms of sub problem
* Do step 1 for all rows and columns, the k value
* 
* Step 3 - use table to compute optimal value bottom up
* Create a table showing all present connections, change after new connections
* formed due to previous steps
* 
* Step 4 - find optimal solution based on step 1-3
* return solution
*/

/// <summary>
/// Finds all shortest paths between any two vertices
/// </summary>
/// <param name="p_matrix"></param>
void Floyd_alg(std::array<std::array<unsigned, 4>, 4>& p_matrix) {
	for (decltype(p_matrix.size())k = 0; k != p_matrix.size(); ++k) {
		for (decltype(p_matrix.size())i = 0; i != p_matrix.size(); ++i) {
			for (decltype(p_matrix.size())j = 0; j != p_matrix.size(); ++j) {
				auto path = p_matrix[i][k] + p_matrix[k][j];
				if (p_matrix[i][j] > path)
					p_matrix[i][j] = path;
			}
		}
	}
	//efficiency O(n^3) time, in place
}

int main() {
	std::array<std::array<unsigned, 4>, 4> adjacency_matrix{ {
		{0, 1000, 3, 1000},
		{2, 0, 1000, 1000},
		{1000, 7, 0, 1},
		{6, 1000, 1000, 0},
		}
	};//using some sufficient large number to represent no connection initially

	Floyd_alg(adjacency_matrix);

	std::cout << "All shortest paths between any two vertices is shown"
		<< " in adjacency matrix below:\n";
	
	for (const auto& i : adjacency_matrix) {
		for (const auto& j : i)
			std::cout << j << " ";
		std::cout << std::endl;
	}

	return 0;
}