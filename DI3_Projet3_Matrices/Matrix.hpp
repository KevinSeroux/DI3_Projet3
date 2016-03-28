#include <cassert> //TODO: To remove when all the methods are implemented
#include "Cexception.h"
//TODO: Fonction qui itére sur les lignes, colonnes avec une fonction callback

template <class T>
CMatrix<T>::CMatrix(unsigned int uiCountRows, unsigned int uiCountColumns)
{
    if(uiCountColumns == 0 || uiCountRows == 0)
        throw new Cexception(ZERO_SIZED_MATRIX);

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

//TODO: Refactor with operator=?
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
	   throw new Cexception(EXC_SIZE_INVALID);

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
CMatrix<T>& CMatrix<T>::operator+=(const CMatrix<T>&)
{
	assert(false && "Not Implemented Yet");
	return *this;
}


template <class T>
CMatrix<T> CMatrix<T>::operator-(const CMatrix<T>&) const
{
	assert(false && "Not Implemented Yet");
	return CMatrix<T>(1,1);
}

template <class T>
CMatrix<T>& CMatrix<T>::operator-=(const CMatrix<T>&)
{
	assert(false && "Not Implemented Yet");
	return *this;
}


template <class T>
CMatrix<T> CMatrix<T>::operator*(const CMatrix<T>& MATparam) const
{
    unsigned int uiloopRow, uiloopColumn, uiloopAdd, uinbAdd;

    if(MATgetCountColumns() != MATparam.MATgetCountRows())
        throw new Cexception(INVALID_MATRIX_SIZE_FOR_THIS_OPERATION);

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
	//assert(false && "Not Implemented Yet");
	return MATres;
}

template <class T>
CMatrix<T>& CMatrix<T>::operator*=(const CMatrix<T>&)
{
	assert(false && "Not Implemented Yet");
	return *this;
}

template <class T>
CMatrix<T> CMatrix<T>::operator*(const T) const
{
	assert(false && "Not Implemented Yet");
	return CMatrix<T>(1,1);
}

template <class T>
CMatrix<T>& CMatrix<T>::operator*=(const T)
{
	assert(false && "Not Implemented Yet");
	return *this;
}


template <class T>
CMatrix<T> CMatrix<T>::operator/(const CMatrix<T>&) const
{
	assert(false && "Not Implemented Yet");
	return CMatrix<T>(1,1);
}

template <class T>
CMatrix<T>& CMatrix<T>::operator/=(const CMatrix<T>&)
{
	assert(false && "Not Implemented Yet");
	return *this;
}

template <class T>
CMatrix<T> CMatrix<T>::operator/(const T) const
{
	assert(false && "Not Implemented Yet");
	return CMatrix<T>(1,1);
}

template <class T>
CMatrix<T>& CMatrix<T>::operator/=(const T)
{
	assert(false && "Not Implemented Yet");
	return *this;
}


template <class T>
CMatrix<T> CMatrix<T>::MATtranspose()
{
	assert(false && "Not Implemented Yet");
	return CMatrix<T>(1,1);
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
    if(MATgetCountColumns() != MATparam.MATgetCountColumns()
        || MATgetCountRows() != MATparam.MATgetCountRows())
            throw new Cexception(UNCOMPARABLE_MATRIX);

    unsigned int uiloopRow, uiloopColumn;
    for(uiloopRow = 0; uiloopRow < MATgetCountRows(); uiloopRow++)
    {
        for(uiloopColumn = 0; uiloopColumn < MATgetCountColumns(); uiloopColumn++)
        {
            if(this->operator()(uiloopRow, uiloopColumn) != MATparam(uiloopRow, uiloopColumn))
                return false;
        }
    }
	//assert(false && "Not Implemented Yet");
	return true;
}


template <class T>
inline T& CMatrix<T>::operator()(unsigned int uiRow, unsigned int uiColumn)
{
	//TODO: Tester que uiRow et uiColumn sont dans les bornes
	return *ppptMatData[uiRow][uiColumn];
}

template <class T>
inline T CMatrix<T>::operator()(unsigned int uiRow, unsigned int uiColumn) const
{
	//TODO: Tester que uiRow et uiColumn sont dans les bornes
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
CMatrix<T> operator*(const T, const CMatrix<T>&)
{
	assert(false && "Not Implemented Yet");
	return CMatrix<T>(1,1);
}

template <class T>
CMatrix<T> operator/(const T, const CMatrix<T>&)
{
	assert(false && "Not Implemented Yet");
	return CMatrix<T>(1,1);
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
