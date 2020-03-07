#include "Bag.h"
#include "BagIterator.h"
#include <iostream>



Bag::Bag()
{
	bag.m = 10;
	bag.T = new node * [bag.m];
	for (int i = 0; i < bag.m; i++)
		bag.T[i] = nullptr;
}

void Bag::add(TElem val)
{
	TKey pos = this->bag.hash(val);
	//std::cout << pos;
	node* current = this->bag.T[pos];
	if (current == nullptr)
	{
		current = new node;
		current->info.first = val;
		current->info.second = 1;
		current->next = nullptr;
		this->bag.T[pos] = current;
		return;
	}
	if (current->info.first == val)
	{
		current->info.second++;
		return;
	}
	while (current->next != nullptr && current->next->info.first != val)
		current = current->next;
	if (current->next == nullptr)
	{
		node* n = new node;
		n->info.first = val;
		n->info.second = 1;
		n->next = nullptr;
		current->next = n;
	}
	else
	{
		current->info.second++;
	}
}

bool Bag::remove(TElem val)
{
	TKey pos = this->bag.hash(val);
	node* current = this->bag.T[pos];
	if (current == nullptr)
		return false;
	if (current->info.first == val)
	{
		if (current->info.second > 1)
		{
			current->info.second--;
			return true;
		}
		this->bag.T[pos] = current->next;
		current = nullptr;
		return true;
	}
	while (current->next != nullptr && current->next->info.first != val)
		current = current->next;
	if (current->next != nullptr)
	{
		node* n = new node;
		n = current->next;
		current->next = n;
		return true;
	}
	return false;
}

bool Bag::search(TElem val)
{
	TKey pos = this->bag.hash(val);
	node* current = this->bag.T[pos];
	while (current != nullptr && current->info.first != val)
		current = current->next;
	if (current == nullptr)
		return false;
	return true;
}

int Bag::nrOccurrences(TElem val)
{
	TKey pos = this->bag.hash(val);
	node* current = this->bag.T[pos];
	while (current != nullptr && current->info.first != val)
		current = current->next;
	if (current != nullptr)
	{
		return current->info.second;
	}
	return 0;
}

int Bag::size()
{
	int len = 0;
	for (TKey i = 0; i < bag.m; i++)
	{
		node* current = this->bag.T[i];
		while (current != nullptr)
		{
			len += current->info.second;
			current = current->next;
		}
	}
	//std::cout << len;
	return len;
}

bool Bag::isEmpty()
{
	return size() == 0;
}

BagIterator Bag::iterator() const
{
	return BagIterator(*this);
}


Bag::~Bag()
{
}
