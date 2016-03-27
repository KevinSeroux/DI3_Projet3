/**************************************************
Titre: Classe pour la gestion des exceptions
***************************************************
Interface de la Classe Cexception
Permet de créer des objets remontés lors de
la levée d'exceptions.
**************************************************/

#ifndef CEXCEPTION_H
#define CEXCEPTION_H

#define FILE_OPENING_ERROR 1

class Cexception
{
	//Attribut
private:
	unsigned int uiEXCvaleur; //Contient la valeur de l'exception

	//Constructeur et destructeur
public:
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
	Cexception();

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
	Cexception(unsigned int);

/**************************************************
* ~CException
* *************************************************
* Destructeur de la classe
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : exception détruite
* ************************************************/
	~Cexception();

	//Methode
/**************************************************
* Excmodifier_valeur
* *************************************************
* Modifier valeur de l'exception
* *************************************************
* Entrée: nouvelle valeur
* Pré-condition :
* Sortie :
* Post-condition : valeur de l'exception modifiée
* ************************************************/
	void EXCmodifier_valeur(unsigned int);

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
	unsigned int EXClire_valeur();
};

#endif
