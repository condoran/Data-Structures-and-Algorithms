#include "SortedMultiMap.h"
#include "SMMIterator.h"


SortedMultiMap::SortedMultiMap(Relation r)
{
	dllMap = new DLL();
	dllMap->head = NULL;
	dllMap->tail = NULL;
	this->rel = r;
}

SortedMultiMap::~SortedMultiMap()
{
	node* n = dllMap->head;
	while (n)
	{
		node* nextN = n->next;
		delete n;
		n = nextN;
	}
}

void SortedMultiMap::add(TKey k, TValue v)
{
	node* newNode = new node();
	newNode->el.first = k;
	newNode->el.second = v;
	if (dllMap->head == NULL)
	{
		dllMap->head = newNode;
		dllMap->tail = newNode;
	}
	else
	{
		node* aux = dllMap->head;
		while (aux != NULL && rel(aux->el.first, k))
			aux = aux->next;
		if (aux == NULL)
		{
			node* aux2 = dllMap->head;
			while (aux2->next != NULL)
				aux2 = aux2->next;
			aux2->next = newNode;
			newNode->next = NULL;
		}
		else if (aux == dllMap->head)
		{
			newNode->next = dllMap->head;
			dllMap->head = newNode;
		}
		else
		{
			node* aux2 = dllMap->head;
			while (aux2->next != aux && aux2 != NULL)
				aux2 = aux2->next;
			newNode->next = aux;
			aux2->next = newNode;
		}
	}
}

bool SortedMultiMap::remove(TKey k, TValue v)
{
	node* n = dllMap->head;
	while (n != NULL)
	{
		if (n->el.first == k && n->el.second == v)
		{
			if (dllMap->head == n)
				dllMap->head = n->next;
			else
			{
				node* aux = dllMap->head;
				while (aux->next != n)
					aux = aux->next;
				aux->next = n->next;
			}
			delete n;
			return true;
		}
		n = n->next;
	}
	return false;
}

vector<TValue> SortedMultiMap::search(TKey k) const
{
	vector<TValue> v;
	node* n = dllMap->head;
	while (n != NULL)
	{
		if (n->el.first == k)
			v.push_back(n->el.second);
		n = n->next;
	}
	return v;
}

int SortedMultiMap::size() const
{
	node* n = dllMap->head;
	int count = 0;
	while (n != NULL)
	{
		count++;
		n = n->next;
	}
	return count;
}

bool SortedMultiMap::isEmpty() const
{
	return size() == 0;
}

SMMIterator SortedMultiMap::iterator() const
{
	return SMMIterator(*this);
}
