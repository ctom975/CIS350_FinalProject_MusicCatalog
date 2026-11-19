#pragma once
#include "iostream"
#include "string"
#include "AVLNode.h"

using namespace std;
class AVLTree
{
private:
	AVLNode* root = nullptr;
	int size = 0;
public:
	AVLTree();
	~AVLTree();

	// Getters
	AVLNode* get_root() const;
	int get_size() const;

	// Setters
	void set_root(AVLNode*);
	void set_size(int);

	// Utilities
	void make_child(AVLNode*, AVLNode*, bool);
	void delete_tree(AVLNode*);
	bool contains(string);

	// BST functions
	bool is_empty() const;
	int get_height(AVLNode*);
	AVLNode* add_node(string);
	AVLNode* find_node(string);
	AVLNode* get_youngest_ancestor(AVLNode*, bool);
	AVLNode* get_youngest_descendant(AVLNode*, bool);
	AVLNode* get_successor(AVLNode*);

	// AVL Functions
	AVLNode* get_tallest_child(AVLNode*);
	bool is_balanced(AVLNode*);
	void reset_height(AVLNode*);
	AVLNode* rebalance(AVLNode*);
	void rebalance_ancestors(AVLNode*);
	void single_rotation(AVLNode*, AVLNode*);
	void double_rotation(AVLNode*, AVLNode*, AVLNode*);
};