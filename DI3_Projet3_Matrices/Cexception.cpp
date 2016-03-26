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

/**************************************************
* Excmodifier_valeur
* *************************************************
* Modifier valeur de l'exception
* *************************************************
* Entr�e: nouvelle valeure
* Pr�-condition :
* Sortie :
* Post-condition : valeure de l'exception modifi�e
* ************************************************/
inline void Cexception::EXCmodifier_valeur(unsigned int val)
{
	uiEXCvaleur = val;
}

/**************************************************
* EXClire_valeur
* *************************************************
* Permet de lire la valeur de l'exception
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie : valeur de l'exception
* Post-condition : valeur de l'exception retourn�e
* ************************************************/
inline unsigned int Cexception::EXClire_valeur()
{
	return uiEXCvaleur;
}