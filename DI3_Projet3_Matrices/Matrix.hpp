#include <cassert>

template <class T>
CMatrix<T>::CMatrix(unsigned int uiCountRows, unsigned int uiCountColumns)
{
	assert(false && "Not Implemented Yet");
}

template <class T>
CMatrix<T>::CMatrix(const CMatrix<T>&)
{
	assert(false && "Not Implemented Yet");
}

template <class T>
CMatrix<T>::~CMatrix()
{
	assert(false && "Not Implemented Yet");
}


template <class T>
CMatrix<T> CMatrix<T>::operator+(const CMatrix<T>&) const
{
	assert(false && "Not Implemented Yet");
	return CMatrix<T>(1,1);
}

template <class T>
CMatrix<T>& CMatrix<T>::operator+=(const CMatrix<T>&)
{
	assert(false && "Not Implemented Yet");
	return this;
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
	return this;
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
	return this;
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
	return this;
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
	return this;
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
	return this;
}


template <class T>
CMatrix<T> CMatrix<T>::transpose()
{
	assert(false && "Not Implemented Yet");
	return CMatrix<T>(1,1);
}

template <class T>
CMatrix<T>& CMatrix<T>::operator=(const CMatrix<T>&)
{
	assert(false && "Not Implemented Yet");
	return this;
}


template <class T>
bool CMatrix<T>::operator==(const CMatrix<T>&)
{
	assert(false && "Not Implemented Yet");
	return true;
}


template <class T>
T CMatrix<T>::operator()(unsigned int uiRow, unsigned int uiColumn)
{
	assert(false && "Not Implemented Yet");
	return T;
}


template <class T>
std::ostream& CMatrix<T>::operator<<(std::ostream& stream)
{
	assert(false && "Not Implemented Yet");
	return stream;
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