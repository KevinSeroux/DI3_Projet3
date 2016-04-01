/* --------------------------------------------------------------------
| Copyright (C) 2016 <Amoros Julien> <Seroux Kevin>                    \
|                                                                      |
| This program is free software: you can redistribute it and/or modify |
| it under the terms of the GNU General Public License as published by |
| the Free Software Foundation, either version 3 of the License, or    |
| (at your option) any later version.                                  |
|                                                                      |
| This program is distributed in the hope that it will be useful,      |
| but WITHOUT ANY WARRANTY; without even the implied warranty of       |
| MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the         |
| GNU General Public License for more details.                         |
|                                                                      |
| You should have received a copy of the GNU General Public License    |
| along with this program. If not, see <http://www.gnu.org/licenses/>. |
|-------------------------------------------------------------------*/

#ifdef _DEBUG //To detect memory leaks
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

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

	#ifdef _DEBUG //Display memleaks
	_CrtDumpMemoryLeaks();
	#endif

	return 0;
}
