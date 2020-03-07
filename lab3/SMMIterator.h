#pragma once
#include "SortedMultiMap.h"

class SortedMultiMap;

class SMMIterator
{
	friend class SortedMultiMap;

private:
	SMMIterator(const SortedMultiMap& m);
	const SortedMultiMap& m;
	DLL* dllMap;
	node* current;
public:
	void first();
	void next();
	bool valid() const;
	TElem getCurrent() const;
};

