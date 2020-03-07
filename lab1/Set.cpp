#include "Set.h"
#include <stdlib.h>



Set::Set()
{
	min = 0;
	max = 0;
	cap = 100;
	list = (bool*)malloc(sizeof(bool) * cap);
	list[0] = 0;
}

void Set::resize()
{
	this->cap *= 2;
	this->list = (bool*)realloc(this->list, sizeof(bool) * cap);
}

bool Set::add(TElem elem)
{
	if (this->search(elem))
		return 0;
	else if (list[0] == 0)
	{
		list[0] = 1;
		min = elem;
		max = elem;
		return 1;
	}
	else if (elem > max)
	{
		while (abs(elem - min) >= this->cap)
			this->resize();
		int beg = max - min + 1;
		int fin = elem - min;
		int i;
		for (i = beg; i < fin; i++)
			list[i] = 0;
		list[i] = 1;
		max = elem;
		return 1;
	}
	else if (elem < min)
	{
		while (abs(max - elem) >= this->cap)
			this->resize();
		int r = min - elem;
		int beg = max - min + r;
		int i;
		for (i = beg; i >= r; i--)
			list[i] = list[i - r];
		for (i = r - 1; i > 0; i--)
			list[i] = 0;
		list[0] = 1;
		min = elem;
		return 1;
	}
	else if (elem > min && elem < max)
	{
		list[elem - min] = 1;
		return 1;
	}
}

bool Set::remove(TElem elem)
{
	if (this->search(elem) == 0)
		return 0;
	else if (max == min)
	{
		list[0] = 0;
		max = 0;
		min = 0;
		return 1;
	}
	else if (elem == max)
	{
		int i = max - min;
		list[i] = 0;
		while (list[i] == 0)
			i--;
		max = i + min;
		return 1;
	}
	else if (elem == min)
	{
		int i = 0;
		list[i] = 0;
		while (list[i] == 0)
			i++;
		int r = i;
		min = min + i;
		for (i = 0; i <= r; i++)
			list[i] = list[i + r];
		return 1;
	}
	else
	{
		list[elem - min] = 0;
		return 1;
	}
}

bool Set::search(TElem elem)
{
	if (list[0] == 0)
		return 0;
	if (elem > max)
		return 0;
	if (elem < min)
		return 0;
	if (list[elem - min] == 0)
		return 0;
	return 1;
}

int Set::size()
{
	if (this->isEmpty())
		return 0;
	int count = 0;
	for (int i = 0; i <= max - min; i++)
		if (list[i] == 1)
			count++;
	return count;
}

bool Set::isEmpty()
{
	if (list[0] == 0)
		return 1;
	return 0;
}

SetIterator Set::iterator()
{
	return SetIterator(max, list, min);
}

