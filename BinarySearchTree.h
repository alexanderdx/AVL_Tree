#pragma once

#include <vector>

#include "Tree.h"
#include "Nod.h"

class BinarySearchTree : public Tree
{
private:
	Nod* root;
	
	Nod* search(Nod*, int);
	Nod* findMax(Nod*);
	Nod* findMin(Nod*);
	Nod* remove(Nod*, int);
	Nod* copy_tree(const Nod*);

	void insert(Nod*, int);
	void clear_tree(Nod*);
	void inorder_traversal(Nod*);
	void display_tree(Nod*, int);

public:
	BinarySearchTree() : Tree(0), root(nullptr) { }
	BinarySearchTree(Nod* _root) : Tree(1), root(_root) { }
	BinarySearchTree(const std::vector<int>& list);
	BinarySearchTree(const BinarySearchTree& src);
	~BinarySearchTree();
	
	//Nod* search(int value);
	//TODO: OPERATOR OVERLOADING
	void remove(int value);
	void insert(int value);
	void clear_tree();
	void display();
	void display_tree();
};

