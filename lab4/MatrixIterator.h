#pragma once
#include "Matrix.h"

class Matrix;

class MatrixIterator
{
	friend class Matrix;
private:
	MatrixIterator(const Matrix& m);
	const Matrix& m;
	DLLA fmm;
	int currentElem;
public:
	void first();
	void next();
	bool valid() const;
	TValue getCurrent() const;
};

