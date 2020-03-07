#pragma once
#include "SortedList.h"

class ListIterator
{
	friend class ListIterator;
public:
	void first();
	void next();
	bool valid();
	TComp getCurrent();
	~ListIterator();
private:
	ListIterator(SortedList& l);
	SortedList& list;
	TComp current;
	int poz;
};

