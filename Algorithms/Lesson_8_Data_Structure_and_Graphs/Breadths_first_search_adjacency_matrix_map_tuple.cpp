#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <tuple>
#include <deque>
/*
* Data structure and graph
* Breadths First Search using adjacency matrix, visits graph vertices by 
* visiting all neighbours of last visited vertex
*/

using vertex = std::tuple<std::vector<int>, bool>;


/// <summary>
/// Does work of bfs, visits all the vertices adjacent to node, uses queue
/// structure
/// </summary>
/// <param name="node"></param>
/// <param name="p2_graph"></param>
/// <param name="p_result"></param>
void bfs(std::pair<const char, vertex>& node, std::map<char, vertex>& p2_graph,
	std::vector<char>& p_result)
{
	std::get<1>(node.second) = true; //visited set to true
	std::deque<char> q;
	q.push_back(node.first); //add vertex to queue

	while (!q.empty()) {
		auto cnt = -1;
		for (auto& i : std::get<0>(p2_graph[*q.begin()])) {
			++cnt;
			if (i == 1) {
				char check = cnt + 97; //convert from int to ascii
				
				if (std::get<1>(p2_graph[check]) == false) {
					std::get<1>(p2_graph[check]) = true; //visit
					q.push_back(check);
				}
			}
		}

		p_result.push_back(q.front());
		q.pop_front(); //remove the first vertex
	}
}


/// <summary>
/// Starts Breadth First Search
/// </summary>
/// <param name="p1_graph"></param>
/// <param name="p_result"></param>
void BFS(std::map<char, vertex>& p1_graph, std::vector<char>& p_result) {
	for (auto& i : p1_graph)
		if (std::get<1>(i.second) == false)
			bfs(i, p1_graph, p_result);
}


int main() {
	
	std::map<char, vertex> adjacency_matrix{ {'a', 
		vertex({0, 1, 0, 0, 1, 0, 0, 0}, false) }, { 'b',
		vertex({0, 0, 0, 0, 0, 1, 1, 0}, false) }, { 'c',
		vertex({0, 0, 0, 1, 0, 0, 1, 0}, false) }, { 'd',
		vertex({0, 0, 1, 0, 0, 0, 0, 1}, false) }, { 'e',
		vertex({1, 0, 0, 0, 0, 1, 0, 0}, false) }, { 'f',
		vertex({0, 1, 0, 0, 1, 0, 0, 0}, false) }, { 'g',
		vertex({0, 1, 1, 0, 0, 0, 0, 1}, false) }, { 'h',
		vertex({0, 0, 1, 0, 0, 0, 1, 0}, false) }};

	std::vector<char> result;
	BFS(adjacency_matrix, result);

	for (const auto& i : result)
		std::cout << i << " ";
	std::cout << std::endl;

	//Efficiency of adjacency_matrix is |V|^2 where V is set of all vertices,
	//Efficiency of adjacency_list is |V| + |E|, where V is set of all vertices,
	//E is set of all edges
	return 0;
}