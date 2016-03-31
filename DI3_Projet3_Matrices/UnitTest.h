/**************************************************
Titre: Classe pour la gestion du chargement des fichier txt
***************************************************
Entete de la Classe CUnitTest
Permet de tester les fonctions et surcharges de CMatrix
**************************************************/

#ifndef UNITTEST_H
#define UNITTEST_H

#include "Matrix.h"

class CUnitTest
{
	//Constructeur
public:
/**************************************************
* CUnitTest
* *************************************************
* Constructeur par d�faut
* *************************************************
* Entr�e : 
* Pr�-condition : 
* Sortie : 
* Post-condition : Instanciation de CUnitTest
* ************************************************/
	CUnitTest();

/**************************************************
* CUnitTest
* *************************************************
* Destructeur par d�faut
* *************************************************
* Entr�e : 
* Pr�-condition : 
* Sortie : 
* Post-condition : Destruction de l'instanciation de CUnitTest
* ************************************************/
	~CUnitTest();

/**************************************************
* testMatrix
* *************************************************
* Fonction d'appel des tests unitaires des fonctions
* *************************************************
* Entr�e : 
* Pr�-condition : 
* Sortie : 
* Post-condition : Aucune assert d�clench�e = librairie fonctionnelle
* ************************************************/
	void testMatrix();
};

#endif //UNITTEST_H
