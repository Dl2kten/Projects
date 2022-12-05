#include <iostream>
#include <vector>
#include <list>

/*
* Exercise 13.28
* Given classes from text, implement default constructor and necessary
* copy-control members
*/

class TreeNode {
public:
	TreeNode(const std::string& s = std::string()) : value(s),
		count(0), left(nullptr), right(nullptr) {}
	TreeNode(const TreeNode&);
	TreeNode& operator=(const TreeNode&);
private:
	std::string value;
	int count;
	TreeNode* left;
	TreeNode* right;
};

class BinStrTree {
public:

private:
	TreeNode* root;
};



int main() {

	


	return 0;
}