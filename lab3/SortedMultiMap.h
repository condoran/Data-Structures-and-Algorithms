#pragma once
#include <stdexcept>
#include <vector>
#include <utility>
//#include "SMMIterator.h"

using namespace std;

typedef int TKey;

typedef int TValue;

typedef std::pair<TKey, TValue> TElem;
typedef bool (*Relation) (TKey, TKey);

struct node
{
	TElem el;
	node* next;
	node* prev;
};

struct DLL
{
	node* head;
	node* tail;
};

class SMMIterator;

class SortedMultiMap
{
	friend class SMMIterator;
private:
	DLL* dllMap;
	Relation rel;
public:
	SortedMultiMap(Relation r);
	~SortedMultiMap();
	void add(TKey k, TValue v);
	bool remove(TKey k, TValue v);
	vector<TValue> search(TKey k) const;
	int size() const;
	bool isEmpty() const;
	SMMIterator iterator() const;
};

