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
Cexception::Cexception(void)
{
	uiEXCvaleur = 0;
}

/**************************************************
* Excmodifier_valeur
* *************************************************
* Modifier valeur de l'exception
* *************************************************
* Entrée: nouvelle valeure
* Pré-condition :
* Sortie :
* Post-condition : valeure de l'exception modifiée
* ************************************************/
void Cexception::EXCmodifier_valeur(unsigned int val)
{
	uiEXCvaleur = val;
}

/**************************************************
* EXClire_valeur
* *************************************************
* Permet de lire la valeur de l'exception
* *************************************************
* Entrée:
* Pré-condition :
* Sortie : valeur de l'exception
* Post-condition : valeur de l'exception retournée
* ************************************************/
unsigned int Cexception::EXClire_valeur()
{
	return uiEXCvaleur;
}