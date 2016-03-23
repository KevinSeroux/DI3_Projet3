#include "FileLoaderMat2D.h"
#include "Mat2D.h"
#include <iostream>
#include <fstream>

using namespace std;

CMat2D<double> FLMload(char* pcPath)
{
	int iboucle;
	char* cptype;
	char cboucle;
	int inbLigne;
	int inbColonne;
	CMat2D M2Dres;

	ifstream fichier("test.txt", ios::in);  // on ouvre le fichier en lecture
 
	if(fichier)  // si l'ouverture a r�ussi
	{       
		for(iboucle = 0; iboucle <= 12; iboucle++) //positionnement au d�but du type
			fichier.get(cboucle);

		iboucle = 0;
		while(cboucle != '\n') //stockage du type
		{
			iboucle++;
			realloc(cptype, iboucle*sizeof(char));
			fichier.get(cboucle);
			*(cptype + iboucle - 1) = cboucle;
		}

		for(iboucle = 0; iboucle <= 9; iboucle++) //positionnement au d�but int nblignes
			fichier.get(cboucle);
		fichier >> inbLigne;

		for(iboucle = 0; iboucle <= 11; iboucle++) //positionnement au d�but int nbcolonnes
			fichier.get(cboucle);
		fichier >> inbColonne;

		CMat2D 

		fichier.close();  // on ferme le fichier
	}
    else  // sinon
		cerr << "Impossible d'ouvrir le fichier !" << endl;
}