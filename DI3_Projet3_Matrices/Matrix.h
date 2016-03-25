#ifndef MATRIX_H
#define MATRIX_H

template <class T>
class CMatrix
{
public:
	CMatrix(unsigned int uiCountRows, unsigned int uiCountColumns);
	CMatrix<T> operator+(const CMatrix<T>&) const;
	CMatrix<T>& operator=(const CMatrix<T>&);
};

#include "Matrix.hpp"

#endif //MATRIX_H