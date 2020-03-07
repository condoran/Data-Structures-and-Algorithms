#pragma once
#include "Set.h"

class SetIterator
{
	friend class Set;
private:
	bool* list;
	TElem max;
	int current;
	TElem min;
public:

	SetIterator(TElem maxim, bool* listN, TElem minim);
	void first();
	void next();
	bool valid();
	int getCurrent();
};