#include <iostream>
#include "FileLoaderMatrix.h"
#include "Matrix.h"
#include "UnitTest.h"

int main(int argc, char* argv[])
{
	CUnitTest tests;
	tests.testMatrix();

	char const * str = "mat1.txt";
    //cout << argc;
    //cout << argv[1] << '\n';
    //cout << argv[2] << '\n';

	CFileLoaderMatrix::FLMload(str);

	return 0;
}
