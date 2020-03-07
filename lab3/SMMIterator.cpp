#include "SMMIterator.h"
#include "SortedMultiMap.h"
#include <stdexcept>


SMMIterator::SMMIterator(const SortedMultiMap& m) : m(m)
{
	dllMap = m.dllMap;
	current = m.dllMap->head;
}

void SMMIterator::first()
{
	current = m.dllMap->head;
}

void SMMIterator::next()
{
	if (!this->valid())
	{
		throw std::runtime_error("Invalid iterator!");
	}
	if (current != NULL)
	{
		current = current->next;
	}
}

bool SMMIterator::valid() const
{
	if (current != NULL)
		return true;
	return false;
}

TElem SMMIterator::getCurrent() const
{
	if (!this->valid())
	{
		throw std::runtime_error("Invalid iterator!");
	}
	return current->el;
}

