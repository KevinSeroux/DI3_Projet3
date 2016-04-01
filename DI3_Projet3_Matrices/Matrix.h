/* --------------------------------------------------------------------
| Copyright (C) 2016 <Amoros Julien> <Seroux Kevin>                    \
|                                                                      |
| This program is free software: you can redistribute it and/or modify |
| it under the terms of the GNU General Public License as published by |
| the Free Software Foundation, either version 3 of the License, or    |
| (at your option) any later version.                                  |
|                                                                      |
| This program is distributed in the hope that it will be useful,      |
| but WITHOUT ANY WARRANTY; without even the implied warranty of       |
| MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the         |
| GNU General Public License for more details.                         |
|                                                                      |
| You should have received a copy of the GNU General Public License    |
| along with this program. If not, see <http://www.gnu.org/licenses/>. |
|-------------------------------------------------------------------*/

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

template <class T>
class CMatrix
{
private:
	unsigned int uiCountRows, uiCountColumns;
	T*** ppptMatData;

public:
	CMatrix(unsigned int uiCountRows, unsigned int uiCountColumns);
	CMatrix(const CMatrix<T>&);
	~CMatrix();

	CMatrix<T> operator+(const CMatrix<T>&) const;
	CMatrix<T>& operator+=(const CMatrix<T>&);

	CMatrix<T> operator-(const CMatrix<T>&) const;
	CMatrix<T>& operator-=(const CMatrix<T>&);

	CMatrix<T> operator*(const CMatrix<T>&) const;
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

	//Free functions
	template <class T> friend CMatrix<T> operator*(const T, const CMatrix<T>&);
	template <class T> friend std::ostream& operator<<(std::ostream& out, const CMatrix<T>&);
};

#include "Matrix.hpp"

#endif //MATRIX_H
