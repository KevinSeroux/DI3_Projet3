#include <cassert> //TODO: To remove when all the methods are implemented
#include "Cexception.h"
//TODO: Fonction qui itére sur les lignes, colonnes avec une fonction callback

template <class T>
CMatrix<T>::CMatrix(unsigned int uiCountRows, unsigned int uiCountColumns)
{
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

	CMatrix<T> MAT2Return(uiCountRows, uiCountColumns);

	unsigned int uiCurrentRow = 0;
	for(; uiCurrentRow < uiCountRows; uiCurrentRow++)
	{
		unsigned int uiCurrentColumn = 0;
		for(; uiCurrentColumn < uiCountColumns; uiCurrentColumn++)
		{
			MAT2Return(uiCurrentRow, uiCurrentColumn) = 
			(*this)(uiCurrentRow, uiCurrentColumn) + MATParam(uiCurrentRow, uiCurrentColumn);
		}
	}

	return MAT2Return;
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
CMatrix<T> CMatrix<T>::operator*(const CMatrix<T>&) const
{
	assert(false && "Not Implemented Yet");
	return CMatrix<T>(1,1);
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
bool CMatrix<T>::operator==(const CMatrix<T>&)
{
	assert(false && "Not Implemented Yet");
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
std::ostream& CMatrix<T>::operator<<(std::ostream& stream)
{
	assert(false && "Not Implemented Yet");
	return stream;
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