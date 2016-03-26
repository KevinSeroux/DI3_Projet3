#include "UnitTest.h"

CUnitTest::CUnitTest()
{
}

CUnitTest::~CUnitTest()
{
}

static void testMatrixConstructorByDefault()
{
	CMatrix<int> mat(3, 4);
	assert(mat.MATgetCountRows() == 3);
	assert(mat.MATgetCountColumns() == 4);
}

static void testMatrixOperatorParenthesis()
{
	CMatrix<int> mat(2, 3);
	mat(1,2) = 43;
	assert(mat(1,2) == 0);
}

void CUnitTest::testMatrix()
{
	testMatrixConstructorByDefault();
	testMatrixOperatorParenthesis();
}