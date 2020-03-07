#pragma once
#include <exception>
#include <utility>
#include <math.h>

typedef int TKey;
typedef int TFreq;
typedef int TElem;
typedef std::pair<TElem, TFreq> TValue;
//typedef int (*TFunction) (TValue);

struct node
{
	TValue info;
	node* next;
};

struct HashTable
{
	node** T;
	int m;
	int hash(TElem v) { return abs(v) % this->m; };
};

class Bag
{
	friend class BagIterator;
private:
	HashTable bag;
public:
	Bag();
	void add(TElem);
	bool remove(TElem);
	bool search(TElem);
	int nrOccurrences(TElem);
	int size();
	bool isEmpty();
	BagIterator iterator() const;

	~Bag();
};
