#include "FileLoaderMatrix.h"
#include <iostream>
#include <fstream>

using namespace std;

CMatrix<double> CFileLoaderMatrix::FLMload(char* pcPath)
{
	int iboucle;
	char* cptype;
	char cboucle;
	int inbLigne;
	int inbColonne;
	CMatrix<double> M2Dres(0,0); //TO REPLACE

	ifstream fichier("test.txt", ios::in);  // on ouvre le fichier en lecture
 
	if(fichier)  // si l'ouverture a réussi
	{       
		for(iboucle = 0; iboucle <= 12; iboucle++) //positionnement au début du type
			fichier.get(cboucle);

		iboucle = 0;
		while(cboucle != '\n') //stockage du type
		{
			iboucle++;
			realloc(cptype, iboucle*sizeof(char));
			fichier.get(cboucle);
			*(cptype + iboucle - 1) = cboucle;
		}

		for(iboucle = 0; iboucle <= 9; iboucle++) //positionnement au début int nblignes
			fichier.get(cboucle);
		fichier >> inbLigne;

		for(iboucle = 0; iboucle <= 11; iboucle++) //positionnement au début int nbcolonnes
			fichier.get(cboucle);
		fichier >> inbColonne;

		//M2Dres = CMat2D<double>(inbLigne,inbColonne);

		fichier.close();  // on ferme le fichier
	}
    else  // sinon
		cerr << "Impossible d'ouvrir le fichier !" << endl;
	return M2Dres;
}