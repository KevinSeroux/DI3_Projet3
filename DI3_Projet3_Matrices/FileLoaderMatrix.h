/**************************************************
Titre: Classe pour la gestion du chargement des fichier txt
***************************************************
Entete de la Classe CFileLoaderMatrix
Permet de charger un ficher txt et de retourner 
la matrice décrite par celui-ci
**************************************************/

/**************************************************
Utilisation : cette classe ne contient qu'une méthode 
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
* Constructeur par défaut, privé car classe non-instanciable
* *************************************************
* Entrée :
* Pré-condition :
* Sortie :
* Post-condition :
* ************************************************/
	CFileLoaderMatrix(void){};

/**************************************************
* ~CFileLoaderMatrix
* *************************************************
* Destructeur par défaut, privé car classe non-instanciable
* *************************************************
* Entrée:
* Pré-condition :
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
* Entrée: adresse d'un fichier txt (char const*)
* Pré-condition : Le fichier est VALIDE et contient des informations COHERENTES
* Sortie : matrice
* Post-condition : la matrice renvoyée est celle 
contenue dans le fichier texte
* ************************************************/
	static CMatrix<double> FLMload(char const* pcPath);
};

#endif //FILELOADERMAT2D_H
