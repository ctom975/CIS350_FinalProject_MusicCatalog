#include "AVLNode.h"

// Constructor
AVLNode::AVLNode()
{
	
}
AVLNode::AVLNode(string n)
{
	name = n;
}

// Getters
string AVLNode::get_name() const
{
	return name;
}
int AVLNode::get_height() const
{
	return height;
}
AVLNode* AVLNode::get_parent() const
{
	return parent;
}
AVLNode* AVLNode::get_left() const
{
	return left_child;
}
AVLNode* AVLNode::get_right() const
{
	return right_child;
}

// Setters
void AVLNode::set_name(string n)
{
	name = n;
}
void AVLNode::set_height(int h)
{
	height = h;
}
void AVLNode::set_parent(AVLNode* p)
{
	parent = p;
}
void AVLNode::set_left(AVLNode* l)
{
	left_child = l;
}
void AVLNode::set_right(AVLNode* r)
{
	right_child = r;
}