/**************************************************
Titre: Classe pour la gestion du chargement des fichier txt
***************************************************
Corps de la Classe CFileLoaderMatrix
Permet de charger un ficher txt et de retourner 
la matrice décrite par celui-ci
**************************************************/

#include "FileLoaderMatrix.h"

/**************************************************
* FLMload
* *************************************************
* Fonction static de chargement d'un fichier txt
* *************************************************
* Entrée: adresse d'un fichier txt (char const*)
* Pré-condition : Le fichier est VALIDE et contient 
des informations COHERENTES et de type double.
* Sortie : matrice
* Post-condition : la matrice renvoyée est celle 
contenue dans le fichier texte
* ************************************************/
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
				throw Cexception(NOT_SUPPORTED_DATA_TYPE);

		for(uiloop = 0; cloop != '='; uiloop++) //positionnement au début de int nblignes
			fichier.get(cloop);
		fichier >> inbLigne;

		fichier.get(cloop);
		for(uiloop = 0; cloop != '='; uiloop++) //positionnement au début de int nbcolonnes
			fichier.get(cloop);
		fichier >> inbColonne;

		CMatrix<double> MATres(inbLigne, inbColonne);	//Déclaration de la matrice renvoyée

		for(uiloop = 0; cloop != '['; uiloop++) //positionnement au début des valeurs
			fichier.get(cloop);
		fichier.get(cloop);

        for(uiloopRow = 0; uiloopRow < MATres.MATgetCountRows(); uiloopRow++)	//Parcours des lignes de la matrice
        {
            for(uiloopColumn = 0; uiloopColumn < MATres.MATgetCountColumns(); uiloopColumn++)	//Parcours des colonnes de la matrice
                fichier >> MATres(uiloopRow, uiloopColumn);	//Stockage du nombre extrait du fichier dans l'emplacement adéquat
        }

		fichier.close();  // on ferme le fichier

		delete cptype;
		return MATres;
	}
    else  // En cas de problème d'ouverture
		cerr << "Impossible d'ouvrir le fichier !" << endl;
	throw Cexception(FILE_OPENING_ERROR);
}
