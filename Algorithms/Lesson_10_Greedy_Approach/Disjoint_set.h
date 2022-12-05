#pragma once
#include <set>
#include <vector>

/// <summary>
/// Disjoint subsets means that elements are only in one subset at a time 
/// </summary>
class Disjoint_set {
public:
	Disjoint_set() = default;

	void make_set(char);
	std::set<char> find(char);
	void combine(std::set<char>, std::set<char>);

private:
	std::vector<std::set<char>> set_list;
};