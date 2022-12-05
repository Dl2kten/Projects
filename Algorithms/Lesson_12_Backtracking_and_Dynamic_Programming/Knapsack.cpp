#include <iostream>
#include <vector>

/*
* Dynamic Programming - general design for solving optimization problems
* Knapsack Problem - find the most valuable subset of items that can fit into
* a knapsack that takes a given max weight, refer to Knapsack.odt for problem
* 
* Step 1 - decompose into simpler sub problems
* find the max value of various items at smaller max weights
* V[i, w] = max(V[i-1, w], vi + V[i-1, w-wi]), the max value of an item i at
* a certain max weight w, V[i-1, w] represents the max value of the previous
* item at that max weight w, vi + V[i-1, w-wi] represents if the max weights
* can fit current item plus previous items
* 
* Step 2 - express solution in terms of sub problem
* Derive the subsequent max values of items based on previous max values
* 
* Step 3 - use table to compute optimal value bottom up
* Create a table with W representing the max weight and i representing the
* items, and compute bottom up
* 
* Step 4 - find optimal solution based on step 1-3
* return solution
*/

/// <summary>
/// Finds the max value of a knapsack capable of holding p_weight based on
/// weights and values of items in p_items
/// </summary>
/// <param name="p_items"></param>
/// <param name="p_weight"></param>
/// <returns></returns>
unsigned knapsack_alg(const std::vector<std::pair<unsigned, unsigned>>& p_items,
	unsigned p_weight) {
	std::vector<std::vector<unsigned>> table(p_items.size(), 
		std::vector<unsigned>(p_weight + 1));
	
	//first row for item0 already set to 0, if not need to set explicitly

	for (decltype(table.size()) i = 1; i != table.size(); ++i) {
		for (decltype(table[0].size()) j = 0; j != table[0].size(); ++j) {
			if (p_items[i].first <= j) //if weight of item is less than max weight
				table[i][j] = std::max(table[i - 1][j],
					p_items[i].second + table[i - 1][j - p_items[i].first]);
			else
				table[i][j] = table[i - 1][j];
		}
	}

	return table[table.size() - 1][table[0].size() - 1];	
}

int main() {
	unsigned max_weight = 5;
	std::vector<std::pair<unsigned, unsigned>> items{
		{0,0}, {2, 12}, {1, 10}, {3, 20}, {2, 15}
	}; //vector of items, first of pair represents weight, second represents
	//value

	auto max_value = knapsack_alg(items, max_weight);

	std::cout << "The max value for the knapsack is: $" << max_value << std::endl;

	return 0;
}