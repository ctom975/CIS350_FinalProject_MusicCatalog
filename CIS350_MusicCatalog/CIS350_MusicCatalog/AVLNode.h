#pragma once
#include "iostream"
#include "string"

using namespace std;
class AVLNode
{
	private:
		string name;		// Name from Excerpt item
		int height = 0;		// Assume leaf: Height of leaf is 0
		AVLNode* left_child = nullptr;
		AVLNode* right_child = nullptr;
		AVLNode* parent = nullptr;
	public:
		// Constructor
		AVLNode();
		AVLNode(string);

		// Getters
		string get_name() const;
		int get_height() const;
		AVLNode* get_parent() const;
		AVLNode* get_left() const;
		AVLNode* get_right() const;

		// Setters
		void set_name(string);
		void set_height(int);
		void set_parent(AVLNode*);
		void set_left(AVLNode*);
		void set_right(AVLNode*);
};