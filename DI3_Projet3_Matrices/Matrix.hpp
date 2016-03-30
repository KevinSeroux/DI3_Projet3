#include <cassert> //TODO: To remove when all the methods are implemented
#include "Cexception.h"
//TODO: Fonction qui itére sur les lignes, colonnes avec une fonction callback

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

	unsigned int uiCurrentRow = 0;
	for(; uiCurrentRow < uiCountRows; uiCurrentRow++)
	{
		unsigned int uiCurrentColumn = 0;
		for(; uiCurrentColumn < uiCountColumns; uiCurrentColumn++)
		{
			MATreturn(uiCurrentRow, uiCurrentColumn) =
			(*this)(uiCurrentRow, uiCurrentColumn) + MATParam(uiCurrentRow, uiCurrentColumn);
		}
	}

	return MATreturn;
}

template <class T>
CMatrix<T>& CMatrix<T>::operator+=(const CMatrix<T>& MATParam)
{
	if(uiCountRows != MATParam.uiCountRows || uiCountColumns != MATParam.uiCountRows)
	   throw Cexception(EXC_SIZE_INVALID);

	unsigned int uiCurrentRow = 0;
	for(; uiCurrentRow < uiCountRows; uiCurrentRow++)
	{
		unsigned int uiCurrentColumn = 0;
		for(; uiCurrentColumn < uiCountColumns; uiCurrentColumn++)
		{
			(*this)(uiCurrentRow, uiCurrentColumn) =
			(*this)(uiCurrentRow, uiCurrentColumn) + MATParam(uiCurrentRow, uiCurrentColumn);
		}
	}

	return *this;
}


template <class T>
CMatrix<T> CMatrix<T>::operator-(const CMatrix<T>& MATParam) const
{
	if(uiCountRows != MATParam.uiCountRows || uiCountColumns != MATParam.uiCountRows)
	   throw Cexception(EXC_SIZE_INVALID);

	CMatrix<T> MAT2return(uiCountRows, uiCountColumns);

	unsigned int uiCurrentRow = 0;
	for(; uiCurrentRow < uiCountRows; uiCurrentRow++)
	{
		unsigned int uiCurrentColumn = 0;
		for(; uiCurrentColumn < uiCountColumns; uiCurrentColumn++)
		{
			MAT2return(uiCurrentRow, uiCurrentColumn) =
			(*this)(uiCurrentRow, uiCurrentColumn) - MATParam(uiCurrentRow, uiCurrentColumn);
		}
	}

	return MAT2return;
}

template <class T>
CMatrix<T>& CMatrix<T>::operator-=(const CMatrix<T>& MATParam)
{
	if(uiCountRows != MATParam.uiCountRows || uiCountColumns != MATParam.uiCountRows)
	   throw Cexception(EXC_SIZE_INVALID);

	unsigned int uiCurrentRow = 0;
	for(; uiCurrentRow < uiCountRows; uiCurrentRow++)
	{
		unsigned int uiCurrentColumn = 0;
		for(; uiCurrentColumn < uiCountColumns; uiCurrentColumn++)
		{
			(*this)(uiCurrentRow, uiCurrentColumn) -= MATParam(uiCurrentRow, uiCurrentColumn);
		}
	}

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

	unsigned int uiloopRow, uiloopColumn;
    for(uiloopRow = 0; uiloopRow < MATgetCountRows(); uiloopRow++)
    {
        for(uiloopColumn = 0; uiloopColumn < MATgetCountColumns(); uiloopColumn++)
        {
            MATres(uiloopRow, uiloopColumn) = (*this)(uiloopRow, uiloopColumn) * value;
        }
    }

	return MATres;
}

template <class T>
CMatrix<T>& CMatrix<T>::operator*=(const T value)
{
	unsigned int uiloopRow, uiloopColumn;
    for(uiloopRow = 0; uiloopRow < MATgetCountRows(); uiloopRow++)
    {
        for(uiloopColumn = 0; uiloopColumn < MATgetCountColumns(); uiloopColumn++)
        {
            (*this)(uiloopRow, uiloopColumn) = (*this)(uiloopRow, uiloopColumn) * value;
        }
    }

	return *this;
}


template <class T>
CMatrix<T> CMatrix<T>::operator/(const T tValue) const
{
	if(tValue == 0)
	   throw Cexception(DIVIDE_BY_ZERO);

	CMatrix<T> MAT2return(uiCountRows, uiCountColumns);

	unsigned int uiCurrentRow = 0;
	for(; uiCurrentRow < uiCountRows; uiCurrentRow++)
	{
		unsigned int uiCurrentColumn = 0;
		for(; uiCurrentColumn < uiCountColumns; uiCurrentColumn++)
		{
			MAT2return(uiCurrentRow, uiCurrentColumn) =
			(*this)(uiCurrentRow, uiCurrentColumn) / tValue;
		}
	}

	return MAT2return;
}

template <class T>
CMatrix<T>& CMatrix<T>::operator/=(const T tValue)
{
	if(tValue == 0)
	   throw Cexception(DIVIDE_BY_ZERO);

	unsigned int uiCurrentRow = 0;
	for(; uiCurrentRow < uiCountRows; uiCurrentRow++)
	{
		unsigned int uiCurrentColumn = 0;
		for(; uiCurrentColumn < uiCountColumns; uiCurrentColumn++)
		{
			(*this)(uiCurrentRow, uiCurrentColumn) /= tValue;
		}
	}

	return *this;
}


template <class T>
CMatrix<T> CMatrix<T>::MATtranspose()
{
	CMatrix<T> MATres(MATgetCountRows(), MATgetCountColumns());

	unsigned int uiloopRow, uiloopColumn;
    for(uiloopRow = 0; uiloopRow < MATgetCountRows(); uiloopRow++)
    {
        for(uiloopColumn = 0; uiloopColumn < MATgetCountColumns(); uiloopColumn++)
        {
            MATres(uiloopRow, uiloopColumn) = (*this)(uiloopColumn, uiloopRow);
        }
    }

	return MATres;
}

template <class T>
CMatrix<T>& CMatrix<T>::operator=(const CMatrix<T>& MATParam)
{
	unsigned int uiCurrentRow = 0;
	for(; uiCurrentRow < uiCountRows; uiCurrentRow++)
	{
		unsigned int uiCurrentColumn = 0;
		for(; uiCurrentColumn < uiCountColumns; uiCurrentColumn++)
		{
			(*this)(uiCurrentRow, uiCurrentColumn) = MATParam(uiCurrentRow, uiCurrentColumn);
		}
	}

	return *this;
}


template <class T>
bool CMatrix<T>::operator==(const CMatrix<T>& MATparam)
{
	//assert(false && "Not Implemented Yet");

    if(MATgetCountColumns() != MATparam.MATgetCountColumns()
        || MATgetCountRows() != MATparam.MATgetCountRows())
            throw Cexception(UNCOMPARABLE_MATRIX);

    unsigned int uiloopRow, uiloopColumn;
    for(uiloopRow = 0; uiloopRow < MATgetCountRows(); uiloopRow++)
    {
        for(uiloopColumn = 0; uiloopColumn < MATgetCountColumns(); uiloopColumn++)
        {
            if(this->operator()(uiloopRow, uiloopColumn) != MATparam(uiloopRow, uiloopColumn))
                return false;
        }
    }
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
	//assert(false && "Not Implemented Yet");
	CMatrix<T> MATres(MATparam.MATgetCountRows(), MATparam.MATgetCountColumns());

	unsigned int uiloopRow, uiloopColumn;
    for(uiloopRow = 0; uiloopRow < MATparam.MATgetCountRows(); uiloopRow++)
    {
        for(uiloopColumn = 0; uiloopColumn < MATparam.MATgetCountColumns(); uiloopColumn++)
        {
            MATres(uiloopRow, uiloopColumn) = MATparam(uiloopRow, uiloopColumn) * value;
        }
    }
	return MATres;
}

template <class T>
std::ostream& operator<<(std::ostream& out, const CMatrix<T>& MAT)
{
    out << '[' << std::endl;

    unsigned int uiCurrentRow = 0;
	for(uiCurrentRow; uiCurrentRow < MAT.MATgetCountRows(); uiCurrentRow++)
    {
		unsigned int uiCurrentColumn = 0;
        for(; uiCurrentColumn < MAT.MATgetCountColumns(); uiCurrentColumn++)
        {
            out << MAT(uiCurrentRow, uiCurrentColumn) << ' ';
        }
        out << std::endl;
    }

	out << ']' << std::endl;

	return out;
}
