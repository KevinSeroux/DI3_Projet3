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
Titre: Classe pour la gestion des exceptions
***************************************************
Interface de la Classe Cexception
Permet de cr�er des objets remont�s lors de
la lev�e d'exceptions.
**************************************************/

#ifndef CEXCEPTION_H
#define CEXCEPTION_H

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
	~Cexception() {}

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

#endif