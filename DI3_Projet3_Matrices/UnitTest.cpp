#include "UnitTest.h"

CUnitTest::CUnitTest(void)
{
}


CUnitTest::~CUnitTest(void)
{
}


void CUnitTest::test_matrices()
{
	CMatrix<int> mat1(3,3);
	CMatrix<int> mat2(3,3);
	CMatrix<int> mat = mat1 + mat2;
}
