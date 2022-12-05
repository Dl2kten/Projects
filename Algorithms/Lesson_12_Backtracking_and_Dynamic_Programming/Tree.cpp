#include "Tree.h"
#include <algorithm>
#include <iostream>

/// <summary>
/// Recursive call to destroy all child nodes
/// </summary>
/// <param name="leaf"></param>
void Tree::destroy_tree(Node* leaf) {
	if (leaf != nullptr) {
		destroy_tree(leaf->child);
		delete leaf;
	}
}


/// <summary>
/// Destructor
/// </summary>
Tree::~Tree() {
	destroy_tree(root);
}


/// <summary>
/// Mark squares as unavailable for a new queen to be added in accordance
/// with rules
/// </summary>
/// <param name="row"></param>
/// <param name="col"></param>
/// <param name="p_node"></param>
void Tree::add_dead_ends(std::size_t row, std::size_t col, Node* p_node) {
	int r = row, c = col;
	while (++r != dimension) { //make specific columns unavailable
		dead_ends[r].insert(col); //use set over vector instead
	}
	
	r = row, c = col;
	while (++c != dimension) { //make column to right invalid, need this for
		//map.at
		dead_ends[r].insert(c);
	}

	r = row, c = col;
	while (++c != dimension && ++r != dimension) { //make diagonals to right invalid
		dead_ends[r].insert(c);
	}

	r = row, c = col;
	while (--c >= 0 && ++r != dimension) { //make diagonals to left invalid
		dead_ends[r].insert(c);
	}

	p_node->board = dead_ends;

	dead_end_check();
}


/// <summary>
/// Insert a new node to the tree
/// </summary>
/// <param name="key"></param>
void Tree::insert(unsigned i, unsigned j) {

	if (dead_ends.empty()) {
		root->child = new Node(i, j);
		add_dead_ends(i, j, root->child);
	}
	else {
		if (dead_ends.at(i).find(j) ==
			dead_ends.at(i).end()) {
			Node* node = new Node(i, j);
			insert(node, root);
			add_dead_ends(i, j, node);
		}
	}
}


/// <summary>
/// Insert node to the correct position
/// </summary>
/// <param name="new_key"></param>
/// <param name="leaf"></param>
void Tree::insert(Node* node, Node* leaf) {
	if (leaf->child == nullptr) {
		leaf->child = node;
	}
	else {
		insert(node, leaf->child);
	}

}

/// <summary>
/// Removes child node that leads to dead end, backtrack to previous 
/// available choices
/// </summary>
/// <param name="p_child"></param>
void Tree::remove(Node* p_child) {

	if (p_child->child->child == nullptr) {
		dead_ends = p_child->board;
		//mark the square that went on to produce dead end as invalid
		dead_ends[p_child->child->row].insert(p_child->child->col); 
		p_child->board = dead_ends;

		delete p_child->child;
		p_child->child = nullptr;
		dead_end_check();
	}
	else {
		remove(p_child->child);
	}
}

/// <summary>
/// Check to see if a dead end has been reached, where there's no available
/// square to place the next queen
/// </summary>
void Tree::dead_end_check()
{
	for (const auto& i : dead_ends)
		if (i.second.size() == dimension) {
			remove(root);
			break;
		}

	if (dead_ends.size() == 1) {
		dead_end.first = true;
		dead_end.second = *dead_ends.begin()->second.begin();
		++dead_end.second;
	}
}

/// <summary>
/// Prints the positions of the placed queens
/// </summary>
/// <param name="os"></param>
/// <returns></returns>
std::ostream& Tree::print(std::ostream& os)
{
	for (auto beg = root->child; beg != nullptr; beg = beg->child) {
		os << "Queen" << beg->row + 1 << " at: row " << beg->row + 1 
			<< " col " << beg->col + 1 << std::endl;
	}

	return os;
}