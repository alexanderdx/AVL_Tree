#pragma once

#include <vector>
#include <algorithm>

#include "Nod_AVL.h"
#include "Tree.h"

class AVL_Tree : public Tree
{
private:
	Nod_AVL* root;

    Nod_AVL* findMax(Nod_AVL*);
    Nod_AVL* findMin(Nod_AVL*);
    Nod_AVL* RR_rotation(Nod_AVL*);
    Nod_AVL* LL_rotation(Nod_AVL*);
    Nod_AVL* LR_rotation(Nod_AVL*);
    Nod_AVL* RL_rotation(Nod_AVL*);
    Nod_AVL* rebalance(Nod_AVL*);
    Nod_AVL* insert(Nod_AVL*, int);
    Nod_AVL* copy_tree(const Nod_AVL*);
    Nod_AVL* remove(Nod_AVL*, int);

    int height(Nod_AVL*);
    void set_echilibru(Nod_AVL*);
    void print_echilibru(Nod_AVL*);
    void clear_tree(Nod_AVL*);
    void inorder_traversal(Nod_AVL*, std::ostream&);
    void display_tree(Nod_AVL*, int, std::ostream&);

public:
    AVL_Tree() : Tree(0), root(nullptr) { }
    AVL_Tree(Nod_AVL* _root) : Tree(1), root(_root) { }
    AVL_Tree(const std::vector<int>& list);
    AVL_Tree(const AVL_Tree& src);
    ~AVL_Tree();

    void insert(int value);
    void remove(int value);
    void clear_tree();
    void display(std::ostream&);

    AVL_Tree& operator=(const AVL_Tree& other);
    friend std::istream& operator>>(std::istream& in, AVL_Tree& tree);
    friend std::ostream& operator<<(std::ostream& out, AVL_Tree& tree);
};

