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

	// Getters
	AVLNode* get_root() const;
	int get_size() const;

	// Setters
	void set_root(AVLNode*);
	void set_size(int);

	// Utilities
	void make_child(AVLNode*, AVLNode*, bool);

	// BST functions
	bool is_empty() const;
	int get_height(AVLNode*);
	void add_node(string);		// Should this return anything?
	AVLNode* find_node(string);
	void insert_node(string);	// Should we combine this into add_node?
	AVLNode* get_youngest_ancestor(AVLNode*, bool);
	AVLNode* get_youngest_descendant(AVLNode*, bool);
	AVLNode* get_successor(AVLNode*);

	// AVL Functions
	AVLNode* get_tallest_child(AVLNode*);
	bool is_balanced(AVLNode*);
	void reset_height(AVLNode*);
	void rebalance(AVLNode*);
	void rebalance_ancestors(AVLNode*);
	void single_rotation(AVLNode*, AVLNode*);
	void double_rotation(AVLNode*, AVLNode*, AVLNode*);
};