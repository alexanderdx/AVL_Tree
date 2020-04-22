#include "Nod_AVL.h"

Nod_AVL::Nod_AVL()
{
	value = 0;
	echilibru = 0;
	left = nullptr;
	right = nullptr;
}

Nod_AVL::Nod_AVL(int data)
{
	value = data;
	echilibru = 0;
	left = nullptr;
	right = nullptr;
}

Nod_AVL::Nod_AVL(int data, int echilibru)
{
	value = data;
	this->echilibru = echilibru;
	left = nullptr;
	right = nullptr;
}

Nod_AVL::Nod_AVL(const Nod_AVL& src)
{
	this->value = src.value;
	this->echilibru = src.echilibru;
	this->left = new Nod_AVL(src.left->value);
	this->right = new Nod_AVL(src.right->value);
}

Nod_AVL::Nod_AVL(int data, Nod_AVL* left, Nod_AVL* right)
{
	this->value = data;
	this->left = left;
	this->right = right;
	this->echilibru = 0;
}

Nod_AVL::~Nod_AVL()
{
	this->left = nullptr;
	this->right = nullptr;
}

int Nod_AVL::get_data() const
{
	return this->value;
}

Nod_AVL* Nod_AVL::get_right() const
{
	return this->right;
}

Nod_AVL* Nod_AVL::get_left() const
{
	return this->left;
}

void Nod_AVL::set_data(int data)
{
	this->value = data;
}

void Nod_AVL::set_right(Nod_AVL* n)
{
	this->right = n;
}

void Nod_AVL::set_left(Nod_AVL* n)
{
	this->left = n;
}
