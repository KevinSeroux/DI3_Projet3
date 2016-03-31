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
* Constructeur par défaut
* *************************************************
* Entrée : 
* Pré-condition : 
* Sortie : 
* Post-condition : Instanciation de CUnitTest
* ************************************************/
	CUnitTest();

/**************************************************
* CUnitTest
* *************************************************
* Destructeur par défaut
* *************************************************
* Entrée : 
* Pré-condition : 
* Sortie : 
* Post-condition : Destruction de l'instanciation de CUnitTest
* ************************************************/
	~CUnitTest();

/**************************************************
* testMatrix
* *************************************************
* Fonction d'appel des tests unitaires des fonctions
* *************************************************
* Entrée : 
* Pré-condition : 
* Sortie : 
* Post-condition : Aucune assert déclenchée = librairie fonctionnelle
* ************************************************/
	void testMatrix();
};

#endif //UNITTEST_H
