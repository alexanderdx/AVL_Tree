#include "Nod.h"

Nod::Nod()
{
	left = nullptr;
	right = nullptr;
	value = 0;
}

Nod::Nod(int data)
{
	value = data;
	left = nullptr;
	right = nullptr;
}

Nod::Nod(const Nod& src)
{
	this->value = src.value;
	this->left = new Nod(src.left->value);
	this->right = new Nod(src.right->value);
}

Nod::Nod(int data, Nod* left, Nod* right)
{
	this->value = data;
	this->left = left;
	this->right = right;
}

Nod::~Nod()
{
	this->left = nullptr;
	this->right = nullptr;
}

int Nod::get_data() const
{
	return this->value;
}

Nod* Nod::get_right() const
{
	return this->right;
}

Nod* Nod::get_left() const
{
	return this->left;
}

void Nod::set_data(int data)
{
	this->value = data;
}

void Nod::set_right(Nod* n)
{
	this->right = n;
}

void Nod::set_left(Nod* n)
{
	this->left = n;
}
