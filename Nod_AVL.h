#pragma once

#include "Nod.h"

class Nod_AVL
{
private:
	int echilibru;
	int value;
	Nod_AVL* left;
	Nod_AVL* right;

public:
	Nod_AVL();
	Nod_AVL(int data);
	Nod_AVL(int data, int echilibru);
	Nod_AVL(const Nod_AVL& src);
	Nod_AVL(int data, Nod_AVL* left, Nod_AVL* right);
	~Nod_AVL();

	int get_echilibru() const { return echilibru; }
	void set_echilibru(int n) { echilibru = n; }

	int get_data() const;
	Nod_AVL* get_left() const;
	Nod_AVL* get_right() const;

	void set_data(int data);
	void set_left(Nod_AVL* n);
	void set_right(Nod_AVL* n);
};

