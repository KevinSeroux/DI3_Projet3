template <class T>
CMatrix<T>::CMatrix(const unsigned int uiCountRows, const unsigned int uiCountColumns)
{

}

template <class T>
CMatrix<T> CMatrix<T>::operator+(const CMatrix<T>&) const
{
	return CMatrix<T>(1,1);
}

template <class T>
CMatrix<T>& CMatrix<T>::operator=(const CMatrix<T>&)
{
	return this;
}