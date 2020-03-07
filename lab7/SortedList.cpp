#include "SortedList.h"



void SortedList::resize()
{
	node* newEl = new node[this->cap * 2];
	for (int i = 0; i < this->cap; i++)
	{
		newEl[i].info = this->elems[i].info;
		newEl[i].left = this->elems[i].left;
		newEl[i].right = this->elems[i].right;
		newEl[i].parent = this->elems[i].parent;
	}
	this->firstFree = this->cap;
	this->cap *= 2;
	delete[]this->elems;
	this->elems = newEl;
}

SortedList::SortedList(Relation r)
{
	this->root = -1;
	this->firstFree = 0;
	this->cap = 10;
	this->size = 0;
	this->elems = new node[this->cap];
	this->rel = r;
}

TPosition SortedList::first()
{
	TPosition current = this->root;
	while (this->elems[current].left != -1)
	{
		current = this->elems->left;
	}
	return current;
}

TPosition SortedList::last()
{
	TPosition current = this->root;
	while (this->elems[current].right != -1)
	{
		current = this->elems->right;
	}
	return this->elems[current].info.second;
}

bool SortedList::valid(TPosition pos)
{
	TPosition current = this->root;
	while (current != size())
	{
		if (this->elems[current].info.second == pos)
			return true;
		current++;
	}
	return false;
}

TPosition SortedList::next(TPosition pos)
{
	if (!valid(pos) || !valid(pos + 1))
		throw std::exception();
	if (this->elems[pos].right != -1)
		return this->elems[this->elems[pos].right].info.second;
	else if (this->elems[this->elems[pos].parent].right != pos)
		return this->elems[this->elems[pos].parent].info.second;
	else
		while (this->elems[this->elems[pos].parent].right != -1 || this->elems[this->elems[pos].parent].right != pos)
			return this->elems[this->elems[this->elems[pos].parent].right].info.second;
}

TPosition SortedList::previous(TPosition pos)
{
	if (!valid(pos) || !valid(pos + 1))
		throw std::exception();
	if (this->elems[pos].left != -1)
		return this->elems[this->elems[pos].left].info.second;
	else if (this->elems[this->elems[pos].parent].left != pos)
		return this->elems[this->elems[pos].parent].info.second;
	else
		while (this->elems[this->elems[pos].parent].left != -1 || this->elems[this->elems[pos].parent].left != pos)
			return this->elems[this->elems[this->elems[pos].parent].left].info.second;
}

TComp SortedList::getElement(TPosition pos)
{
	int current = this->root;
	while (this->elems[current].info.second != pos || (this->elems[current].left == -1 && this->elems[current].right == -1))
	{
		if (this->elems[current].info.second > pos)
			current = this->elems[current].left;
		else
			current = this->elems[current].right;
	}
	if (this->elems[current].info.second == pos)
		return this->elems[current].info.first;
	throw std::exception();
}

TPosition SortedList::position(TComp el)
{
	int current = this->root;
	while (this->elems[current].info.first != el || (this->elems[current].left == -1 && this->elems[current].right == -1))
	{
		if (this->elems[current].info.first > el)
			current = this->elems[current].left;
		else
			current = this->elems[current].right;
	}
	if (this->elems[current].info.first == el)
		return this->elems[current].info.second;
	throw std::exception();
}

TComp SortedList::setElement(TPosition pos, TComp el)
{
	int current = this->root;
	while (this->elems[current].info.second != pos || (this->elems[current].left == -1 && this->elems[current].right == -1))
	{
		if (this->elems[current].info.second > pos)
			current = this->elems[current].left;
		else
			current = this->elems[current].right;
	}
	if (this->elems[current].info.second == pos)
	{
		TComp old = this->elems[current].info.first;
		this->elems[current].info.first = el;
	}
	throw std::exception();
}

void SortedList::addToPos(TComp el)
{
	int current = this->root;
	while (this->elems[current].info.first != el || (this->elems[current].left == -1 && this->elems[current].right == -1))
	{
		if (this->elems[current].info.first > el)
			current = this->elems[current].left;
		else
			current = this->elems[current].right;
	}
	if (this->elems[current].info.first == el)
		this->elems[current].info.second++;
	throw std::exception();
}

void SortedList::addToBegining(TComp el)
{
	if (this->root == -1)
	{
		this->elems[0].info.first = el;
		this->elems[0].info.second = 0;
		this->elems[0].left = -1;
		this->elems[0].right = -1;
		this->elems[0].parent = -1;
		return;
	}
	int current = this->root;
	while (this->elems[current].left != -1)
		current = this->elems[current].left;
	this->elems[current].left = firstFree;
	this->elems[current].info.second++;
	if (size() == cap - 1)
		resize();
	int len = size();
	this->elems[firstFree].info.first = el;
	this->elems[firstFree].info.second = len + 1;
	this->elems[firstFree].left = -1;
	this->elems[firstFree].right = -1;
	this->elems[firstFree].parent = current;
	TComp curr = position(this->elems[current].info.first);
	while (position(curr) == last())
	{
		curr = next(curr);
		addToPos(getElement(curr));
	}
	lSize++;
	firstFree = size();
}

void SortedList::addToEnd(TComp el)
{
	int current = this->root;
	if (size() == cap - 1)
		resize();
	while (this->elems[current].right != -1)
		current = this->elems[current].right;
	this->elems[current].right = firstFree;
	this->elems[firstFree].info.first = el;
	this->elems[firstFree].info.second = size();
	this->elems[firstFree].left = -1;
	this->elems[firstFree].right = -1;
	this->elems[firstFree].parent = current;
	lSize++;
	firstFree = size();
}

void SortedList::add(TComp el)
{
	int current = this->root;
	if (size() == cap - 1)
		resize();
	while (this->elems[this->elems[current].left].info.first > el  || this->elems[this->elems[current].right].info.first < el || (this->elems[current].left == -1 && this->elems[current].right == -1))
	{
		if (this->elems[current].info.first > el)
			current = this->elems[current].left;
		else
			current = this->elems[current].right;
	}
	if (this->elems[current].info.first <= el)
	{
		this->elems[firstFree].info.first = el;
		this->elems[firstFree].info.second = size();
		this->elems[firstFree].left = -1;
		this->elems[firstFree].right = this->elems[current].right;
		this->elems[current].right = firstFree;
		addToPos(this->elems[firstFree].right);
	}
	else
	{
		this->elems[firstFree].info.first = el;
		this->elems[firstFree].info.second = size();
		this->elems[firstFree].right = -1;
		this->elems[firstFree].left = this->elems[current].left;
		this->elems[current].left = firstFree;
		addToPos(this->elems[firstFree].left);
	}
	firstFree = lSize + 1;
	lSize++;
	//addToPos(current);
}

TComp SortedList::remove(TPosition pos)
{
	if (!valid(pos))
		throw std::exception();
	int current = this->root;
	while (this->elems[current].info.second != pos || (this->elems[current].left == -1 && this->elems[current].right == -1))
	{
		if (this->elems[current].info.second > pos)
			current = this->elems[current].left;
		else
			current = this->elems[current].right;
	}
	int lef = this->elems[current].left;
	int rig = this->elems[current].right;
	int par = this->elems[current].parent;
	if (this->elems[current].info.first > this->elems[par].info.first)
	{
		this->elems[par].right = rig;
	}
	else
	{
		this->elems[par].left = rig;
	}
	while (this->elems[rig].left != -1)
		rig = this->elems[rig].left;
	this->elems[rig].left = lef;
	return this->elems[current].info.first;
	lSize--;
}

bool SortedList::search(TComp el)
{
	int current = this->root;
	while (this->elems[current].info.first != el || (this->elems[current].left == -1 && this->elems[current].right == -1))
	{
		if (this->elems[current].info.first > el)
			current = this->elems[current].left;
		else
			current = this->elems[current].right;
	}
	if (this->elems[current].info.first == el)
		return true;
	return false;
}

/*
void SortedList::newFirstFree()
{
	for (int i = 0; i < cap; i++)
		if (this->elems[i] == nullptr)
}*/



bool SortedList::isEmpty()
{
	return lSize == 0;
}

int SortedList::size()
{
	return lSize;
}

ListIterator SortedList::iterator()
{
	return ListIterator(*this);
}

SortedList::~SortedList()
{
}
