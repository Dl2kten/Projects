#include <iostream>
#include <list>
#include <unordered_map>

/*
* Graph algorithm
* Topological sort of work tasks using Decrease by one
* Refer to Work_tasks_decrease_by_one for task order and directed acyclic graph
*/

/// <summary>
/// Holds the data of a vertex, including its adjacent vertices and the number
/// of vertices that needs to be visited before visiting this vertex
/// </summary>
struct vertex {
	vertex() : in_degree(0) {}
	vertex(unsigned i) : in_degree(i) {}
	vertex(std::initializer_list<char> cil, unsigned i) : in_degree(i) {

		for (auto beg = cil.begin(); beg != cil.end(); ++beg)
			adjacent_vertex.push_back(*beg);
	}
	std::list<char> adjacent_vertex;
	unsigned in_degree;
};

/// <summary>
/// Removes vertices using decrease by one, starting from vertices with no
/// in_degrees which subtract edges from other vertices and cause them to
/// have no in_degrees, until either graph is empty or no feasible solution
/// is reached
/// </summary>
/// <param name="p_graph"></param>
/// <param name="p_solution"></param>
/// <returns></returns>
bool topo_sort(std::unordered_map<char, vertex>& p_graph,
	std::list<char>& p_solution) {
	std::list<std::pair<char,vertex>> candidates;
	for (const auto& i : p_graph)
		//start at vertex that does not need to be visited by any 
		//other vertices, add all vertices with in_degree == 0
		if (i.second.in_degree == 0) 
			candidates.push_back({ i.first,i.second });

	while (!candidates.empty()) {
		auto v = candidates.begin();
		p_solution.push_back(v->first); //push vertex onto solution
		for (auto& i : v->second.adjacent_vertex) {
			--p_graph[i].in_degree;
			if (p_graph[i].in_degree == 0)
				candidates.push_back({ i, p_graph[i] });
		}
		//erase vertex from candidates and graph
		p_graph.erase(v->first);
		candidates.erase(v);
	}
	
	if (!p_graph.empty()) //if vertices remain
		return false;

	return true;
}



int main() {
	std::unordered_map<char, vertex> adjacency_list{ {'d', 
		vertex({'a', 'b', 'c', 'e'}, 0)}, {'a', vertex({'b', 'c'}, 1)}, 
		{'b', vertex({'c', 'e'}, 2)}, {'c', vertex({'e'}, 3)}, 
		{'e', vertex(3)} };
	std::list<char> solution;

	auto dag = topo_sort(adjacency_list, solution);

	if (dag) {
		for (const auto& i : solution)
			std::cout << i << " ";
		std::cout << std::endl;
	}
	
	return 0;
}