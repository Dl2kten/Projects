#include <iostream>
#include <array>

/*
* Dynamic Programming - general design for solving optimization problems
* Robot Coin-collecting refer to Robot_coin_collecting.odt
*
* Step 1 - decompose into simpler sub problems
* Starting at the destination, choose the largest coin that can be brought
* from the top cell or the left cell
* F(i, j) = max(F(i-1, j), F(i, j-1) + cij, c at ij is if there's a coin in
* the cell of (i, j), 1 if there is, 0 otherwise
* 
* Step 2 - express solution in terms of sub problem
* Keep applying step one until arrive at start
* 
* Step 3 - use table to compute optimal value bottom up
* Create a table with same dimensions and record the max number of coins at
* each cell
* 
* Step 4 - find optimal solution based on step 1-3
* return solution
*/

using matrix = std::array <std::array<unsigned, 6>, 5>;

/// <summary>
/// Finds the max coin number for each cell
/// </summary>
/// <param name="p_cells"></param>
/// <returns></returns>
matrix robot_coin_collection(const matrix& p_cells) {
	matrix max_coin;
	max_coin.fill({0,0,0,0,0,0});
	max_coin[0][0] = p_cells[0][0];

	//sets the coin count of all cells in first row
	for (decltype(p_cells[0].size()) i = 1; i != p_cells[0].size(); ++i) {
		max_coin[0][i] = max_coin[0][i-1] + p_cells[0][i];
	}
	
	for (decltype(p_cells.size()) i = 1; i != p_cells.size(); ++i) {
		max_coin[i][0] = max_coin[i - 1][0] + p_cells[i][0];
		for (decltype(p_cells[0].size()) j = 1; j != p_cells[0].size(); ++j) {
			max_coin[i][j] = std::max(max_coin[i - 1][j],
				max_coin[i][j - 1]) + p_cells[i][j];
		}
	}

	//efficiency O(i*j) time, O(i*j) space
	return max_coin;
}

int main() {
	matrix cells = { {
		{0, 0, 0, 0, 1, 0},
		{0, 1, 0, 1, 0, 0},
		{0, 0, 0, 1, 0, 1},
		{0, 0, 1, 0, 0, 1},
		{1, 0, 0, 0, 1, 0} }
	};
	
	matrix solution = robot_coin_collection(cells);
	
	std::cout << "The max number of coins that can be attained at each cell is:"
		<< std::endl;
	for (const auto& i : solution) {
		for (const auto& j : i) {
			std::cout << j << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}