#include "BinarySearchTree.h"

Nod* BinarySearchTree::search(Nod* root, int value)
{
	if (root == nullptr)
		return nullptr;

	if (value == root->get_data())
		return root;
	if (value < root->get_data())
		search(root->get_left(), value);
	else search(root->get_right(), value);
}

Nod* BinarySearchTree::findMax(Nod* subtree_root)
{
	if (subtree_root == nullptr)
		return subtree_root;
	else if (subtree_root->get_right() == nullptr)
		return subtree_root;
	else return findMax(subtree_root->get_right());
}

Nod* BinarySearchTree::findMin(Nod* subtree_root)
{
	if (subtree_root == nullptr)
		return subtree_root;
	else if (subtree_root->get_left() == nullptr)
		return subtree_root;
	else return findMin(subtree_root->get_left());
}

Nod* BinarySearchTree::remove(Nod* node, int value)
{
	if (node == nullptr)
		return root;

	if (value < node->get_data())
		node->set_left(remove(node->get_left(), value));
	else if (value > node->get_data())
		node->set_right(remove(node->get_right(), value));
	else { // am gasit valoarea

		if (node->get_left() == nullptr &&
			node->get_right() == nullptr) // suntem pe un nod frunza
		{
			delete node;
			node = nullptr;
		}
		else if (node->get_left() == nullptr) { //nod cu un fiu la dreapta
			Nod* delptr = node;
			node = node->get_right();
			delete delptr;
		}
		else if (node->get_right() == nullptr) { //nod cu un fiu la stanga
			Nod* delptr = node;
			node = node->get_left();
			delete delptr;
		}
		else {									// nod cu ambii fii
			Nod* minRightSubtree = findMin(node->get_right());
			node->set_data(minRightSubtree->get_data());
			node->set_right(remove(minRightSubtree, minRightSubtree->get_data()));
		}
	}
	return node;
}


void BinarySearchTree::remove(int value)
{
	root = remove(root, value);
}

BinarySearchTree::BinarySearchTree(const std::vector<int>& list) : Tree(list.size()), root(nullptr)
{
	for (auto const& it : list)
		insert(it);
}

Nod* BinarySearchTree::copy_tree(const Nod* src)
{
	if (src) {
		Nod* newNode = new Nod(src->get_data());
		newNode->set_left(copy_tree(src->get_left()));
		newNode->set_right(copy_tree(src->get_right()));
		
		return newNode;
	}
	return nullptr;
}

BinarySearchTree::BinarySearchTree(const BinarySearchTree& src) : Tree(src.get_nrNoduri()), root(nullptr)
{
	if (src.root == nullptr) {
		root = nullptr;
		set_nrNoduri(0);
	}
	else root = copy_tree(src.root);
}

BinarySearchTree::~BinarySearchTree()
{
	clear_tree();
}

void BinarySearchTree::insert(Nod* leaf, int value)
{
	if (value < leaf->get_data()) {
		if (leaf->get_left() == nullptr) {
			set_nrNoduri(get_nrNoduri() + 1);
			leaf->set_left(new Nod(value));
		}
		else {
			insert(leaf->get_left(), value);
		}
	}
	else {
		if (leaf->get_right() == nullptr) {
			set_nrNoduri(get_nrNoduri() + 1);
			leaf->set_right(new Nod(value));
		}
		else {
			insert(leaf->get_right(), value);
		}
	}
}

void BinarySearchTree::clear_tree(Nod* root)
{
	if (root) {
		clear_tree(root->get_left());
		clear_tree(root->get_right());
	}

	delete root;
}

void BinarySearchTree::inorder_traversal(Nod* root)
{
	if (root == nullptr)
		return;

	inorder_traversal(root->get_left());
	std::cout << root->get_data() << ' ';
	inorder_traversal(root->get_right());
}

void BinarySearchTree::display()
{
	inorder_traversal(root);
}
 

void BinarySearchTree::clear_tree()
{
	clear_tree(root);
}


void BinarySearchTree::insert(int value)
{
	if (root == nullptr)
		root = new Nod(value);
	else
		insert(root, value);
}


void BinarySearchTree::display_tree(Nod* node, int spaces)
{
	if (node)
	{
		display_tree(node->get_right(), spaces + 4);

		for (int i = 0; i < spaces; ++i)
			std::cout << ' ';
		
		if (node) 
			std::cout << "   " << node->get_data() << std::endl;

		display_tree(node->get_left(), spaces + 4);
	}
}


void BinarySearchTree::display_tree()
{
	//TODO: EXCEPTION FOR NULLPTR
	std::cout << "\n\n";
	display_tree(root, 0);
	std::cout << "\n\n";
}
