#pragma once
/// <summary>
/// Represents a node on the binary tree
/// </summary>
struct Node {
	char key = ' ';
	Node* left = nullptr;
	Node* right = nullptr;
	Node* parent = nullptr;
};

/// <summary>
/// Binary tree
/// </summary>
/// <param name=""></param>
class Binary_tree {
public:
	Binary_tree() = default;
	~Binary_tree();

	void insert(char);
	int height();
	int leaves();
	const Node* getRoot() const { return root; }
private:
	void destroy_tree(Node*);
	void insert(char, Node*);
	int height(Node*);
	int leaves(Node*);
	Node* root;
};