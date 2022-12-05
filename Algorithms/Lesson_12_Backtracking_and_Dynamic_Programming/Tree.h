#pragma once
#include <map>
#include <memory>
#include <set>

/// <summary>
/// Node represents the addition of a queen to the board, includes
/// the queen's positions and how it changes the board
/// </summary>
struct Node {
	Node() {}
	Node(unsigned r, unsigned c) : row(r), col(c) {}

	int row = -1, col = -1;
	Node* child = nullptr;
	std::map<std::size_t, std::set<std::size_t>> board; //records state of
	//board after a queen is added, including the invalid squares
};

/// <summary>
/// Tree represents the choice of nodes added that lead to the solution
/// </summary>
class Tree {
public:
	Tree() = default;
	Tree(std::size_t n) : dimension(n) {}
	~Tree();

	void insert(unsigned, unsigned);
	std::pair<bool, unsigned>& get_dead_end() { return dead_end; }
	void set_dead_end() { dead_end.first = false; }
	std::ostream& print(std::ostream& os);
private:
	void destroy_tree(Node*);
	void insert(Node*, Node*);
	void remove(Node*);
	void add_dead_ends(std::size_t, std::size_t, Node*);
	void dead_end_check();

	int path = 0;
	std::size_t dimension = 0;
	std::pair<bool, unsigned> dead_end{false, 0};
	Node* root = new Node();
	std::map<std::size_t, std::set<std::size_t>> dead_ends;
};