#pragma once
#include <utility>
#include <exception>

typedef int TComp;
typedef int TPosition;
typedef bool (*Relation)(TComp, TComp);
typedef std::pair<TComp, TPosition> TValue;

class ListIterator;

struct node
{
	TValue info;
	int left;
	int right;
	int parent;
};

class SortedList
{
	friend class ListIterator;
private:
	Relation rel;
	node* elems;
	int firstFree;
	int root;
	int cap;
	int lSize;
	void resize();
public:
	SortedList(Relation r);

	TPosition first();
	TPosition last();
	bool valid(TPosition);
	TPosition next(TPosition);
	TPosition previous(TPosition);
	TComp getElement(TPosition);
	TPosition position(TComp);
	TComp setElement(TPosition, TComp);
	void addToPos(TComp);
	void addToBegining(TComp);
	void addToEnd(TComp);
	//void newFirstFree();
	void add(TComp);
	//void addAfterPosition(TPosition, TComp);
	TComp remove(TPosition);
	bool search(TComp);
	bool isEmpty();
	int size();
	ListIterator iterator();
	~SortedList();
};

 