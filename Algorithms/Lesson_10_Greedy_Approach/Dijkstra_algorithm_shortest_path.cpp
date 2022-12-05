#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>

/*
* Single-Source Shortest Path
* Dijkstra algorithm, used to find the shortest path from one source vertex to
* every other vertex in graph, refer to Dijkstra_graph
*/

/// <summary>
/// Function finds if there's a shorter path to vertex through one adjacent
/// vertex
/// </summary>
/// <param name="p_source"></param>
/// <param name="p_vertex"></param>
/// <param name="p_graph"></param>
/// <param name="p_solution"></param>
/// <returns></returns>
std::pair<std::string, unsigned> relax(
	std::pair<const char, std::map<unsigned, char>>& p_source,
	const std::pair<unsigned, char>& p_vertex,
	const std::unordered_map<char, std::map<unsigned, char>>& p_graph,
	const std::unordered_map<std::string, unsigned>& p_solution) {

	unsigned d_source_vertex = p_vertex.first, d_source_adjacent = 0;

	std::string temp(1, p_graph.begin()->first);
	temp += p_vertex.second;
	std::pair<std::string, unsigned> ret(temp, d_source_vertex);


	for (const auto& i : p_source.second) {
		if (i.second != p_vertex.second) { //check to see if any adjacent vertices
			if (i.first < p_vertex.first) { //have smaller weight
				d_source_adjacent = i.first;
				for (const auto& av :
					p_graph.at(i.second)) { //check if connects to vertex
					if (av.second == p_vertex.second)
						if (d_source_vertex > d_source_adjacent + av.first) {
							d_source_vertex = d_source_adjacent + av.first;
							ret.second = d_source_vertex;
						}
				}
			}
		}

	}

	//add distance from original source point, in this case vertex A
	temp[1] = p_source.first;
	d_source_vertex += p_solution.at(temp);
	ret.second = d_source_vertex;

	return ret;
}


/// <summary>
/// Dijkstra alg finds the shortest path to each vertex from a source vertex
/// </summary>
/// <param name="p_graph"></param>
/// <param name="p_solution"></param>
void Dijkstra_alg(std::unordered_map<char, std::map<unsigned, char>>& p_graph,
	std::unordered_map<std::string, unsigned>& p_solution) {

	//each iteration finds the shortest path to one vertex
	for (auto beg = p_graph.begin();
		beg != p_graph.end(); ++beg) {

		if (p_solution.size() == p_graph.size())
			break;
		//av for adjacent vertex
		for (const auto& av : beg->second) {
			auto found = std::find(beg->second.begin(),
				beg->second.end(), av);
			if (found != beg->second.end())
				p_solution.insert(relax(*beg, av, p_graph,
					p_solution));
		}
	}
}


int main() {
	std::multimap<unsigned, std::pair<char, std::map<unsigned, char>>> distance_sort{
		{0, {'A', {{10, 'B'}, {3, 'C'}}}},
		{11, {'B', {{2, 'D'}, {1, 'C'}}}},
		{20, {'E', {{9, 'D'}}}},
		{21, {'D', {{7, 'E'}}}},
		{10, {'C', {{4, 'B'}, {8, 'D'}, {2, 'E'}}}},

	}; //sort by distance from source point A and the weights of the adjacent 
	//C weight is less than B so given 10 vs 11 for B

	std::unordered_map<char, std::map<unsigned, char>> adjacency_list;
	for (const auto& i : distance_sort) {
		adjacency_list[i.second.first] = i.second.second;
	} 
	//I wanted to use a container where can call value by key, also considered
	//using a vector with a struct containing the map but each time to get a 
	//value wanted need to iterate to find the value, the at function time
	//complexity of unordered_map is constant for average case

	std::unordered_map<std::string, unsigned> solution{ {"AA", 0} };
	Dijkstra_alg(adjacency_list, solution);

	for (const auto& i : solution)
		std::cout << i.first << ":" << i.second << " ";
	std::cout << std::endl;

	return 0;
}