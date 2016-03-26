#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

#define EXC_SIZE_INVALID 0

template <class T>
class CMatrix
{
public:
	CMatrix(unsigned int uiCountRows, unsigned int uiCountColumns);
	CMatrix(const CMatrix<T>&);
	~CMatrix();

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

	CMatrix<T> MATtranspose();

	CMatrix<T>& operator=(const CMatrix<T>&);

	bool operator==(const CMatrix<T>&);

	T& operator()(unsigned int uiRow, unsigned int uiColumn);
	T operator()(unsigned int uiRow, unsigned int uiColumn) const;

	std::ostream& operator<<(std::ostream& stream);

	unsigned int const MATgetCountRows() const;
	unsigned int const MATgetCountColumns() const;

private:
	unsigned int uiCountRows, uiCountColumns;
	T*** ppptMatData;
};

//Free functions
template <class T> CMatrix<T> operator*(const T, const CMatrix<T>&);
template <class T> CMatrix<T> operator/(const T, const CMatrix<T>&);

#include "Matrix.hpp"

#endif //MATRIX_H