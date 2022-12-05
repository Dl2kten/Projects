#include <iostream>
#include <list>
#include <unordered_map>
#include <algorithm>

/*
* Greedy Approach
* Using Prim's algorithm to find minimum spanning tree of graph, refer
* to Prim_Kruskal_problem for diagram
*/

std::list<std::pair<char, unsigned>> Prim_alg(
	std::unordered_map<char, std::list<std::pair<char, unsigned>>>& p_graph) {
	std::list<std::pair<char, unsigned>> edges, candidates;
	edges.push_back({ p_graph.begin()->first, 0 });
	//candidates
	
	for (decltype(p_graph.size()) i = 0; i < p_graph.size() - 1; ++i) {
		auto key = edges.back().first;
		
		//remove vertices visited from other vertices' adjacency list,
		//maybe can add a visited boolean value and use if statement instead
		for (auto beg = p_graph.begin();
			beg != p_graph.end(); ++beg) {
			for (auto list_beg = beg->second.begin();
				list_beg != beg->second.end(); ++list_beg) {
				if (list_beg->first == key) {
					beg->second.remove(*list_beg);
					break;
				}
			}
		}

		auto edge = *p_graph[key].begin();
		auto min = p_graph[key].begin()->second;
		
		candidates.insert(candidates.end(), p_graph[key].begin(),
			p_graph[key].end());//insert all distance from adjacent 
		//vertices as candidate edges


		for (const auto& i : candidates) {
			if (i.second < min) { //find adjacent vertex with lowest edge value
				edge = i;
			}
		}

		auto temp = candidates;
		for (auto beg = temp.begin(); 
			beg != temp.end(); ++beg) {
			if (beg->first == edge.first)
				candidates.remove(*beg);
		}
				
		
		edges.push_back(edge);
	}
	
	return edges;
}

int main() {
	std::unordered_map<char, std::list<std::pair<char, unsigned>>> adjacency_list {
		{'a', { {'b', 10}, {'e', 5}, {'f', 4} }},
		{'b', { {'a', 10}, {'c', 6}, {'d', 9}, {'e', 8} }},
		{ 'c', { {'b', 6}, {'d', 4}, {'e', 15} }},
		{ 'd', { {'b', 9}, {'c', 4}, {'e', 12} }},
		{ 'e', { {'a', 5}, {'b', 8}, {'c', 15}, {'d', 12}, {'f', 3} }},
		{ 'f', { {'a', 4}, {'e', 3} }}
	};

	auto solution = Prim_alg(adjacency_list);

	//did some formatting
	for (auto beg = solution.cbegin(), check = beg; 
		beg != solution.cend(); ++beg) {
		++check;
		if (beg == solution.cbegin()) {
			std::cout << beg->first;
		}
		else if (check == solution.cend()) {
			std::cout << "-" << beg->first << ":" << beg->second;
		}
		else {
			std::cout << "-" << beg->first << ":" << beg->second << " " << beg->first;
		}
	}
	std::cout << std::endl;
	return 0;
}