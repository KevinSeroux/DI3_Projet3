#include "UnitTest.h"
#include "Cexception.h"

CUnitTest::CUnitTest()
{
}

CUnitTest::~CUnitTest()
{
}

static void testMatrixConstructorByDefault()
{
	CMatrix<int> MAT(3, 4);
	assert(MAT.MATgetCountRows() == 3);
	assert(MAT.MATgetCountColumns() == 4);
}

static void testMatrixConstructorByCopy()
{
	CMatrix<int> MAT(3, 2);
	MAT(0, 0) = 11;
	MAT(0, 1) = 12;
	MAT(1, 0) = 21;
	MAT(1, 1) = 22;
	MAT(2, 0) = 31;
	MAT(2, 1) = 32;

	CMatrix<int> MATCopy(MAT);

	//To test if there is a copy of value and not a copy of address
	MAT(1, 0) = 42;

	assert(MATCopy.MATgetCountRows() == 3);
	assert(MATCopy.MATgetCountColumns() == 2);
	assert(MATCopy(0, 0) == 11);
	assert(MATCopy(0, 1) == 12);
	assert(MATCopy(1, 0) == 21);
	assert(MATCopy(1, 1) == 22);
	assert(MATCopy(2, 0) == 31);
	assert(MATCopy(2, 1) == 32);
}

static void testMatrixOperatorEqual()
{
	CMatrix<int> MAT(2, 2);
	MAT(0, 0) = 11;
	MAT(0, 1) = 12;
	MAT(1, 0) = 21;
	MAT(1, 1) = 22;

	CMatrix<int> MATCopy(2,2);
	MATCopy = MAT;

	assert(MATCopy(0, 0) == 11);
	assert(MATCopy(0, 1) == 12);
	assert(MATCopy(1, 0) == 21);
	assert(MATCopy(1, 1) == 22);
}

static void testMatrixOperatorParenthesis()
{
	CMatrix<int> MAT(2, 3);
	MAT(1,2) = 43;
	assert(MAT(1,2) == 43);
}

static void testMatrixOperatorAdd()
{
	CMatrix<int> MAT1(2, 2);
	MAT1(0, 0) = 111;
	MAT1(0, 1) = 112;
	MAT1(1, 0) = 121;
	MAT1(1, 1) = 122;

	CMatrix<int> MAT2(2, 2);
	MAT2(0, 0) = 211;
	MAT2(0, 1) = 212;
	MAT2(1, 0) = 221;
	MAT2(1, 1) = 222;

	CMatrix<int> MAT(2, 2);
	MAT = MAT1 + MAT2;

	assert(MAT(0, 0) == 322);
	assert(MAT(0, 1) == 324);
	assert(MAT(1, 0) == 342);
	assert(MAT(1, 1) == 344);
}

static void testMatrixOperatorStream()
{
    CMatrix<int> MAT1(2, 2);
	MAT1(0, 0) = 111;
	MAT1(0, 1) = 112;
	MAT1(1, 0) = 121;
	MAT1(1, 1) = 122;
	std::cout << MAT1;

	CMatrix<double> MAT2(2, 2);
	MAT2(0, 0) = .111;
	MAT2(0, 1) = 1.12;
	MAT2(1, 0) = 12.1;
	MAT2(1, 1) = 122.;
	std::cout << MAT2;
}

static void testMatrixOperatorMult()
{
    CMatrix<int> O(2, 2);
	O(0, 0) = 0;
	O(0, 1) = 0;
	O(1, 0) = 0;
	O(1, 1) = 0;

	CMatrix<int> I(2, 2);
	I(0, 0) = 1;
	I(0, 1) = 0;
	I(1, 0) = 0;
	I(1, 1) = 1;

	CMatrix<int> MAT(2, 2);
	MAT(0, 0) = 11;
	MAT(0, 1) = 12;
	MAT(1, 0) = 21;
	MAT(1, 1) = 22;

    CMatrix<int> MATLig(1, 3); //tester avec matrices tailles !=
	MATLig(0, 0) = 1;
	MATLig(0, 1) = 2;
	MATLig(0, 2) = 1;

	CMatrix<int> MATCol(3, 1);
	MATCol(0, 0) = 2;
	MATCol(1, 0) = 4;
	MATCol(2, 0) = 8;

	std::cout << (2 * MATCol);
	std::cout << (MATCol * 2);

	if(!((MAT * O) == O))
        assert(false);
    if(!((MAT * I) == MAT))
        assert(false);
}

static void testMatrixOperatorEquality()
{
    CMatrix<int> MAT(2, 2);
	MAT(0, 0) = 11;
	MAT(0, 1) = 12;
	MAT(1, 0) = 21;
	MAT(1, 1) = 22;

	CMatrix<int> MAT2(2, 2);
	MAT2(0, 0) = 11;
	MAT2(0, 1) = 12;
	MAT2(1, 0) = 21;
	MAT2(1, 1) = 0;

	CMatrix<int> MAT3(1, 2);
	MAT3(0, 0) = 11;
	MAT3(0, 1) = 12;

    if(!(MAT == MAT))
        assert(false);
    if(MAT == MAT2)
        assert(false);
    try{
        MAT == MAT3;
        assert(false);
    }catch(Cexception*)
    {
        //Gestion de l'exception
    }
}

void CUnitTest::testMatrix()
{
	testMatrixConstructorByDefault();
	testMatrixConstructorByCopy();
	testMatrixOperatorEqual();
	testMatrixOperatorParenthesis();
	testMatrixOperatorAdd();
	testMatrixOperatorStream();
	testMatrixOperatorMult();
	testMatrixOperatorEquality();
}
