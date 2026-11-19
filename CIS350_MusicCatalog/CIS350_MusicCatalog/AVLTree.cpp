#include "AVLTree.h"

AVLTree::AVLTree()
{
	// Doesn't need anything here
}

AVLTree::~AVLTree()
{
	delete_tree(root);
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
bool AVLTree::contains(string excerpt_name)
{
	// Check if the tree contains a node with the specified Excerpt name
	AVLNode* w = find_node(excerpt_name);
	return (w != nullptr && w->get_name() == excerpt_name);
}

void AVLTree::delete_tree(AVLNode* w)
{
	// Recursively delete all nodes in the tree
	if (w != nullptr)
	{
		delete_tree(w->get_left());
		delete_tree(w->get_right());
		delete w;
	}
}

void AVLTree::make_child(AVLNode* p, AVLNode* c, bool is_left)
{
	// Set node c as the child of node p
	if (p != nullptr)
	{
		if (is_left)
		{
			// c becomes left child of p
			p->set_left(c);
		}
		else
		{
			// c becomes right child of p
			p->set_right(c);
		}
	}
	if (c != nullptr)
	{
		// p becomes parent of c if c is a node
		c->set_parent(p);
	}
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
AVLNode* AVLTree::add_node(string name)
{
	// Find the node with the name, if it exists
	AVLNode* w = find_node(name);

	// Create new node
	AVLNode* x = new AVLNode(name);

	// Make new node child of found node, if it exists
	if (w == nullptr)
	{
		// Empty tree. New node becomes root
		set_root(x);
	}
	else
	{
		make_child(w, x, w->get_name() > name);
	}
	set_size(get_size() + 1);

	// Rebalance all ancestors of new node
	if (x->get_parent() != nullptr)
	{
		rebalance_ancestors(x->get_parent());
	}

	// Return new node
	return x;
}
AVLNode* AVLTree::find_node(string name)
{
	AVLNode* w = get_root();	// Current node
	AVLNode* z = nullptr;		// Found node

	// While current node is not none and name not found
	while (w != nullptr && w->get_name() != name)
	{
		z = w;

		// Search for either left or right child
		w = (w->get_name() > name) ? w->get_left() : w->get_right();
	}

	// Returns the last visited node in search (If name found, will be node with name)
	return (w == nullptr) ? z : w;
}
AVLNode* AVLTree::get_youngest_ancestor(AVLNode* w, bool check_left)
{
	if (w == nullptr)
	{
		return nullptr;
	}

	AVLNode* z = w;					// w
	AVLNode* x = z->get_parent();	// w's parent

	// Keep going up the tree until x becomes null or z is no longer a child of x
	while (x != nullptr && (check_left ? x->get_left() : x->get_right()) == z)
	{
		z = x;
		x = x->get_parent();
	}
	
	// Return youngest ancestor
	return x;
}
AVLNode* AVLTree::get_youngest_descendant(AVLNode* w, bool check_left)
{
	if (w == nullptr)
	{
		return nullptr;
	}

	// Keep going down the tree until one of w's children is null
	while ((check_left ? w->get_left() : w->get_right()) != nullptr)
	{
		w = check_left ? w->get_left() : w->get_right();
	}

	// Return youngest descendant
	return w;
}
AVLNode* AVLTree::get_successor(AVLNode* w)
{
	if (w == nullptr)
	{
		return nullptr;
	}

	// If w has no right child, then successor will be an ancestor
	if (w->get_right() == nullptr)
	{
		return get_youngest_ancestor(w, true);
	}

	// Successor is in the right subtree
	return get_youngest_descendant(w, true);
}

// AVL Functions
AVLNode* AVLTree::get_tallest_child(AVLNode* w)
{
	// Get height of left and right child
	int h_left = get_height(w->get_left());
	int h_right = get_height(w->get_right());

	// Return whichever child has highest height (Favor left child)
	return (h_left >= h_right) ? w->get_left() : w->get_right();
}
bool AVLTree::is_balanced(AVLNode* w)
{
	// height(right child) - height(left child)
	return abs(get_height(w->get_right()) - get_height(w->get_left())) <= 1;
}
void AVLTree::reset_height(AVLNode* w)
{
	w->set_height(max(get_height(w->get_left()), get_height(w->get_right())) + 1);
}
AVLNode* AVLTree::rebalance(AVLNode* w)
{
	// Root node of subtree rooted at w
	AVLNode* r = w;

	if (r == nullptr)
	{
		return nullptr;
	}

	// Get tallest child of w and y
	AVLNode* y = get_tallest_child(r);
	AVLNode* x = get_tallest_child(y);

	// Single Rotation: r, y, x form a straight line
	if ((r->get_left() == y && y->get_left() == x) || (r->get_right() == y && y->get_right() == x))
	{
		// Rotate once left or right
		single_rotation(y, w);

		// y becomes new root
		r = y;
	}

	// Double Rotation: r, y, x form a bend (< or >)
	else if ((r->get_left() == y && y->get_right() == x) || (r->get_right() == y && y->get_left() == x))
	{
		// Rotate twice
		double_rotation(x, y, w);

		// x becomes new root
		r = x;
	}

	// Return new root of subtree
	return r;
}
void AVLTree::rebalance_ancestors(AVLNode* w)
{
	while (w != nullptr)
	{
		AVLNode* x = w->get_parent();
		int old_height = get_height(w);

		if (is_balanced(w))
		{
			// Already balanced. Reset the height of w
			reset_height(w);
		}
		else
		{
			// Unbalanced. Reblanace w
			w = rebalance(w);

			if (x == nullptr)
			{
				// w has no parent. Therefore, it should be root of tree
				set_root(w);
			}
		}

		// Used to break out of loop early. If height changed, w becomes its parent.
		w = (old_height == get_height(w) ? nullptr : x);
	}
}
void AVLTree::single_rotation(AVLNode* y, AVLNode* z)
{
	if (z->get_left() == y)
	{
		// Rotate right
		AVLNode* x = y->get_right();	// Right child of y
		AVLNode* p = z->get_parent();	// Parent of z

		// z becomes right child of y
		make_child(y, z, false);

		// x becomes left child of z
		make_child(z, x, true);

		// y becomes child of p
		make_child(p, y, p != nullptr && p->get_left() == z);
	}
	else
	{
		// Rotate left
		AVLNode* x = y->get_left();	// Left child of y
		AVLNode* p = z->get_parent();	// Parent of z

		// z becomes right child of y
		make_child(y, z, true);

		// x becomes left child of z
		make_child(z, x, false);

		// y becomes child of p
		make_child(p, y, p != nullptr && p->get_left() == z);
	}

	// Recalculate heights of all affected nodes up the tree
	AVLNode* w = z;
	while (w != nullptr)
	{
		reset_height(w);
		w = w->get_parent();
	}
}
void AVLTree::double_rotation(AVLNode* x, AVLNode* y, AVLNode* z)
{
	single_rotation(x, y);
	single_rotation(x, z);
}