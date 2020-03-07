#include "SetIterator.h"

SetIterator::SetIterator(TElem maxim, bool* listN, TElem minim)
{
	this->min = minim;
	this->max = maxim;
	this->list = listN;
	this->current = 0;
}

void SetIterator::first()
{
	this->current = 0;
}

void SetIterator::next()
{
	if (this->valid() == 0)
		return;
	current++;
	while (list[current] == 0)
		current++;
}

bool SetIterator::valid()
{
	if (list[0] == 0)
		return 0;
	if (this->current > max - min)
		return 0;
	return 1;
}

int SetIterator::getCurrent()
{
	return current + min;
}
