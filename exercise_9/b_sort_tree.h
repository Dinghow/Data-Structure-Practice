#include<iostream>

using namespace std;

class Node {
public:
	int value;
	Node* left_child;
	Node* right_child;
	Node(int m_value):value(m_value),left_child(NULL),right_child(NULL){}
};

class BST {
private:
	Node* root;
public:
	BST():root(NULL){}
	Node* getRoot() { return root; }
	void inorder(Node* node);
	void addChild(Node* node,Node* new_node);
	void searchNode(Node* node,int value,bool& flag);
};

//Output the tree in inorder traversal
void BST::inorder(Node* node) {
	if (node->left_child)
		inorder(node->left_child);
	cout << node->value << "->";
	if (node->right_child)
		inorder(node->right_child);
}

//Add child to the tree
void BST::addChild(Node* node,Node* new_node) {
	if (!node && node!=root)
		return;
	if (node == root && node == NULL) {
		root = new_node;
		return;
	}
	if (node->value == new_node->value) {
		cout << "The input key <" << node->value << "> have been in!" << endl;
		return;
	}
	else if (new_node->value > node->value) {
		if (!node->right_child) {
			node->right_child = new_node;
			return;
		}
		else
			addChild(node->right_child, new_node);
	}
	else {
		if (!node->left_child) {
			node->left_child = new_node;
			return;
		}
		else
			addChild(node->left_child, new_node);
	}
}

//Search node in the tree
void BST::searchNode(Node* node, int value, bool& flag) {
	if (node == NULL)
		return;
	else {
		if (node->value == value) {
			cout << "search success!" << endl;
			flag = true;
		}
		else if (node->value > value)
			searchNode(node->left_child, value,flag);
		else
			searchNode(node->right_child, value,flag);
	}
}
