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
    int iloop;
    double dvalue;
    CMatrix<double>** tabMat = new CMatrix<double>*[argc]; //VS does not support VLA

	/*CUnitTest tests;
	tests.testMatrix();*/

    for(iloop = 1; iloop <= argc; iloop++)
        tabMat[iloop - 1] = &CFileLoaderMatrix::FLMload(argv[iloop]);

    scanf("c = ?", &dvalue);    //Demande valeur à l'utilisateur

    for(iloop = 0; iloop < argc; iloop++)   //Afficher toute les matrices * c
        cout << "M" << iloop << (*tabMat[iloop] * dvalue);

    for(iloop = 0; iloop < argc; iloop++)   //Afficher toute les matrices / c
        cout << "M" << iloop << (*tabMat[iloop] / dvalue);
	
    CMatrix<double> MATres(tabMat[0]->MATgetCountRows(), tabMat[0]->MATgetCountColumns());
    MATres = *tabMat[0];
    for(iloop = 1; iloop < argc; iloop++)   //Afficher la somme des matrices
        MATres += *tabMat[iloop];
    cout << "M1+M2+M3+...=" << MATres;

    MATres = *tabMat[0];
    for(iloop = 1; iloop < argc; iloop++)   //Afficher le résultat de M1-M2+M3-...
    {
        if(iloop % 2 == 1)
            MATres -= *tabMat[iloop];
        if(iloop % 2 == 0)
            MATres += *tabMat[iloop];
    }
    cout << "M1-M2+M3-...=" << MATres;

    MATres = *tabMat[0];
    for(iloop = 1; iloop < argc; iloop++)   //Afficher le résultat du produit des matrices
        MATres = MATres * *tabMat[iloop];
    cout << "M1*M2*M3*...=" << MATres;

	delete[] tabMat;

	#ifdef _DEBUG //Display memleaks
	_CrtDumpMemoryLeaks();
	#endif

	return 0;
}
