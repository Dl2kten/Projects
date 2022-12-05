#include <iostream>
#include "Binary_tree.h"

/*
* Binary Tree Traversal
* Will traverse tree in three different orders, pre-order, in-order, and
* post-order, refer to Binary_tree_diagram for image
*/

/// <summary>
/// Pre order traversal, starts at root goes to left most before going back to
/// right most
/// </summary>
/// <param name="p_root"></param>
void pre_order_traversal_print(const Node* p_root) {
	if (p_root == nullptr)
		return;
	std::cout << p_root->key << " ";
	pre_order_traversal_print(p_root->left);
	pre_order_traversal_print(p_root->right);
}


/// <summary>
/// In order traversal, goes to left most, prints parent before going right
/// </summary>
/// <param name="p_root"></param>
void in_order_traversal_print(const Node* p_root) {
	if (p_root == nullptr)
		return;
	in_order_traversal_print(p_root->left);
	std::cout << p_root->key << " ";
	in_order_traversal_print(p_root->right);
}


/// <summary>
/// Post order traversal, starts from left most, goes right, printing child
/// nodes and then parent nodes, root parent printed last
/// </summary>
/// <param name="p_root"></param>
void post_order_traversal_print(const Node* p_root) {
	if (p_root == nullptr)
		return;
	post_order_traversal_print(p_root->left);
	post_order_traversal_print(p_root->right);
	std::cout << p_root->key << " ";
}

int main() {
	
	Binary_tree bt;

	bt.insert('l');
	bt.insert('e');
	bt.insert('o');
	bt.insert('b');
	bt.insert('g');
	bt.insert('n');
	bt.insert('d');
	
	const Node* root = bt.getRoot();
	pre_order_traversal_print(root);
	std::cout << std::endl;

	in_order_traversal_print(root);
	std::cout << std::endl;

	post_order_traversal_print(root);
	std::cout << std::endl;
	return 0;
}