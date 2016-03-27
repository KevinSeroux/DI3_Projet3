/**************************************************
Titre: Classe pour la gestion des exceptions
***************************************************
Interface de la Classe Cexception
Permet de cr�er des objets remont�s lors de
la lev�e d'exceptions.
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
* Constructeur par d�faut
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : Exception initialis� � 0
* ************************************************/
	Cexception();

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
	Cexception(unsigned int);

/**************************************************
* ~CException
* *************************************************
* Destructeur de la classe
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : exception d�truite
* ************************************************/
	~Cexception();

	//Methode
/**************************************************
* Excmodifier_valeur
* *************************************************
* Modifier valeur de l'exception
* *************************************************
* Entr�e: nouvelle valeur
* Pr�-condition :
* Sortie :
* Post-condition : valeur de l'exception modifi�e
* ************************************************/
	void EXCmodifier_valeur(unsigned int);

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
	unsigned int EXClire_valeur();
};

#endif
