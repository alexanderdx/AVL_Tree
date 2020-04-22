#pragma once
#include <iostream>

class Tree
{
private:
	int nr_noduri;

public:
	Tree() : nr_noduri(0) { }
	Tree(int nrNoduri) : nr_noduri(nrNoduri) { }
	virtual ~Tree() { std::cout << "\nDealocare...\n"; }

	virtual void insert() { }
	virtual void remove() { }
	void set_nrNoduri(int n) { nr_noduri = n; }
	int get_nrNoduri() const { return nr_noduri; }
};

