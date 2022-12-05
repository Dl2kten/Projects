#include "Binary_tree.h"
#include <algorithm>

/// <summary>
/// 
/// </summary>
/// <param name="leaf"></param>
void Binary_tree::destroy_tree(Node* leaf) {
	if (leaf != nullptr) {
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

/// <summary>
/// 
/// </summary>
Binary_tree::~Binary_tree() {
	destroy_tree(root);
}

/// <summary>
/// 
/// </summary>
/// <param name="key"></param>
void Binary_tree::insert(int key) {
	if (root == nullptr) {//if object was created with default constructor
		root = new Node();
		root->key = key;
	}
	else {
		insert(key, root);
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="new_key"></param>
/// <param name="leaf"></param>
void Binary_tree::insert(int new_key, Node* leaf) {

	if (new_key <= leaf->key) {
		if (leaf->left != nullptr)
			insert(new_key, leaf->left);
		else {
			leaf->left = new Node();
			leaf->left->key = new_key;
			leaf->left->parent = leaf;
		}
	}//end of inserting new key smaller than leaf 
	else {
		if (leaf->right != nullptr)
			insert(new_key, leaf->right);
		else {
			leaf->right = new Node();
			leaf->right->key = new_key;
			leaf->right->parent = leaf;
		}
	}

}


/// <summary>
/// 
/// </summary>
/// <param name="n"></param>
/// <returns></returns>
int Binary_tree::height(Node* n) {
	if (n == nullptr)
		return 0;

	return std::max(height(n->left),
		height(n->right)) + 1;
}

/// <summary>
/// Process height of tree, user does not need to call root
/// </summary>
/// <returns></returns>
int Binary_tree::height() {
	if (root == nullptr)
		return 0;

	return std::max(height(root->left),
		height(root->right)) + 1;
}

/// <summary>
/// 
/// </summary>
/// <param name="n"></param>
/// <returns></returns>
int Binary_tree::leaves(Node* n) {
	if (n == nullptr)
		return 0;

	if (n->left == nullptr && n->right == nullptr)
		return 1;

	return leaves(n->left) + leaves(n->right) + 1;
}

/// <summary>
/// Count number of nodes, user need not pass root
/// </summary>
/// <returns></returns>
int Binary_tree::leaves() {
	if (root == nullptr)
		return 0;

	if (root->left == nullptr && root->right == nullptr)
		return 1;

	return leaves(root->left) + leaves(root->right);
}