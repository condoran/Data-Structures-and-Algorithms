#pragma once
#include "Bag.h"

class BagIterator
{
	friend class Bag;
private:
	BagIterator(const Bag&);
	const Bag& bag;
	node* current;
	int currentPoz;
public:
	void first();
	void next();
	bool valid() const;
	TElem getCurrent() const;
	~BagIterator();
};

