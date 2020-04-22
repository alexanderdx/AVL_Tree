#include "BinarySearchTree.h"
#include "AVL_Tree.h"

int main()
{
	AVL_Tree avl;
	avl.insert(13);
	avl.insert(6);
	avl.insert(15);
	avl.insert(16);
	avl.insert(5);
	avl.insert(10);
	avl.insert(4);
	avl.insert(7);
	avl.insert(11);
	avl.display_tree();

	avl.remove(13);
	avl.display_tree();
	avl.insert(3);
	avl.display_tree();
	return 0;
}