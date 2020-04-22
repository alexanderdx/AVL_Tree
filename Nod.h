#pragma once
#include <iostream>

class Nod
{
private:
	int value;
	Nod* left;
	Nod* right;

public:
	Nod();
	Nod(int data);
	Nod(const Nod&);
	Nod(int data, Nod* left, Nod* right);
	~Nod();

	int get_data() const;
	Nod* get_left() const;
	Nod* get_right() const;

	void set_data(int data);
	void set_left(Nod* n);
	void set_right(Nod* n);
};

