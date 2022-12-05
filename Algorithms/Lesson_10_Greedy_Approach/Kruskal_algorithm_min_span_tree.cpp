#include <iostream>
#include <map>
#include <algorithm>
#include <set>
#include <vector>
#include "Disjoint_set.h"
/*
* Greedy Approach
* Using Kruskal's algorithm to find minimum spanning tree of graph, refer
* to Prim_Kruskal_problem for diagram
*/

void Kruskal_alg(const std::vector<char>& p_v, 
	const std::multimap<unsigned, std::string>& p_e, 
	std::multimap<unsigned, std::string>& solution){
	Disjoint_set ds;

	//make each vertex its own set
	for (const auto& i : p_v)
		ds.make_set(i);

	auto beg = p_e.begin();

	while(solution.size() != p_v.size() - 1 && beg != p_e.end()) {
		//find the sets the vertices are in
		auto cu = ds.find(beg->second[0]);
		auto cv = ds.find(beg->second[1]);

		if (cu != cv) {//if different sets
			solution.insert(*beg);
			ds.combine(cu, cv);
		}

		++beg;
	}
}

int main() {
	std::vector<char> vertices{ 'a', 'b', 'c', 'd', 'e', 'f' };
	std::multimap<unsigned, std::string> edges { {4, "af"}, { 10, "ab" }, 
		{ 6, "bc" }, { 4, "cd" }, { 12, "de" }, { 3, "ef" }, { 5, "ae" }, 
		{ 8, "be" }, { 9, "bc" }, { 15, "ce" } };
	std::multimap<unsigned, std::string> solution;

	Kruskal_alg(vertices, edges, solution);

	for (const auto& i : solution)
		std::cout << i.second << ":" << i.first << " ";
	std::cout << std::endl;
	/*
	* Efficiency suppose to be defined by initial sort on edge weights and
	* O(ElogE), E is edges, but I have a double for in find...
	*/
	return 0;
}