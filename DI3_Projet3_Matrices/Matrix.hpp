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
Corps de la Classe CMatrix
Permet de créer des Matrices et d'effectuer des
opérations élémentaires dessus (transposition,
addition, soustraction, multiplication, division etc...)
**************************************************/

#include "Cexception.h"

#define BEGIN_FOREACH_CELL                                         \
	unsigned int uiCurrentRow = 0;                                 \
	for(; uiCurrentRow < uiCountRows; uiCurrentRow++)              \
	{                                                              \
		unsigned int uiCurrentColumn = 0;                          \
		for(; uiCurrentColumn < uiCountColumns; uiCurrentColumn++) \
		{
#define END_FOREACH_CELL                                           \
	    }                                                          \
	}                                                              \

using namespace std;

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
template <class T>
CMatrix<T>::CMatrix(unsigned int uiCountRows, unsigned int uiCountColumns)
{
    if(uiCountColumns == 0 || uiCountRows == 0)
        throw Cexception(ZERO_SIZED_MATRIX);

	this->uiCountRows = uiCountRows;
	this->uiCountColumns = uiCountColumns;

	ppptMatData = new T**[uiCountRows];
	unsigned int uiCurrentRow = 0;
	for(; uiCurrentRow < uiCountRows; uiCurrentRow++)
	{
		ppptMatData[uiCurrentRow] = new T*[uiCountColumns];

		unsigned int uiCurrentColumn = 0;
		for(; uiCurrentColumn < uiCountColumns; uiCurrentColumn++)
			ppptMatData[uiCurrentRow][uiCurrentColumn] = new T;
	}
}

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
template <class T>
CMatrix<T>::CMatrix(const CMatrix<T>& MATparam)
{
	uiCountRows = MATparam.uiCountRows;
	uiCountColumns = MATparam.uiCountColumns;

	ppptMatData = new T**[uiCountRows];

	unsigned int uiCurrentRow = 0;
	for(; uiCurrentRow < uiCountRows; uiCurrentRow++)
	{
		ppptMatData[uiCurrentRow] = new T*[uiCountColumns];
		unsigned int uiCurrentColumn = 0;
		for(; uiCurrentColumn < uiCountColumns; uiCurrentColumn++)
		{
			ppptMatData[uiCurrentRow][uiCurrentColumn] = new T;
			(*this)(uiCurrentRow, uiCurrentColumn) = MATparam(uiCurrentRow, uiCurrentColumn);
		}
	}
}

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
template <class T>
CMatrix<T>::~CMatrix()
{
	unsigned int uiCurrentRow = 0;
	for(; uiCurrentRow < uiCountRows; uiCurrentRow++)
	{
		unsigned int uiCurrentColumn = 0;
		for(; uiCurrentColumn < uiCountColumns; uiCurrentColumn++)
			delete ppptMatData[uiCurrentRow][uiCurrentColumn];

		delete[] ppptMatData[uiCurrentRow];
	}

	delete[] ppptMatData;
}

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
template <class T>
CMatrix<T> CMatrix<T>::operator+(const CMatrix<T>& MATparam) const
{
	if(uiCountRows != MATparam.uiCountRows || uiCountColumns != MATparam.uiCountRows)
	   throw Cexception(SIZE_INVALID);

	CMatrix<T> MATreturn(uiCountRows, uiCountColumns);

	BEGIN_FOREACH_CELL
	MATreturn(uiCurrentRow, uiCurrentColumn) =
	(*this)(uiCurrentRow, uiCurrentColumn) + MATparam(uiCurrentRow, uiCurrentColumn);
	END_FOREACH_CELL

	return MATreturn;
}

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
template <class T>
CMatrix<T>& CMatrix<T>::operator+=(const CMatrix<T>& MATparam)
{
	if(uiCountRows != MATparam.uiCountRows || uiCountColumns != MATparam.uiCountRows)
	   throw Cexception(SIZE_INVALID);

	BEGIN_FOREACH_CELL
	(*this)(uiCurrentRow, uiCurrentColumn) =
	(*this)(uiCurrentRow, uiCurrentColumn) + MATparam(uiCurrentRow, uiCurrentColumn);
	END_FOREACH_CELL

	return *this;
}

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
template <class T>
CMatrix<T> CMatrix<T>::operator-(const CMatrix<T>& MATparam) const
{
	if(uiCountRows != MATparam.uiCountRows || uiCountColumns != MATparam.uiCountRows)
	   throw Cexception(SIZE_INVALID);

	CMatrix<T> MAT2return(uiCountRows, uiCountColumns);

	BEGIN_FOREACH_CELL
	MAT2return(uiCurrentRow, uiCurrentColumn) =
	(*this)(	uiCurrentRow, uiCurrentColumn) - MATparam(uiCurrentRow, uiCurrentColumn);
	END_FOREACH_CELL

	return MAT2return;
}

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
template <class T>
CMatrix<T>& CMatrix<T>::operator-=(const CMatrix<T>& MATparam)
{
	if(uiCountRows != MATparam.uiCountRows || uiCountColumns != MATparam.uiCountRows)
	   throw Cexception(SIZE_INVALID);

	BEGIN_FOREACH_CELL
	(*this)(uiCurrentRow, uiCurrentColumn) -= MATparam(uiCurrentRow, uiCurrentColumn);
	END_FOREACH_CELL

	return *this;
}

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
template <class T>
CMatrix<T> CMatrix<T>::operator*(const CMatrix<T>& MATparam) const
{
    unsigned int uiloopRow, uiloopColumn, uiloopAdd, uinbAdd;

	if(uiCountColumns != MATparam.uiCountRows)  //Si la multiplication est impossible
        throw Cexception(SIZE_INVALID);

    CMatrix<T> MATres(MATgetCountRows(), MATparam.MATgetCountColumns());    //Déclaration de la matrice de résultat
    for(uiloopRow = 0; uiloopRow < MATres.MATgetCountRows(); uiloopRow++)   //initialisation de la matrice de resultat
    {
        for(uiloopColumn = 0; uiloopColumn < MATres.MATgetCountColumns(); uiloopColumn++)
        {
            MATres(uiloopRow, uiloopColumn) = 0;
        }
    }

    uinbAdd = MATgetCountColumns();

    for(uiloopRow = 0; uiloopRow < MATres.MATgetCountRows(); uiloopRow++)   //Calcul du résultat
    {
        for(uiloopColumn = 0; uiloopColumn < MATres.MATgetCountColumns(); uiloopColumn++)
        {
            for(uiloopAdd = 0; uiloopAdd < uinbAdd; uiloopAdd++)
            {
                MATres(uiloopRow, uiloopColumn) = MATres(uiloopRow, uiloopColumn)
                + this->operator()(uiloopRow, uiloopAdd) * MATparam(uiloopAdd, uiloopColumn);
            }
        }
    }

	return MATres;
}

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
template <class T>
CMatrix<T> CMatrix<T>::operator*(const T value) const
{
	CMatrix<T> MATres(uiCountRows, uiCountColumns);

	BEGIN_FOREACH_CELL
    MATres(uiCurrentRow, uiCurrentColumn) = (*this)(uiCurrentRow, uiCurrentColumn) * value;
	END_FOREACH_CELL

	return MATres;
}

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
template <class T>
CMatrix<T>& CMatrix<T>::operator*=(const T value)
{
	BEGIN_FOREACH_CELL
	(*this)(uiCurrentRow, uiCurrentColumn) = (*this)(uiCurrentRow, uiCurrentColumn) * value;
	END_FOREACH_CELL

	return *this;
}

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
template <class T>
CMatrix<T> CMatrix<T>::operator/(const T tValue) const
{
	if(tValue == 0)
	   throw Cexception(DIVIDE_BY_ZERO);

	CMatrix<T> MAT2return(uiCountRows, uiCountColumns);

	BEGIN_FOREACH_CELL
	MAT2return(uiCurrentRow, uiCurrentColumn) = (*this)(uiCurrentRow, uiCurrentColumn) / tValue;
	END_FOREACH_CELL

	return MAT2return;
}

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
template <class T>
CMatrix<T>& CMatrix<T>::operator/=(const T tValue)
{
	if(tValue == 0)
	   throw Cexception(DIVIDE_BY_ZERO);

	BEGIN_FOREACH_CELL
	(*this)(uiCurrentRow, uiCurrentColumn) /= tValue;
	END_FOREACH_CELL

	return *this;
}

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
template <class T>
CMatrix<T> CMatrix<T>::MATtranspose()
{
	CMatrix<T> MATres(uiCountColumns, uiCountRows);

	BEGIN_FOREACH_CELL
	/*uiCurrentRow et Column sont des variables de boucles sur les éléments de la matrice courante
	donc nous devons inverser ces deux index pour la matrice résultat */
	MATres(uiCurrentColumn, uiCurrentRow) = (*this)(uiCurrentRow, uiCurrentColumn);
	END_FOREACH_CELL

	return MATres;
}

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
template <class T>
CMatrix<T>& CMatrix<T>::operator=(const CMatrix<T>& MATparam)
{
	//On autorise pas que 2 matrices de taille différentes puissent être mise à égalité
	if(uiCountRows != MATparam.uiCountRows || uiCountColumns != MATparam.uiCountRows)
	   throw Cexception(SIZE_INVALID);

	BEGIN_FOREACH_CELL
	(*this)(uiCurrentRow, uiCurrentColumn) = MATparam(uiCurrentRow, uiCurrentColumn);
	END_FOREACH_CELL

	return *this;
}

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
template <class T>
bool CMatrix<T>::operator==(const CMatrix<T>& MATparam)
{
	// Test si les matrices sont comparable
	if(uiCountRows != MATparam.uiCountRows || uiCountColumns != MATparam.uiCountRows)
	   throw Cexception(SIZE_INVALID);

	BEGIN_FOREACH_CELL
	if(this->operator()(uiCurrentRow, uiCurrentColumn) != MATparam(uiCurrentRow, uiCurrentColumn))
		return false;
	END_FOREACH_CELL

	return true;
}

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
template <class T>
inline bool CMatrix<T>::operator!=(const CMatrix<T>& MATparam)
{
	return !operator==(MATparam);
}

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
template <class T>
inline T& CMatrix<T>::operator()(unsigned int uiRow, unsigned int uiColumn)
{
	if(uiRow >= this->MATgetCountRows() || uiColumn >= this->MATgetCountColumns())  //Si l'index n'est pas valide
        throw Cexception(INDEX_OUT_OF_BOUND);

	return *ppptMatData[uiRow][uiColumn];
}

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
template <class T>
inline T CMatrix<T>::operator()(unsigned int uiRow, unsigned int uiColumn) const
{
	if(uiRow >= this->MATgetCountRows() || uiColumn >= this->MATgetCountColumns()) //Si index non valide
        throw Cexception(INDEX_OUT_OF_BOUND);

	return *ppptMatData[uiRow][uiColumn];
}

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
template <class T>
inline unsigned int const CMatrix<T>::MATgetCountRows() const
{
	return uiCountRows;
}

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
template <class T>
inline unsigned int const CMatrix<T>::MATgetCountColumns() const
{
	return uiCountColumns;
}

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
template <class T>
CMatrix<T> operator*(const T value, const CMatrix<T>& MATparam)
{
	CMatrix<T> MATres(MATparam.uiCountRows, MATparam.uiCountColumns);

	//Pour la boucle FOREACH
	unsigned int uiCountRows = MATparam.uiCountRows;
	unsigned int uiCountColumns = MATparam.uiCountColumns;

	BEGIN_FOREACH_CELL
	MATres(uiCurrentRow, uiCurrentColumn) = MATparam(uiCurrentRow, uiCurrentColumn) * value;
	END_FOREACH_CELL

	return MATres;
}

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
template <class T>
std::ostream& operator<<(std::ostream& out, const CMatrix<T>& MAT)
{
	unsigned int uiloopRow, uiloopColumn;
    out << '[' << std::endl;

    for(uiloopRow = 0; uiloopRow < MAT.uiCountRows; uiloopRow++)
    {
        for(uiloopColumn = 0; uiloopColumn < MAT.uiCountColumns; uiloopColumn++)
            out << MAT(uiloopRow, uiloopColumn) << ' ';

        out << std::endl;
	}

	out << ']' << std::endl;

	return out;
}
