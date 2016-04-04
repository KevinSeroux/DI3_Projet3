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

#ifdef _DEBUG //Pour détecter les fuites mémoires
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
	// On exécute les tests unitaires en mode DEBUG
	#ifdef _DEBUG
	cout << "DEBUT TEST UNITAIRE" << endl << "===================" << endl;
	CUnitTest tests;
	tests.testMatrix();
	cout << "FIN TEST UNITAIRE" << endl << "=================" << endl;
	#endif

	if(argc >= 2)
	{
		int iloop;
		double dvalue;
		CMatrix<double>** tabMat = new CMatrix<double>*[argc - 1]; //VS ne supporte pas les VLA

		//Charge tous les fichiers rentrés en paramètre
		for(iloop = 1; iloop < argc; iloop++)
		{
			CMatrix<double> pMATtmp = CFileLoaderMatrix::FLMload(argv[iloop]);
			tabMat[iloop - 1] = new CMatrix<double>(pMATtmp);
		}

		cout << "Entrez une valeur par laquelle matrices en argument vont être multiplié/divisé : ";
		cin >> dvalue; //Demande valeur à l'utilisateur

		for(iloop = 1; iloop < argc; iloop++)   //Afficher toute les matrices * c
			cout << "M" << iloop << (*tabMat[iloop - 1] * dvalue);

		for(iloop = 1; iloop < argc; iloop++)   //Afficher toute les matrices / c
			cout << "M" << iloop << (*tabMat[iloop - 1] / dvalue);
	
		CMatrix<double> MATres(tabMat[0]->MATgetCountRows(), tabMat[0]->MATgetCountColumns());
		MATres = *tabMat[0];
		for(iloop = 2; iloop < argc; iloop++)   //Afficher la somme des matrices
			MATres += *tabMat[iloop - 1];
		cout << "M1+M2+M3+...=" << MATres;

		MATres = *tabMat[0];
		for(iloop = 2; iloop < argc; iloop++)   //Afficher le résultat de M1-M2+M3-...
		{
			if(iloop % 2 == 1)
				MATres -= *tabMat[iloop - 1];
			if(iloop % 2 == 0)
				MATres += *tabMat[iloop - 1];
		}
		cout << "M1-M2+M3-...=" << MATres;

		MATres = *tabMat[0];
		for(iloop = 1; iloop < argc; iloop++)   //Afficher le résultat du produit des matrices
			MATres = MATres * *tabMat[iloop - 1];
		cout << "M1*M2*M3*...=" << MATres;

		
		for(iloop = 1; iloop < argc; iloop++)
			delete tabMat[iloop - 1];
		delete[] tabMat;
	}
	else
		cout << "Merci de rentrer des fichiers de matrice en paramètre" << endl;

	//On affiche les éventuelles fuites mémoires
	#ifdef _DEBUG
	_CrtDumpMemoryLeaks();
	#endif

	return 0;
}
