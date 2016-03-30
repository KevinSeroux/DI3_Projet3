/**************************************************
Titre: Classe pour la gestion des exceptions
***************************************************
Corps de la Classe Cexception
Permet de créer des objets remontés lors de 
la levée d'exceptions.
**************************************************/

#include "Cexception.h"

/**************************************************
* CException
* *************************************************
* Constructeur par défaut
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : Exception initialisé à 0
* ************************************************/
Cexception::Cexception()
{
	uiEXCvaleur = 0;
}

/**************************************************
* CException
* *************************************************
* Constructeur
* *************************************************
* Entrée: Valeur associée à l'exception
* Pré-condition :
* Sortie :
* Post-condition : Exception initialisé à la valeur en entrée
* ************************************************/
Cexception::Cexception(unsigned int uiValue)
{
	uiEXCvaleur = uiValue;
}