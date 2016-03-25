#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

template <class T>
class CMatrix
{
public:
	CMatrix(unsigned int uiCountRows, unsigned int uiCountColumns);

	CMatrix<T> operator+(const CMatrix<T>&) const;
	CMatrix<T>& operator+=(const CMatrix<T>&);

	CMatrix<T> operator-(const CMatrix<T>&) const;
	CMatrix<T>& operator-=(const CMatrix<T>&);

	CMatrix<T> operator*(const CMatrix<T>&) const;
	CMatrix<T>& operator*=(const CMatrix<T>&);
	CMatrix<T> operator*(const T) const;
	CMatrix<T>& operator*=(const T);

	CMatrix<T> operator/(const CMatrix<T>&) const;
	CMatrix<T>& operator/=(const CMatrix<T>&);
	CMatrix<T> operator/(const T) const;
	CMatrix<T>& operator/=(const T);

	CMatrix<T> transpose();

	CMatrix<T>& operator=(const CMatrix<T>&);

	bool operator==(const CMatrix<T>&);

	T operator()(unsigned int uiRow, unsigned int uiColumn);

	std::ostream& operator<<(std::ostream& stream);
};

//Free functions
template <class T> CMatrix<T> operator*(const T, const CMatrix<T>&);
template <class T> CMatrix<T> operator/(const T, const CMatrix<T>&);

#include "Matrix.hpp"

#endif //MATRIX_H