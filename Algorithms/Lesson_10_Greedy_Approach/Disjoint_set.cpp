#include "Disjoint_set.h"

/// <summary>
/// Creates subset
/// </summary>
/// <param name="c"></param>
void Disjoint_set::make_set(char c)
{
	set_list.push_back({ c });
}

/// <summary>
/// Finds the subset the char is part of
/// </summary>
/// <param name="c"></param>
/// <returns></returns>
std::set<char> Disjoint_set::find(char c)
{
	auto ret = set_list.begin();

	//better way to do this? even if use string has to check char in string
	for (; ret != set_list.end(); ++ret) {
		auto found = std::find(ret->begin(),
			ret->end(), c);
		if (found != ret->end())
			break;
	}

	return *ret;
}


/// <summary>
/// Combines two subsets
/// </summary>
/// <param name="p_u"></param>
/// <param name="p_v"></param>
void Disjoint_set::combine(std::set<char> p_u, std::set<char> p_v)
{

	decltype(set_list.size()) u = 0, v = 0;
	for (auto i = u; i != set_list.size(); ++i) {
		std::set<char> temp;
		//auto iter = std::set_symmetric_difference(set_list[i].begin(),
		//	set_list[i].end(), p_u.begin(), p_u.end(), temp.begin());
		if (set_list[i] == p_u)
			u = i;
		if (set_list[i] == p_v)
			v = i;
	}

	std::set<char> dest(set_list[u]);
	dest.insert(set_list[v].begin(), set_list[v].end());
	set_list.push_back(dest);

	//erase the one further first so iterator position valid for the nearer one
	if (u > v) {
		set_list.erase(set_list.begin() + u);
		set_list.erase(set_list.begin() + v);
	}
	else {
		set_list.erase(set_list.begin() + v);
		set_list.erase(set_list.begin() + u);
	}

}