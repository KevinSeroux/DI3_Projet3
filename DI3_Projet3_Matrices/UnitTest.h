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
