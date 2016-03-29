#ifndef MATRIX_H
#define MATRIX_H

//TODO: virtual pour quelles op�s ?

#include <iostream>

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

	CMatrix<T> operator/(const T) const;
	CMatrix<T>& operator/=(const T);

	CMatrix<T> MATtranspose();

	CMatrix<T>& operator=(const CMatrix<T>&);

	bool operator==(const CMatrix<T>&);
	bool operator!=(const CMatrix<T>&);

	T& operator()(unsigned int uiRow, unsigned int uiColumn); //Version to set
	T operator()(unsigned int uiRow, unsigned int uiColumn) const; //Version to get

	unsigned int const MATgetCountRows() const;
	unsigned int const MATgetCountColumns() const;

private:
	//protected si h�ritage matrice dynamique
	unsigned int uiCountRows, uiCountColumns;
	T*** ppptMatData;
};

//Free functions
template <class T> CMatrix<T> operator*(const T, const CMatrix<T>&);
template <class T> std::ostream& operator<<(std::ostream& out, const CMatrix<T>&);

#include "Matrix.hpp"

#endif //MATRIX_H
