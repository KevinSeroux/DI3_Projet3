/**************************************************
Titre: Classe pour la gestion des exceptions
***************************************************
Corps de la Classe Cexception
Permet de cr�er des objets remont�s lors de 
la lev�e d'exceptions.
**************************************************/

#include "Cexception.h"

/**************************************************
* CException
* *************************************************
* Constructeur par d�faut
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : Exception initialis� � 0
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
* Entr�e: Valeur associ�e � l'exception
* Pr�-condition :
* Sortie :
* Post-condition : Exception initialis� � la valeur en entr�e
* ************************************************/
Cexception::Cexception(unsigned int uiValue)
{
	uiEXCvaleur = uiValue;
}