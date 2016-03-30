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
#define NOT_SUPPORTED_DATA_TYPE 2
#define ZERO_SIZED_MATRIX 3
#define INVALID_MATRIX_SIZE_FOR_THIS_OPERATION 4
#define UNCOMPARABLE_MATRIX 5
#define INDEX_OUT_OF_BOUND 6
#define EXC_SIZE_INVALID 7
#define DIVIDE_BY_ZERO 8

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
	~Cexception() {}

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
inline void Cexception::EXCmodifier_valeur(unsigned int val)
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
inline unsigned int Cexception::EXClire_valeur()
{
	return uiEXCvaleur;
}

#endif