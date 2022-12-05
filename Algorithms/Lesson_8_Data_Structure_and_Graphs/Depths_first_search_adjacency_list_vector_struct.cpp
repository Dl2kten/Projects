#include <iostream>
#include <list>
#include <vector>

/*
* Data structure and graph
* Depth First Search, visits all vertices by always moving away from last
* vertex visited if possible, backtracks if no more unvisited adjacent
* vertices, recursion behaves like stack
*/

/// <summary>
/// Holds the data of a vertex, including its adjacent vertices, and 
/// whether been visited or not
/// </summary>
struct vertex {
	vertex(std::initializer_list<char> cil) : vertex_value(*cil.begin()),
	visited(false) {

		for(auto beg = cil.begin() + 1; beg != cil.end(); ++beg)
			adjacent_vertex.push_back(*beg);
	}

	char vertex_value;
	std::list<char> adjacent_vertex;
	bool visited;
};


/// <summary>
/// Does the work, checks to see if vertex and its adjacent vertices are visited
/// </summary>
/// <param name="v"></param>
/// <param name="p_graph"></param>
/// <param name="p2_result"></param>
void dfs(vertex& v, std::vector<vertex>& p_graph, 
	std::vector<vertex>& p2_result) {
	v.visited = true;
	p2_result.push_back(v);
	for (auto& i : v.adjacent_vertex) {//check if adjacent vertex are
		//visited
		for (auto& j : p_graph) {//this step takes too many comparisons
			//maybe use map? p_graph map of <char, vertex>
			if (i == j.vertex_value) {
				if(j.visited == false) { //if not visited, visit
					dfs(j, p_graph, p2_result);
				}
				break;
			}		
		}
	}
}

/// <summary>
/// Starts the search using depth first search
/// </summary>
/// <param name="p_graph"></param>
/// <param name="p1_result"></param>
void DFS(std::vector<vertex>& p_graph, 
	std::vector<vertex>& p1_result) {
	for (auto& i : p_graph) {
		if (i.visited == false)
			dfs(i, p_graph, p1_result);
	}
}


int main() {
	std::vector<vertex> adjacency_list { {'a', 'b', 'c'}, 
		{ 'b', 'f', 'g' }, { 'c', 'd', 'g' }, { 'd', 'c', 'h' }, 
		{ 'e', 'a', 'f' }, { 'f', 'e' }, { 'g', 'c', 'h' }, { 'h', 'd', 'g' }};
	//refer to included readme to see graph diagram

	std::vector<vertex> result;
	DFS(adjacency_list, result);

	for (const auto& i : result)
		std::cout << i.vertex_value << " ";
	std::cout << std::endl;

	return 0;
}