#include "AVL_Tree.h"

Nod_AVL* AVL_Tree::findMax(Nod_AVL* subtree_root)
{
	if (subtree_root == nullptr)
		return subtree_root;
	else if (subtree_root->get_right() == nullptr)
		return subtree_root;
	else return findMax(subtree_root->get_right());
}

Nod_AVL* AVL_Tree::findMin(Nod_AVL* subtree_root)
{
	if (subtree_root == nullptr)
		return subtree_root;
	else if (subtree_root->get_left() == nullptr)
		return subtree_root;
	else return findMin(subtree_root->get_left());
}

Nod_AVL* AVL_Tree::RR_rotation(Nod_AVL* root)
{
	Nod_AVL* temp = root->get_right();
	root->set_right(temp->get_left());
	temp->set_left(root);

	return temp;
}

Nod_AVL* AVL_Tree::LL_rotation(Nod_AVL* root)
{
	Nod_AVL* temp = root->get_left();
	root->set_left(temp->get_right());
	temp->set_right(root);

	return temp;
}

Nod_AVL* AVL_Tree::LR_rotation(Nod_AVL* root)
{
	Nod_AVL* temp = root->get_left();
	root->set_left(RR_rotation(temp));
	return LL_rotation(root);
}

Nod_AVL* AVL_Tree::RL_rotation(Nod_AVL* root)
{
	Nod_AVL* temp = root->get_right();
	root->set_right(LL_rotation(temp));
	return RR_rotation(root);
}

Nod_AVL* AVL_Tree::rebalance(Nod_AVL* node)
{
	set_echilibru(node);
	int balance_factor = node->get_echilibru();

	if (balance_factor > 1)
	{
		if (node->get_left()->get_echilibru() > 0)
			node = LL_rotation(node);
		else
			node = LR_rotation(node);
	}
	else if (balance_factor < -1) 
	{
		if (node->get_right()->get_echilibru() > 0)
			node = RL_rotation(node);
		else
			node = RR_rotation(node);
	}

	return node;
}

Nod_AVL* AVL_Tree::insert(Nod_AVL* root, int value)
{
	if (root == nullptr) {
		root = new Nod_AVL(value);
		return root;
	}
	else if (value < root->get_data()) {
		root->set_left(insert(root->get_left(), value));
		root = rebalance(root);
	}
	else if (value >= root->get_data()) {
		root->set_right(insert(root->get_right(), value));
		root = rebalance(root);
	}

	return root;
}

int AVL_Tree::height(Nod_AVL* node)
{
    if (node == nullptr)
        return 0;
    else {
        return std::max(height(node->get_left()), height(node->get_right())) + 1;
    }
}

void AVL_Tree::set_echilibru(Nod_AVL* node)
{
	node->set_echilibru(height(node->get_left()) 
					  - height(node->get_right()));
}

void AVL_Tree::print_echilibru(Nod_AVL* node)
{
	if (node) {
		print_echilibru(node->get_left());
		std::cout << node->get_echilibru() << ' ';
		print_echilibru(node->get_right());
	}
}


void AVL_Tree::clear_tree(Nod_AVL* root)
{
	if (root) {
		clear_tree(root->get_left());
		clear_tree(root->get_right());
	}

	delete root;
}

AVL_Tree::AVL_Tree(const std::vector<int>& list) : Tree(list.size()), root(nullptr)
{
	for (auto const& it : list)
		insert(it);
}

Nod_AVL* AVL_Tree::copy_tree(const Nod_AVL* src)
{
	if (src) {
		Nod_AVL* newNode = new Nod_AVL(src->get_data(), src->get_echilibru());
		newNode->set_left(copy_tree(src->get_left()));
		newNode->set_right(copy_tree(src->get_right()));

		return newNode;
	}
	return nullptr;
}

AVL_Tree::AVL_Tree(const AVL_Tree& src) : Tree(src.get_nrNoduri()), root(nullptr)
{
	if (src.root == nullptr) {
		root = nullptr;
		set_nrNoduri(0);
	}
	else root = copy_tree(src.root);
}

AVL_Tree::~AVL_Tree()
{
	clear_tree();
}

void AVL_Tree::inorder_traversal(Nod_AVL* root)
{
	if (root == nullptr)
		return;

	inorder_traversal(root->get_left());
	std::cout << root->get_data() << ' ';
	inorder_traversal(root->get_right());
}

void AVL_Tree::insert(int value)
{
	root = insert(root, value);
}

void AVL_Tree::remove(int value)
{
	root = remove(root, value);
}

void AVL_Tree::clear_tree()
{
	clear_tree(root);
}

Nod_AVL* AVL_Tree::remove(Nod_AVL* node, int value)
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
			Nod_AVL* delptr = node;
			node = node->get_right();
			delete delptr;
		}
		else if (node->get_right() == nullptr) { //nod cu un fiu la stanga
			Nod_AVL* delptr = node;
			node = node->get_left();
			delete delptr;
		}
		else {									// nod cu ambii fii
			Nod_AVL* minRightSubtree = findMin(node->get_right());
			node->set_data(minRightSubtree->get_data());
			node->set_right(remove(minRightSubtree, minRightSubtree->get_data()));
		}
	}

	if (node == nullptr)
		return node;
	
	node = rebalance(node);
	return node;
}


void AVL_Tree::display_tree(Nod_AVL* root, int level)
{
	if (root)
	{
		display_tree(root->get_right(), level + 1);
		std::cout << '\n';
		
		if (root == this->root)
			std::cout << "\nRoot-> ";

		for (int i = 0; i < level && root != this->root; ++i)
			std::cout << "     ";
		
		std::cout << "    " << root->get_data() << std::endl;
		display_tree(root->get_left(), level + 1);
	}
}

void AVL_Tree::display_tree()
{
	std::cout << "\n\n";
	display_tree(root, 1);
	std::cout << "\n\n";
}
