#include "FileLoaderMatrix.h"
#include "Matrix.h"

CMatrix<double> CFileLoaderMatrix::FLMload(char* pcPath){
	int iboucle, ibouclei, ibouclej;
	char* cptype = new char[32];
	char* DOUBLE = "double";
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

		//M2Dres = CMat2D(inbLigne, inbColonne);

		for(iboucle = 0; cboucle != '['; iboucle++) //positionnement au début des valeurs
			fichier.get(cboucle);
		fichier.get(cboucle);

		ibouclei = 0;
		ibouclej = -1;
		while(cboucle != ']')
		{
			if(cboucle == '\n')
			{
				ibouclej++;
				ibouclei = 0;
				fichier.get(cboucle);
			}

			if(cboucle >='0' || cboucle <= '9' || cboucle == '.')
			{
				fichier >> iboucle;
				//M2Dres(ibouclei, ibouclej) = iboucle;
				while(cboucle != ' ' && cboucle != '\n')
					fichier.get(cboucle);
			}
		}


		CMatrix<double> M2Dres = CMatrix<double>(inbLigne,inbColonne);

		fichier.close();  // on ferme le fichier
		return M2Dres;
	}
    else  // sinon
		cerr << "Impossible d'ouvrir le fichier !" << endl;
	throw ;
}