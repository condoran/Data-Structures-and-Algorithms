#include "MatrixIterator.h"
#include <exception>
#include "Matrix.h"


MatrixIterator::MatrixIterator(const Matrix& m) : m(m)
{
	this->fmm = m.dllaMatrix;
	this->currentElem = this->fmm.head;
}


void MatrixIterator::first()
{
	this->currentElem = this->fmm.head;
}

void MatrixIterator::next()
{
	if (!valid())
	{
		throw std::bad_exception();
	}
	this->currentElem = this->fmm.nodes[currentElem].next;
}

bool MatrixIterator::valid() const
{
	return this->currentElem != -1;
}

TValue MatrixIterator::getCurrent() const
{
	return this->fmm.nodes[currentElem].info.second;
}
