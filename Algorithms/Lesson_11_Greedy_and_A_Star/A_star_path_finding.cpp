#include <iostream>
#include <vector>
#include <cmath>
#include <map>

/*
* Greedy Approach
* A * Path Finding Algorithm - employs a combination of dijkstra and best-first-
* search using Manhattan distance
* Each square is given a value using
* f(n) = g(n) + h(n)
* g(n) is distance from source, Dijkstra, and h(n) is calculated using Manhattan
* distance |square.x - dest.x| + |square.y - dest.y|
* Choose best square at each point until reach destination
* Refer to A_star_path_finding.odt for problem
*/
constexpr int start_row = 1, start_col = 1, dest_row = 1, dest_col = 3;


/// <summary>
/// Finds the f value of a square
/// </summary>
/// <param name="row"></param>
/// <param name="col"></param>
/// <returns></returns>
void calc_fn(int row, int col,
	std::multimap<int, std::vector<int>>& p_candidates,
	std::vector<std::vector<int>>& p_board) {
	auto g = std::abs(row - start_row) + 
		std::abs(col - start_col);
	if (g > 1) {
		g = p_candidates.begin()->second[2] + 1;
	}

	auto f = g +
		std::abs(row - dest_row) + std::abs(col - dest_col);

	
	//since multiset was getting repeats of elements with same key and value
	//here stops if the value already in multimap
	for (auto beg = p_candidates.begin(); 
		beg != p_candidates.end(); ++beg) {
		if (beg->second[0] == row && beg->second[1] == col)
			return;
	}

	//checks to see if a square had already been traversed, needed cause
	//there's case where will re traverse since deleting element from candidates
	if (p_board[row][col] == INT_MAX) {
		p_board[row][col] = f;
		p_candidates.insert({ f, { row,col,g } });
	}
}


/// <summary>
/// Finds the positions of squares adjacent to given square position
/// </summary>
/// <param name="row"></param>
/// <param name="col"></param>
/// <param name="p_board"></param>
/// <returns></returns>
std::vector<std::pair<int, int>> find_adjacent(int row, int col,
	std::vector<std::vector<int>>& p_board) {
	std::vector<std::pair<int, int>> ret;

	if (row - 1 != -1 && p_board[row - 1][col] != -1)
		ret.push_back({ row - 1, col });
	
	if (row + 1 != p_board.size() && p_board[row + 1][col] != -1)
		ret.push_back({ row + 1, col });

	if (col - 1 != -1 && p_board[row][col - 1] != -1)
		ret.push_back({ row, col - 1 });
				
	if (col + 1 != p_board.size() && p_board[row][col + 1] != -1)
		ret.push_back({ row, col + 1 });

	return ret;
}


/// <summary>
/// Fills adjacent squares with their f value
/// </summary>
/// <param name="row"></param>
/// <param name="col"></param>
/// <param name="p_board"></param>
void fill_adjacent(int row, int col,
	std::multimap<int, std::vector<int>>& p_candidates,
	std::vector<std::vector<int>>& p_board) {
	auto adjacent = find_adjacent(row, col, p_board);

	for(const auto& i : adjacent)
		calc_fn(i.first, i.second, p_candidates, p_board);
}


/// <summary>
/// Records the shortest path from the destination to start using square f(n)
/// values
/// </summary>
/// <param name="p_board"></param>
/// <returns></returns>
std::multimap<int, std::pair<int, int>> backtrack(
	std::vector<std::vector<int>>& p_board) {
	auto curr_row = dest_row, curr_col = dest_col, prev_row = INT_MAX,
		prev_col = INT_MAX;
	std::multimap<int, std::pair<int, int>> path;

	while (curr_row != start_row || curr_col != start_col) {
		auto temp_row = curr_row, temp_col = curr_col;

		auto squares = 
			find_adjacent(curr_row, curr_col, p_board);
		
		auto min = INT_MAX;
		for (const auto& i : squares) {
			if (i.first != prev_row || i.second != prev_col) {
				if (p_board[i.first][i.second] < min) {
					min = p_board[i.first][i.second];
					curr_row = i.first;
					curr_col = i.second;
				}
			}
		}
		prev_row = temp_row, prev_col = temp_col;
		path.insert({ p_board[curr_row][curr_col], {curr_row, curr_col} });
	}

	return path;
}


/// <summary>
/// A* path finding algorithm
/// </summary>
/// <param name="p_board"></param>
/// <returns></returns>
std::multimap<int, std::pair<int, int>> a_star(std::vector<std::vector<int>>& p_board) {
	auto curr_row = 0, curr_col = 0;
	std::multimap<int, std::vector<int>> candidates{{0, 
		{start_row, start_col, 0}}}; //candidates stores f value
	//of square as key, and in vector stores the position row and col in first
	//two values and g(n) in third value

	while (curr_row != dest_row || curr_col != dest_col) {
		curr_row = candidates.begin()->second[0];
		curr_col = candidates.begin()->second[1];
		fill_adjacent(curr_row, curr_col, candidates, p_board);
		candidates.erase(candidates.begin());
	}

	p_board[start_row][start_col] = 0; //reset start squares
	return backtrack(p_board);

}


int main() {
	//set board, starting point at 1,1, obstacles at 1,2 and 2,2, destination
	//at 1,3
	std::vector<std::vector<int>> board(4, std::vector<int>(4, INT_MAX));
	board[1][1] = -1, board[1][2] = -1, board[2][2] = -1;

	auto solution = a_star(board);

	std::cout << "The shortest path from start at (1, 1) to destination"
		<< " at (1,3) is:\n";
	for (auto rbeg = solution.rbegin();
		rbeg != solution.rend(); ++rbeg) {
		std::cout << "(" << rbeg->second.first << "," << rbeg->second.second
			<< ")\n";
	}

	std::cout << std::endl;

	return 0;
}