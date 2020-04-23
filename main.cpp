#include "BinarySearchTree.h"
#include "AVL_Tree.h"

int main()
{
	AVL_Tree tree;
	tree.insert(5);
	tree.insert(3);
	tree.insert(7);
	tree.insert(1);
	tree.insert(3);
	tree.insert(2);
	tree.insert(19);
	tree.insert(13);
	tree.insert(14);
	tree.insert(16);
	tree.insert(15);
	tree.insert(18);

	std::cout << tree;
	tree.remove(5);
	std::cout << tree;
	tree.display(std::cout);
	return 0;
}