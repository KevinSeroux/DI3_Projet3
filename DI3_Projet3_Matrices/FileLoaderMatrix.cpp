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

/**************************************************
Titre: Classe pour la gestion du chargement des fichier txt
***************************************************
Corps de la Classe CFileLoaderMatrix
Permet de charger un ficher txt et de retourner 
la matrice d�crite par celui-ci
**************************************************/

#include <cassert>
#include "FileLoaderMatrix.h"

/**************************************************
* FLMload
* *************************************************
* Fonction static de chargement d'un fichier txt
* *************************************************
* Entr�e: adresse d'un fichier txt (char const*)
* Pr�-condition : Le fichier est VALIDE et contient 
des informations COHERENTES et de type double.
* Sortie : matrice
* Post-condition : la matrice renvoy�e est celle 
contenue dans le fichier texte
* ************************************************/
CMatrix<double> CFileLoaderMatrix::FLMload(char const* const pcPath){
	assert(pcPath != 0); //Assertion car c'est une erreur de dev et pas de runtime
	
	char const DOUBLE[] = "double";
	size_t const cptypeLength = 7;
	char cptype[cptypeLength];
	unsigned int uiloop, uiloopRow, uiloopColumn;
	char cloop;
	int inbLigne;
	int inbColonne;

	ifstream fichier(pcPath, ios::in);  // on ouvre le fichier en lecture

	if(fichier)  // si l'ouverture a r�ussi
	{
		fichier.seekg(12); //positionnement au d�but du type

		fichier.get(cptype, cptypeLength); //stockage du type

		if(strcmp(cptype, DOUBLE) != 0) //V�rification type = double
			throw Cexception(NOT_SUPPORTED_DATA_TYPE);

		fichier.get(cloop);
		for(uiloop = 0; cloop != '='; uiloop++) //positionnement au d�but de int nblignes
			fichier.get(cloop);
		fichier >> inbLigne;

		fichier.get(cloop);
		for(uiloop = 0; cloop != '='; uiloop++) //positionnement au d�but de int nbcolonnes
			fichier.get(cloop);
		fichier >> inbColonne;

		CMatrix<double> MATres(inbLigne, inbColonne);//D�claration de la matrice renvoy�e

		for(uiloop = 0; cloop != '['; uiloop++) //positionnement au d�but des valeurs
			fichier.get(cloop);
		fichier.get(cloop);

        for(uiloopRow = 0; uiloopRow < MATres.MATgetCountRows(); uiloopRow++) //Parcours des lignes de la matrice
        {
            for(uiloopColumn = 0; uiloopColumn < MATres.MATgetCountColumns(); uiloopColumn++) //Parcours des colonnes de la matrice
                fichier >> MATres(uiloopRow, uiloopColumn);	//Stockage du nombre extrait du fichier dans l'emplacement ad�quat
        }

		fichier.close();  // on ferme le fichier

		return MATres;
	}
    else  // En cas de probl�me d'ouverture
		cerr << "Impossible d'ouvrir le fichier " << pcPath << " !" << endl;
	throw Cexception(FILE_OPENING_ERROR);
}
