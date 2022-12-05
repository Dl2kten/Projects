#include <iostream>
#include <list>
#include <unordered_map>

/*
* Graph algorithm
* Topological sort of work tasks using Depths First Search
* Refer to Work_tasks_dfs for task order and directed acyclic graph
*/

/// <summary>
/// Holds the data of a vertex, including its adjacent vertices, and 
/// whether been visited or not
/// </summary>
struct vertex {
	vertex() : visited(false) {}
	vertex(std::initializer_list<int> cil) :visited(false) {

		for (auto beg = cil.begin(); beg != cil.end(); ++beg)
			adjacent_vertex.push_back(*beg);
	}
	std::list<int> adjacent_vertex;
	bool visited;
};

/// <summary>
/// Does the work, checks to see if vertex and its adjacent vertices are 
/// visited, each time recursive call, like putting a vertex on a stack,
/// p_results store the vertices visited in order of pop off of vertices off
/// stack
/// </summary>
/// <param name="v"></param>
/// <param name="p_graph"></param>
/// <param name="p2_result"></param>
void dfs(int p_key, vertex& v, std::unordered_map<int, vertex>& p_graph, 
	std::list<int>& p_results) {
	v.visited = true;

	for (auto& i : v.adjacent_vertex) {//check if adjacent vertex are
		//visited
		if (p_graph[i].visited == false) {
			dfs(i, p_graph[i], p_graph, p_results);
		}
	}

	p_results.push_back(p_key);
}

/// <summary>
/// Starts the search using depth first search
/// </summary>
/// <param name="p_graph"></param>
/// <param name="p1_result"></param>
void DFS(std::unordered_map<int, vertex>& p_graph, std::list<int>& p_results) {
	for (auto& i : p_graph) {
		if (i.second.visited == false)
			dfs(i.first, i.second, p_graph, p_results);
	}
}


int main() {
	std::unordered_map<int, vertex> adjacency_list{ {5, vertex({1, 2, 6})}, 
		{1, vertex({4, 3})}, {2, vertex({3, 4, 1})}, {3, vertex()}, 
		{4, vertex({3})}, {6, vertex({2, 3})} };
	std::list<int> results;

	DFS(adjacency_list, results);

	//since results store the pop off order of stack, must be reversed for
	//correct order of tasks completed
	for (auto rbeg = results.crbegin(); rbeg !=
		results.crend(); ++rbeg)
		std::cout << *rbeg << " ";
	std::cout << std::endl;

	return 0;
}