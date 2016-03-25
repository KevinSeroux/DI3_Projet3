#include <iostream>
#include "FileLoaderMatrix.h"
#include "Matrix.h"
#include "UnitTest.h"

int main(int argc, char* argv[])
{
	CUnitTest tests;
	tests.test_matrices();

	char * str = "mat1.txt";

	CFileLoaderMatrix::FLMload(str);

	return 0;
}