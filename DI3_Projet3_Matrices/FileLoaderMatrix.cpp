#include "FileLoaderMatrix.h"

CMatrix<double> CFileLoaderMatrix::FLMload(char const * pcPath){
	unsigned int iboucle, ibouclei, ibouclej;
	char* cptype = new char[32];
	char const * DOUBLE = "double";
	char cboucle;
	int inbLigne;
	int inbColonne;

	ifstream fichier("mat1.txt", ios::in);  // on ouvre le fichier en lecture

	if(fichier)  // si l'ouverture a réussi
	{
		for(iboucle = 0; iboucle <= 11; iboucle++) //positionnement au début du type
			fichier.get(cboucle);

		iboucle = 0;
		while(cboucle != '\n') //stockage du type
		{
			iboucle++;
			fichier.get(cboucle);
			*(cptype + iboucle - 1) = cboucle;
		}
		*(cptype + iboucle - 1) = 0;

		for(iboucle = 0; *(cptype + iboucle) != 0; iboucle++)	//Vérification type = double
			if(*(cptype + iboucle) != *(DOUBLE + iboucle))
				printf("Type incorrect");//throw ;

		for(iboucle = 0; cboucle != '='; iboucle++) //positionnement au début de int nblignes
			fichier.get(cboucle);
		fichier >> inbLigne;

		fichier.get(cboucle);
		for(iboucle = 0; cboucle != '='; iboucle++) //positionnement au début de int nbcolonnes
			fichier.get(cboucle);
		fichier >> inbColonne;

		CMatrix<double> MATres/* = CMatrix<double>*/(inbLigne, inbColonne);

		for(iboucle = 0; cboucle != '['; iboucle++) //positionnement au début des valeurs
			fichier.get(cboucle);
		fichier.get(cboucle);

		while(cboucle != ']')
		{
			for(ibouclei = 0; ibouclei < MATres.MATgetCountRows(); ibouclei++)
            {
                for(ibouclej = 0; ibouclej < MATres.MATgetCountColumns(); ibouclej++)
// TODO (kubuntu#1#): tester la bonne écriture des données ...
//
                    fichier >> MATres(ibouclei, ibouclej);
                fichier.get(cboucle);
                fichier.get(cboucle);
            }
		}

		fichier.close();  // on ferme le fichier
		return MATres;
	}
    else  // sinon
		cerr << "Impossible d'ouvrir le fichier !" << endl;
	throw new Cexception(FILE_OPENING_ERROR);
}
