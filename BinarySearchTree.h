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
	void inorder_traversal(Nod*, std::ostream&);
	void display_tree(Nod*, int, std::ostream&);

public:
	BinarySearchTree() : Tree(0), root(nullptr) { }
	BinarySearchTree(Nod* _root) : Tree(1), root(_root) { }
	BinarySearchTree(const std::vector<int>& list);
	BinarySearchTree(const BinarySearchTree& src);
	~BinarySearchTree();
	
	void remove(int value);
	void insert(int value);
	void clear_tree();
	void display(std::ostream&);

	BinarySearchTree& operator=(const BinarySearchTree& other);
	friend std::istream& operator>>(std::istream& in, BinarySearchTree& tree);
	friend std::ostream& operator<<(std::ostream& out, BinarySearchTree& tree);
};

