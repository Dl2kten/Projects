#pragma once
/// <summary>
/// 
/// </summary>
struct Node {
	int key = ' ';
	Node* left = nullptr;
	Node* right = nullptr;
	Node* parent = nullptr;
};

/// <summary>
/// 
/// </summary>
/// <param name=""></param>
class Binary_tree {
public:
	Binary_tree() = default;
	~Binary_tree();

	void insert(int);
	int height();
	int leaves();
private:
	void destroy_tree(Node*);
	void insert(int, Node*);
	int height(Node*);
	int leaves(Node*);
	Node* root;
};