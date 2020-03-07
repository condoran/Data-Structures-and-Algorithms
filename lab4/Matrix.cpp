#include "Matrix.h"
#include "MatrixIterator.h"



Matrix::Matrix(int nrLines, int nrCol)
{
	if (nrLines <= 0 || nrCol <= 0)
		throw std::runtime_error("Invalid Matrix!");
	nrL = nrLines;
	nrC = nrCol;
	//int l, c;
	dllaMatrix.capacity = nrL * nrC;
	dllaMatrix.head = 0;
	dllaMatrix.tail = nrL * nrC - 1;
	dllaMatrix.size = 0;
	dllaMatrix.firstEmpty = 0;
	dllaMatrix.nodes = new node[nrC * nrL];
	for (int i = 0; i < nrL * nrC - 1; i++)
	{
		dllaMatrix.nodes[i].info.first.first = i / nrC + 1;
		dllaMatrix.nodes[i].info.first.second = i % nrC + 1;
		dllaMatrix.nodes[i].info.second = 0;
		dllaMatrix.nodes[i].next = i + 1;
		//l++;
	}
	dllaMatrix.nodes[nrL * nrC - 1].info.first.first = nrL;
	dllaMatrix.nodes[nrL * nrC - 1].info.first.second = nrC;
	dllaMatrix.nodes[nrL * nrC - 1].info.second = 0;
	dllaMatrix.nodes[nrL * nrC - 1].next = -1;
	for (int i = 1; i < nrC * nrL; i++)
	{
		this->dllaMatrix.nodes[i].prev = i - 1;
	}
	this->dllaMatrix.nodes[0].prev = -1;
}

int Matrix::nrLines()
{
	return nrL;
}

int Matrix::nrColumns()
{
	return nrC;
}

TValue Matrix::element(TKey i, TKey j)
{
	int el = this->dllaMatrix.head;
	while (el != -1)
	{
		if (this->dllaMatrix.nodes[el].info.first.first == i and this->dllaMatrix.nodes[el].info.first.second == j)
			return this->dllaMatrix.nodes[el].info.second;
		el = this->dllaMatrix.nodes[el].next;
	}
	throw std::runtime_error("Invalid position!");
}

TValue Matrix::modify(TKey i, TKey j, TValue val)
{
	int ok = 0,el = this->dllaMatrix.head;
	TValue old = -1;
	TKey v1, v2;
	while (el != -1)
	{
		v1 = this->dllaMatrix.nodes[el].info.first.first;
		v2 = this->dllaMatrix.nodes[el].info.first.second;
		if (v1 == i and v2 == j)
		{
			old = this->dllaMatrix.nodes[el].info.second;
			this->dllaMatrix.nodes[el].info.second = val;
			return old;
		}
		el = this->dllaMatrix.nodes[el].next;
	}
	throw std::runtime_error("Invalid position!");
	//return 0;
}

MatrixIterator Matrix::iterator() const
{
	return MatrixIterator(*this);
}



Matrix::~Matrix()
{
}
