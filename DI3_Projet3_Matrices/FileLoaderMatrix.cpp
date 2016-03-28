#include "FileLoaderMatrix.h"

CMatrix<double> CFileLoaderMatrix::FLMload(char const * pcPath){
	unsigned int uiloop, uiloopRow, uiloopColumn;
	char* cptype = new char[32];
	char const * DOUBLE = "double";
	char cloop;
	int inbLigne;
	int inbColonne;

	ifstream fichier("mat1.txt", ios::in);  // on ouvre le fichier en lecture

	if(fichier)  // si l'ouverture a réussi
	{
		for(uiloop = 0; uiloop <= 11; uiloop++) //positionnement au début du type
			fichier.get(cloop);

		uiloop = 0;
		while(cloop != '\n') //stockage du type
		{
			uiloop++;
			fichier.get(cloop);
			*(cptype + uiloop - 1) = cloop;
		}
		*(cptype + uiloop - 1) = 0;

		for(uiloop = 0; *(cptype + uiloop) != 0; uiloop++)	//Vérification type = double
			if(*(cptype + uiloop) != *(DOUBLE + uiloop))
				printf("Type incorrect");//throw ;

		for(uiloop = 0; cloop != '='; uiloop++) //positionnement au début de int nblignes
			fichier.get(cloop);
		fichier >> inbLigne;

		fichier.get(cloop);
		for(uiloop = 0; cloop != '='; uiloop++) //positionnement au début de int nbcolonnes
			fichier.get(cloop);
		fichier >> inbColonne;

		CMatrix<double> MATres/* = CMatrix<double>*/(inbLigne, inbColonne);

		for(uiloop = 0; cloop != '['; uiloop++) //positionnement au début des valeurs
			fichier.get(cloop);
		fichier.get(cloop);

        for(uiloopRow = 0; uiloopRow < MATres.MATgetCountRows(); uiloopRow++)
        {
            for(uiloopColumn = 0; uiloopColumn < MATres.MATgetCountColumns(); uiloopColumn++)
            {
                fichier >> MATres(uiloopRow, uiloopColumn);
                cout << MATres(uiloopRow, uiloopColumn);
            }
            //fichier.get(cloop);
        }

		fichier.close();  // on ferme le fichier
		return MATres;
	}
    else  // sinon
		cerr << "Impossible d'ouvrir le fichier !" << endl;
	throw new Cexception(FILE_OPENING_ERROR);
}
