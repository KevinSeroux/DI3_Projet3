#ifndef CEXCEPTION_H
#define CEXCEPTION_H

/**************************************************
Titre: Classe pour la gestion des exceptions
***************************************************
Interface de la Classe Cexception
Permet de créer des objets remontés lors de 
la levée d'exceptions.
**************************************************/

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
	Cexception(void);

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
	~Cexception(void);

	//Methode
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