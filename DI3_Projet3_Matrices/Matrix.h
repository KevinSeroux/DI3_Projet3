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
Titre: Classe pour la gestion de Matrices de type
quelconque
***************************************************
Entete de la Classe CMatrix
Permet de créer des Matrices et d'effectuer des
opérations élémentaires dessus (transposition,
addition, soustraction, multiplication, division etc...)
**************************************************/

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

template <class T>
class CMatrix
{
    //Attributs
private:
	unsigned int uiCountRows, uiCountColumns;   //Contient respectivement le nombre de lignes et de colonnes
	T*** ppptMatData;   //Contient les données

    //Constructeurs et Destructeurs
public:
/**************************************************
* CMatrix
* *************************************************
* Constructeur
* *************************************************
* Entrée: nombre de lignes, nombre de colonnes
* Pré-condition :
* Sortie :
* Post-condition : la matrice est créée avec le bon
nombre de lignes et de colonnes, lance une exception
si une des taille est à 0.
* ************************************************/
	CMatrix(unsigned int uiCountRows, unsigned int uiCountColumns);

/**************************************************
* CMatrix
* *************************************************
* Constructeur de recopie
* *************************************************
* Entrée: matrice
* Pré-condition :
* Sortie :
* Post-condition : instanciatoin d'une copie de la
matrice passée en paramètre
* ************************************************/
	CMatrix(const CMatrix<T>&);

/**************************************************
* ~CMatrix
* *************************************************
* Destructeur par défaut
* *************************************************
* Entrée:
* Pré-condition :
* Sortie :
* Post-condition : Détruit la matrice correctement
* ************************************************/
	~CMatrix();

    //Surcharges
public:
/**************************************************
* operator+
* *************************************************
* Surcharge de l'addition
* *************************************************
* Entrée: matrice
* Pré-condition : les matrice doivent être additionables,
la surcharge de l'addition des objets de type T
est définie
* Sortie : matrice résultat
* Post-condition : renvoie la matrice correspondant
à cette addition. Lance une exception si l'addition
est impossible (matrices de taille différentes).
* ************************************************/
	CMatrix<T> operator+(const CMatrix<T>&) const;

/**************************************************
* operator+=
* *************************************************
* Surchage de l'association additive
* *************************************************
* Entrée: matrice
* Pré-condition : on peut additionner les matrices,
la surcharge de l'addition des objets de type T
est définie
* Sortie :
* Post-condition : ajoute à la matrice actuelle la
matrice passée en paramètre.
* ************************************************/
	CMatrix<T>& operator+=(const CMatrix<T>&);

/**************************************************
* operator-
* *************************************************
* Surcharge de la soustraction
* *************************************************
* Entrée: matrice
* Pré-condition : on peut soustraire ces 2 matrices,
la surcharge de la soustraction des objets de type T
est définie
* Sortie : matrice résultat
* Post-condition : revoie le résutat de la matrice
actuelle moins la matrice passée en paramètre.
Lance une exception si la soustraction est impossible
(matrices de taille différentes).
* ************************************************/
	CMatrix<T> operator-(const CMatrix<T>&) const;

/**************************************************
* operator-=
* *************************************************
* Surcharge de l'association soustractive
* *************************************************
* Entrée: matrice
* Pré-condition : on peut soustraire les matrices,
la surcharge de la soustraction des objets de type T
est définie
* Sortie :
* Post-condition : soustrait à la matrice actuelle
la matrice passée en paramètre. Lance une exception
si la soustraction est impossible (matrices de
taille différentes).
* ************************************************/
	CMatrix<T>& operator-=(const CMatrix<T>&);

/**************************************************
* operator*
* *************************************************
* Surcharge de la multiplication par une matrice
* *************************************************
* Entrée: matrice
* Pré-condition : les matrices sont multipliable,
la surcharge de la multiplication et l'addition des
objets de type T est définie
* Sortie : matrice résultat
* Post-condition : renvoie le résultat de la
multiplication des deux matrices. Lance une exception
si elle ne sont pas multipliables.
* ************************************************/
	CMatrix<T> operator*(const CMatrix<T>&) const;

/**************************************************
* operator*
* *************************************************
* Surcharge de la multiplication par un objet de type T
* *************************************************
* Entrée: objet constant de type T
* Pré-condition : la surcharge de la multiplication
des objets de type T est définie, la matrice est
multipliable par l'objet en paramètre
* Sortie : matrice résultat
* Post-condition : renvoie le résultat de la
multiplication de la matrice actuelle par la matrice
passée en paramètre.
* ************************************************/
	CMatrix<T> operator*(const T) const;

/**************************************************
* operator*=
* *************************************************
* Surcharge de l'association multiplicative
* *************************************************
* Entrée: objet constant de type T
* Pré-condition : la surcharge de la multiplication
des objets de type T est définie, la matrice est
multipliable par l'objet en paramètre
* Sortie :
* Post-condition : on stocke dans la matrice actuelle
le résultat de la multiplication par l'objet passé
en paramètre.
* ************************************************/
	CMatrix<T>& operator*=(const T);

/**************************************************
* operator/
* *************************************************
* Surcharge de la division par un objet de type T
* *************************************************
* Entrée: objet constant de type T
* Pré-condition : la matrice doit être divisible par
le paramètre, la surcharge de la division des objets
de type T doit être définie
* Sortie : matrice résultat
* Post-condition : retourne le résultat de la division
de la matrice par l'objet passé en paramètre.
* ************************************************/
	CMatrix<T> operator/(const T) const;

/**************************************************
* operator/=
* *************************************************
* Surcharge de l'association avec division par un
objet de type T
* *************************************************
* Entrée: Objet constant de type T
* Pré-condition : la matrice doit être divisible par
l'objet en paramètre. La surcharge de la division des
objets de type T doit être définie.
* Sortie :
* Post-condition : Stocke dans la matrice actuelle
le résultat de la division de la matrice par l'objet
en paramètre.
* ************************************************/
	CMatrix<T>& operator/=(const T);

/**************************************************
* MATtranspose
* *************************************************
* Renvoie la matrice transposée
* *************************************************
* Entrée:
* Pré-condition :
* Sortie : Matrice transposée
* Post-condition : renvoie une nouvelle matrice égale
à la transposée de la matrice actuelle.
* ************************************************/
	CMatrix<T> MATtranspose();

/**************************************************
* operator=
* *************************************************
* surcharge de l'opérateur d'affectation
* *************************************************
* Entrée: matrice
* Pré-condition : la surcharge de l'opérateur = doit
être définie pour les objets de type T
* Sortie :
* Post-condition : stocke dans la matrice courante
le contenu de la matrice passée en paramètre.
* ************************************************/
	CMatrix<T>& operator=(const CMatrix<T>&);

/**************************************************
* operator==
* *************************************************
* Surcharge de l'opérateur de test d'égalité
* *************************************************
* Entrée: matrice
* Pré-condition : les matrices sont comparable
(même taille), la surcharge de l'opérateur == doit
être défini pour les objets de type T
* Sortie : booléen
* Post-condition : renvoie faux si les matrices sont
différentes, vrai sinon, lance une exception si elles
ne sont pas comparables.
* ************************************************/
	bool operator==(const CMatrix<T>&);

/**************************************************
* operator!=
* *************************************************
* Surcharge de l'opérateur !=
* *************************************************
* Entrée: matrice
* Pré-condition : la surcharge de l'opérateur ==
doit être définie pour les objets de type T
* Sortie : booléen
* Post-condition : renvoie vrai si les matrices
sont différentes, faux sinon, lance une exception
si elles ne sont pas comparables
* ************************************************/
	bool operator!=(const CMatrix<T>&);

/**************************************************
* operator()
* *************************************************
* Permet de stocker des valeurs
* *************************************************
* Entrée: numéro ligne, numéro colonne
* Pré-condition :
* Sortie : valeur de la case cherché (par référence)
* Post-condition : renvoie une exception si
l'emplacement recherché n'est pas dans le tableau
de données, sinon renvoie la valeur de la case
choisie, par référence
* ************************************************/
	T& operator()(unsigned int uiRow, unsigned int uiColumn); //Version to set

/**************************************************
* operator()
* *************************************************
* Permet d'obtenir une valeure
* *************************************************
* Entrée: numéro ligne, numéro colonne
* Pré-condition :
* Sortie : valeur de la case cherché
* Post-condition : renvoie une exception si
l'emplacement recherché n'est pas dans le tableau
de données, sinon renvoie la valeur de la case
choisie
* ************************************************/
	T operator()(unsigned int uiRow, unsigned int uiColumn) const; //Version to get

    //Methodes

/**************************************************
* MATgetCountRows
* *************************************************
* Accesseur au nombre de lignes
* *************************************************
* Entrée:
* Pré-condition :
* Sortie : nombre de lignes
* Post-condition : renvoie le nombre de lignes
* ************************************************/
	unsigned int const MATgetCountRows() const;

/**************************************************
* MATgetCountColumns
* *************************************************
* Accesseur au nombre de colonnes
* *************************************************
* Entrée:
* Pré-condition :
* Sortie : nombre de colonnes
* Post-condition : renvoie le nombre de colonnes
* ************************************************/
	unsigned int const MATgetCountColumns() const;

	//Free functions
/**************************************************
* operator*
* *************************************************
* Surcharge de l'opérateur de multiplication entre
un objet de type T et une matrice
* *************************************************
* Entrée: Objet de type T, matrice d'objets de type T
* Pré-condition : la matrice passée en paramètre peut
être multipliée par l'objet passé en paramètre, la
surcharge de la multiplication est définie pour les
objets de type T
* Sortie : matrice résultat
* Post-condition : renvoie la matrice résultant de
cette opération
* ************************************************/
	template <class T> friend CMatrix<T> operator*(const T, const CMatrix<T>&);

/**************************************************
* operator<<
* *************************************************
* Surcharge de l'opérateur de flux de sortie (permet
d'afficher la matrice comme n'importe quel autre objet)
* *************************************************
* Entrée: flux de sortie, matrice
* Pré-condition : la surcharge de l'opérateur de flux
de sortie doit être définie pour les objets de type T
* Sortie : flux de sortie
* Post-condition : la matrice est écrite dans le
flux de sortie en paramètre
* ************************************************/
	template <class T> friend std::ostream& operator<<(std::ostream& out, const CMatrix<T>&);
};

#include "Matrix.hpp"

#endif //MATRIX_H
