#include <iostream>
#include "FileLoaderMatrix.h"
#include "Matrix.h"
#include "UnitTest.h"

int main(int argc, char* argv[])
{
	CUnitTest tests;
	tests.testMatrix();

	char * str = "mat1.txt";

	CFileLoaderMatrix::FLMload(str);

	return 0;
}