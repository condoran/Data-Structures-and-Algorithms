#pragma once
//#include "MatrixIterator.h"
#include <stdexcept>
#include <vector>
#include <utility>

using namespace std;

typedef int TKey;
typedef int TValue;
typedef std::pair <TKey, TKey> TCord;
typedef std::pair <TCord, TValue> TElem;

class MatrixIterator;

struct node
{
	TElem info;
	int next, prev;
};

struct DLLA
{
	node* nodes;
	int capacity, head, tail, firstEmpty, size;
};

class Matrix
{
	friend class MatrixIterator;
private:
	int nrL, nrC;
public:
	DLLA dllaMatrix;
	Matrix(int nrLines, int nrCol);
	int nrLines();
	int nrColumns();
	TValue element(TKey i,TKey j);
	TValue modify(TKey i, TKey j, TValue val);
	MatrixIterator iterator() const;
	~Matrix();
};