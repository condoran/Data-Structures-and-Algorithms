#pragma once
#include "DynamicArray.h"
#include "SetIterator.h"

typedef int TElem;

class SetIterator;

class Set
{
	friend class SetIterator;
private:
	bool* list;
	int cap;
	int min;
	int max;
public:
	Set();
	void resize();
	bool getElem(TElem pos);
	bool add(TElem elem);
	bool remove(TElem elem);
	bool search(TElem elem);
	int size();
	bool isEmpty();
	SetIterator iterator();
};