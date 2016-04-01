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

#include <cassert> //TODO: To remove when all the methods are implemented
#include "Cexception.h"
//TODO: Fonction qui itére sur les lignes, colonnes avec une fonction callback

#define BEGIN_FOREACH_CELL                                         \
	unsigned int uiCurrentRow = 0;                                 \
	for(; uiCurrentRow < uiCountRows; uiCurrentRow++)              \
	{                                                              \
		unsigned int uiCurrentColumn = 0;                          \
		for(; uiCurrentColumn < uiCountColumns; uiCurrentColumn++) \
		{
#define END_FOREACH_CELL                                           \
	    }                                                          \
	}                                                              \

using namespace std;

template <class T>
CMatrix<T>::CMatrix(unsigned int uiCountRows, unsigned int uiCountColumns)
{
    if(uiCountColumns == 0 || uiCountRows == 0)
        throw Cexception(ZERO_SIZED_MATRIX);

	this->uiCountRows = uiCountRows;
	this->uiCountColumns = uiCountColumns;

	ppptMatData = new T**[uiCountRows];
	unsigned int uiCurrentRow = 0;
	for(; uiCurrentRow < uiCountRows; uiCurrentRow++)
	{
		ppptMatData[uiCurrentRow] = new T*[uiCountColumns];

		unsigned int uiCurrentColumn = 0;
		for(; uiCurrentColumn < uiCountColumns; uiCurrentColumn++)
			ppptMatData[uiCurrentRow][uiCurrentColumn] = new T;
	}
}

template <class T>
CMatrix<T>::CMatrix(const CMatrix<T>& MATParam)
{
	uiCountRows = MATParam.uiCountRows;
	uiCountColumns = MATParam.uiCountColumns;

	ppptMatData = new T**[uiCountRows];

	unsigned int uiCurrentRow = 0;
	for(; uiCurrentRow < uiCountRows; uiCurrentRow++)
	{
		ppptMatData[uiCurrentRow] = new T*[uiCountColumns];
		unsigned int uiCurrentColumn = 0;
		for(; uiCurrentColumn < uiCountColumns; uiCurrentColumn++)
		{
			ppptMatData[uiCurrentRow][uiCurrentColumn] = new T;
			(*this)(uiCurrentRow, uiCurrentColumn) = MATParam(uiCurrentRow, uiCurrentColumn);
		}
	}
}

template <class T>
CMatrix<T>::~CMatrix()
{
	unsigned int uiCurrentRow = 0;
	for(; uiCurrentRow < uiCountRows; uiCurrentRow++)
	{
		unsigned int uiCurrentColumn = 0;
		for(; uiCurrentColumn < uiCountColumns; uiCurrentColumn++)
			delete ppptMatData[uiCurrentRow][uiCurrentColumn];

		delete[] ppptMatData[uiCurrentRow];
	}

	delete[] ppptMatData;
}


template <class T>
CMatrix<T> CMatrix<T>::operator+(const CMatrix<T>& MATParam) const
{
	if(uiCountRows != MATParam.uiCountRows || uiCountColumns != MATParam.uiCountRows)
	   throw Cexception(EXC_SIZE_INVALID);

	CMatrix<T> MATreturn(uiCountRows, uiCountColumns);

	BEGIN_FOREACH_CELL
	MATreturn(uiCurrentRow, uiCurrentColumn) = 
	(*this)(uiCurrentRow, uiCurrentColumn) + MATParam(uiCurrentRow, uiCurrentColumn);
	END_FOREACH_CELL

	return MATreturn;
}

template <class T>
CMatrix<T>& CMatrix<T>::operator+=(const CMatrix<T>& MATParam)
{
	if(uiCountRows != MATParam.uiCountRows || uiCountColumns != MATParam.uiCountRows)
	   throw Cexception(EXC_SIZE_INVALID);
	
	BEGIN_FOREACH_CELL
	(*this)(uiCurrentRow, uiCurrentColumn) =
	(*this)(uiCurrentRow, uiCurrentColumn) + MATParam(uiCurrentRow, uiCurrentColumn);
	END_FOREACH_CELL

	return *this;
}


template <class T>
CMatrix<T> CMatrix<T>::operator-(const CMatrix<T>& MATParam) const
{
	if(uiCountRows != MATParam.uiCountRows || uiCountColumns != MATParam.uiCountRows)
	   throw Cexception(EXC_SIZE_INVALID);

	CMatrix<T> MAT2return(uiCountRows, uiCountColumns);

	BEGIN_FOREACH_CELL
	MAT2return(uiCurrentRow, uiCurrentColumn) =
	(*this)(	uiCurrentRow, uiCurrentColumn) - MATParam(uiCurrentRow, uiCurrentColumn);
	END_FOREACH_CELL

	return MAT2return;
}

template <class T>
CMatrix<T>& CMatrix<T>::operator-=(const CMatrix<T>& MATParam)
{
	if(uiCountRows != MATParam.uiCountRows || uiCountColumns != MATParam.uiCountRows)
	   throw Cexception(EXC_SIZE_INVALID);

	BEGIN_FOREACH_CELL
	(*this)(uiCurrentRow, uiCurrentColumn) -= MATParam(uiCurrentRow, uiCurrentColumn);
	END_FOREACH_CELL

	return *this;
}


//TODO: Optimiser
template <class T>
CMatrix<T> CMatrix<T>::operator*(const CMatrix<T>& MATparam) const
{
    unsigned int uiloopRow, uiloopColumn, uiloopAdd, uinbAdd;

    if(MATgetCountColumns() != MATparam.MATgetCountRows())
        throw Cexception(INVALID_MATRIX_SIZE_FOR_THIS_OPERATION);

    CMatrix<T> MATres(MATgetCountRows(), MATparam.MATgetCountColumns());
    for(uiloopRow = 0; uiloopRow < MATres.MATgetCountRows(); uiloopRow++)
    {
        for(uiloopColumn = 0; uiloopColumn < MATres.MATgetCountColumns(); uiloopColumn++)
        {
            MATres(uiloopRow, uiloopColumn) = 0;
        }
    }

    uinbAdd = MATgetCountColumns();

    for(uiloopRow = 0; uiloopRow < MATres.MATgetCountRows(); uiloopRow++)
    {
        for(uiloopColumn = 0; uiloopColumn < MATres.MATgetCountColumns(); uiloopColumn++)
        {
            for(uiloopAdd = 0; uiloopAdd < uinbAdd; uiloopAdd++)
            {
                MATres(uiloopRow, uiloopColumn) = MATres(uiloopRow, uiloopColumn)
                + this->operator()(uiloopRow, uiloopAdd) * MATparam(uiloopAdd, uiloopColumn);
            }
        }
    }

	return MATres;
}

template <class T>
CMatrix<T> CMatrix<T>::operator*(const T value) const
{
	CMatrix<T> MATres(MATgetCountRows(), MATgetCountColumns());
	
	BEGIN_FOREACH_CELL
    MATres(uiCurrentRow, uiCurrentColumn) = (*this)(uiCurrentRow, uiCurrentColumn) * value;
	END_FOREACH_CELL

	return MATres;
}

template <class T>
CMatrix<T>& CMatrix<T>::operator*=(const T value)
{
	BEGIN_FOREACH_CELL
	(*this)(uiCurrentRow, uiCurrentColumn) = (*this)(uiCurrentRow, uiCurrentColumn) * value;
	END_FOREACH_CELL

	return *this;
}


template <class T>
CMatrix<T> CMatrix<T>::operator/(const T tValue) const
{
	if(tValue == 0)
	   throw Cexception(DIVIDE_BY_ZERO);

	CMatrix<T> MAT2return(uiCountRows, uiCountColumns);

	BEGIN_FOREACH_CELL
	MAT2return(uiCurrentRow, uiCurrentColumn) =
	(*this)(uiCurrentRow, uiCurrentColumn) / tValue;
	END_FOREACH_CELL

	return MAT2return;
}

template <class T>
CMatrix<T>& CMatrix<T>::operator/=(const T tValue)
{
	if(tValue == 0)
	   throw Cexception(DIVIDE_BY_ZERO);

	BEGIN_FOREACH_CELL
	(*this)(uiCurrentRow, uiCurrentColumn) /= tValue;
	END_FOREACH_CELL

	return *this;
}


template <class T>
CMatrix<T> CMatrix<T>::MATtranspose()
{
	CMatrix<T> MATres(MATgetCountRows(), MATgetCountColumns());

	BEGIN_FOREACH_CELL
    MATres(uiloopRow, uiloopColumn) = (*this)(uiloopColumn, uiloopRow);
	END_FOREACH_CELL

	return MATres;
}

template <class T>
CMatrix<T>& CMatrix<T>::operator=(const CMatrix<T>& MATParam)
{
	BEGIN_FOREACH_CELL
	(*this)(uiCurrentRow, uiCurrentColumn) = MATParam(uiCurrentRow, uiCurrentColumn);
	END_FOREACH_CELL

	return *this;
}


template <class T>
bool CMatrix<T>::operator==(const CMatrix<T>& MATparam)
{
	//assert(false && "Not Implemented Yet");

    if(MATgetCountColumns() != MATparam.MATgetCountColumns()
        || MATgetCountRows() != MATparam.MATgetCountRows())
            throw Cexception(UNCOMPARABLE_MATRIX);

	BEGIN_FOREACH_CELL
	if(this->operator()(uiCurrentRow, uiCurrentColumn) != MATparam(uiCurrentRow, uiCurrentColumn))
		return false;
	END_FOREACH_CELL

	return true;
}

template <class T>
inline bool CMatrix<T>::operator!=(const CMatrix<T>& MATParam)
{
	return !operator==(MATParam);
}


template <class T>
inline T& CMatrix<T>::operator()(unsigned int uiRow, unsigned int uiColumn)
{
	if(uiRow >= this->MATgetCountRows() || uiColumn >= this->MATgetCountColumns())
        throw Cexception(INDEX_OUT_OF_BOUND);

	return *ppptMatData[uiRow][uiColumn];
}

template <class T>
inline T CMatrix<T>::operator()(unsigned int uiRow, unsigned int uiColumn) const
{
	if(uiRow >= this->MATgetCountRows() || uiColumn >= this->MATgetCountColumns())
        throw Cexception(INDEX_OUT_OF_BOUND);

	return *ppptMatData[uiRow][uiColumn];
}


template <class T>
inline unsigned int const CMatrix<T>::MATgetCountRows() const
{
	return uiCountRows;
}

template <class T>
inline unsigned int const CMatrix<T>::MATgetCountColumns() const
{
	return uiCountColumns;
}

//Free functions
template <class T>
CMatrix<T> operator*(const T value, const CMatrix<T>& MATparam)
{
	CMatrix<T> MATres(MATparam.uiCountRows, MATparam.uiCountColumns);
	
	int uiCountRows = MATparam.uiCountRows;
	int uiCountColumns = MATparam.uiCountColumns;

	BEGIN_FOREACH_CELL
	MATres(uiCurrentRow, uiCurrentColumn) = MATparam(uiCurrentRow, uiCurrentColumn) * value;
	END_FOREACH_CELL

	return MATres;
}

template <class T>
std::ostream& operator<<(std::ostream& out, const CMatrix<T>& MAT)
{
    out << '[' << std::endl;

	int uiCountRows = MAT.uiCountRows;
	int uiCountColumns = MAT.uiCountColumns;

	BEGIN_FOREACH_CELL
    out << MAT(uiCurrentRow, uiCurrentColumn) << ' ';
	END_FOREACH_CELL

	out << ']' << std::endl;

	return out;
}
