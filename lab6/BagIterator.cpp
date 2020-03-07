#include "BagIterator.h"



BagIterator::BagIterator(const Bag& b) : bag(b)
{
	this->current = NULL;
	this->currentPoz = 0;
	this->first();
}


void BagIterator::first()
{
	this->current = NULL;
	this->currentPoz = 0;
	while (this->bag.bag.T[this->currentPoz] == NULL && currentPoz < this->bag.bag.m - 1)
	{
		this->currentPoz++;
	}
	this->current = this->bag.bag.T[this->currentPoz];
}

void BagIterator::next()
{
	if (!this->valid())
		throw std::exception();
	if (current->next != NULL)
	{
		current = current->next;
		return;
	}
	this->currentPoz++;
	while (this->bag.bag.T[this->currentPoz] == NULL && currentPoz < this->bag.bag.m - 1)
		this->currentPoz++;
	this->current = this->bag.bag.T[this->currentPoz];
}

bool BagIterator::valid() const
{
	return this->current != NULL;
}

TElem BagIterator::getCurrent() const
{
	if (!this->valid())
		throw std::exception();
	return this->current->info.first;
}

BagIterator::~BagIterator()
{
}
