#include "ListIterator.h"



ListIterator::ListIterator(SortedList& l) : list(l)
{
	this->poz = list.first();
	this->current = list.getElement(poz);
}


void ListIterator::first()
{
	poz = list.first();
}

void ListIterator::next()
{
	poz = list.next(poz);
}

bool ListIterator::valid()
{
	return list.valid(poz);
}

TComp ListIterator::getCurrent()
{
	return list.getElement(poz);
}

ListIterator::~ListIterator()
{
}
