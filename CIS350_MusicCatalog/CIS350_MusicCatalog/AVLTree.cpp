#include "AVLTree.h"

AVLTree::AVLTree()
{
	// Doesn't need anything here
}

// Getters
AVLNode* AVLTree::get_root() const
{
	return root;
}
int AVLTree::get_size() const
{
	return size;
}

// Setters
void AVLTree::set_root(AVLNode* r)
{
	root = r;
}
void AVLTree::set_size(int s)
{
	size = s;
}

// Utilities
void AVLTree::make_child(AVLNode*, AVLNode*, bool)
{

}

// BST functions
bool AVLTree::is_empty() const
{
	// Tree is empty when root is null
	return root == nullptr;
}
int AVLTree::get_height(AVLNode* w)
{
	if (w == nullptr)
	{
		// Height of a null node is -1
		return -1;	// should this be 0?
	}

	return w->get_height();
}
void AVLTree::add_node(string name)
{
	
}
AVLNode* AVLTree::find_node(string name)
{
	
}
void AVLTree::insert_node(string name)
{
	
}
AVLNode* AVLTree::get_youngest_ancestor(AVLNode* w, bool check_left)
{

}
AVLNode* AVLTree::get_youngest_descendant(AVLNode* w, bool check_left)
{
	
}
AVLNode* AVLTree::get_successor(AVLNode* w)
{
	
}

// AVL Functions
AVLNode* AVLTree::get_tallest_child(AVLNode* w)
{
	
}
bool AVLTree::is_balanced(AVLNode* w)
{
	// height(right child) - height(left child)
	return abs(get_height(w->get_right()) - get_height(w->get_left())) <= 1;
}
void AVLTree::reset_height(AVLNode* w)
{
	
}
void AVLTree::rebalance(AVLNode* w)
{
	
}
void AVLTree::rebalance_ancestors(AVLNode* w)
{
	
}
void AVLTree::single_rotation(AVLNode* y, AVLNode* z)
{
	
}
void AVLTree::double_rotation(AVLNode* x, AVLNode* y, AVLNode* z)
{
	
}