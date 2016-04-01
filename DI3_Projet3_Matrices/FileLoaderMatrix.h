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
Entete de la Classe CFileLoaderMatrix
Permet de charger un ficher txt et de retourner 
la matrice d�crite par celui-ci
**************************************************/

/**************************************************
Utilisation : cette classe ne contient qu'une m�thode 
appelable comme cela: 
"CFileLoaderMatrix::FMLload(char const * param);"
**************************************************/

#ifndef FILELOADERMATRIX_H
#define FILELOADERMATRIX_H

#include <iostream>
#include <fstream>
#include "Matrix.h"

using namespace std;

class CFileLoaderMatrix
{
	//Constructeur
private:
/**************************************************
* CFileLoaderMatrix
* *************************************************
* Constructeur par d�faut, priv� car classe non-instanciable
* *************************************************
* Entr�e :
* Pr�-condition :
* Sortie :
* Post-condition :
* ************************************************/
	CFileLoaderMatrix(void){};

/**************************************************
* ~CFileLoaderMatrix
* *************************************************
* Destructeur par d�faut, priv� car classe non-instanciable
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition :
* ************************************************/
	~CFileLoaderMatrix(void){};

	//Methode
public:
/**************************************************
* FLMload
* *************************************************
* Fonction static de chargement d'un fichier txt
* *************************************************
* Entr�e: adresse d'un fichier txt (char const*)
* Pr�-condition : Le fichier est VALIDE et contient des informations COHERENTES
* Sortie : matrice
* Post-condition : la matrice renvoy�e est celle 
contenue dans le fichier texte
* ************************************************/
	static CMatrix<double> FLMload(char const* pcPath);
};

#endif //FILELOADERMAT2D_H
