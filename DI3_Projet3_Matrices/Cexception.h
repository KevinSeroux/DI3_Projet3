#ifndef CEXCEPTION_H
#define CEXCEPTION_H

/**************************************************
Titre: Classe pour la gestion des exceptions
***************************************************
Interface de la Classe Cexception
Permet de cr�er des objets remont�s lors de 
la lev�e d'exceptions.
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
* Constructeur par d�faut
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : Exception initialis� � 0
* ************************************************/
	Cexception(void);

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
	~Cexception(void);

	//Methode
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