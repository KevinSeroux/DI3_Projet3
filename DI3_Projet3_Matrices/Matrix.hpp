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
Permet de cr�er des Matrices et d'effectuer des
op�rations �l�mentaires dessus (transposition,
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
* Entr�e: nombre de lignes, nombre de colonnes
* Pr�-condition :
* Sortie :
* Post-condition : la matrice est cr��e avec le bon
nombre de lignes et de colonnes, lance une exception
si une des taille est � 0.
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
* Entr�e: matrice
* Pr�-condition :
* Sortie :
* Post-condition : instanciatoin d'une copie de la
matrice pass�e en param�tre
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
* Destructeur par d�faut
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie :
* Post-condition : D�truit la matrice correctement
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
* Entr�e: matrice
* Pr�-condition : les matrice doivent �tre additionables,
la surcharge de l'addition des objets de type T
est d�finie
* Sortie : matrice r�sultat
* Post-condition : renvoie la matrice correspondant
� cette addition. Lance une exception si l'addition
est impossible (matrices de taille diff�rentes).
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
* Entr�e: matrice
* Pr�-condition : on peut additionner les matrices,
la surcharge de l'addition des objets de type T
est d�finie
* Sortie :
* Post-condition : ajoute � la matrice actuelle la
matrice pass�e en param�tre.
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
* Entr�e: matrice
* Pr�-condition : on peut soustraire ces 2 matrices,
la surcharge de la soustraction des objets de type T
est d�finie
* Sortie : matrice r�sultat
* Post-condition : revoie le r�sutat de la matrice
actuelle moins la matrice pass�e en param�tre.
Lance une exception si la soustraction est impossible
(matrices de taille diff�rentes).
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
* Entr�e: matrice
* Pr�-condition : on peut soustraire les matrices,
la surcharge de la soustraction des objets de type T
est d�finie
* Sortie :
* Post-condition : soustrait � la matrice actuelle
la matrice pass�e en param�tre. Lance une exception
si la soustraction est impossible (matrices de
taille diff�rentes).
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
* Entr�e: matrice
* Pr�-condition : les matrices sont multipliable,
la surcharge de la multiplication et l'addition des
objets de type T est d�finie
* Sortie : matrice r�sultat
* Post-condition : renvoie le r�sultat de la
multiplication des deux matrices. Lance une exception
si elle ne sont pas multipliables.
* ************************************************/
template <class T>
CMatrix<T> CMatrix<T>::operator*(const CMatrix<T>& MATparam) const
{
    unsigned int uiloopRow, uiloopColumn, uiloopAdd, uinbAdd;

	if(uiCountColumns != MATparam.uiCountRows)  //Si la multiplication est impossible
        throw Cexception(SIZE_INVALID);

    CMatrix<T> MATres(MATgetCountRows(), MATparam.MATgetCountColumns());    //D�claration de la matrice de r�sultat
    for(uiloopRow = 0; uiloopRow < MATres.MATgetCountRows(); uiloopRow++)   //initialisation de la matrice de resultat
    {
        for(uiloopColumn = 0; uiloopColumn < MATres.MATgetCountColumns(); uiloopColumn++)
        {
            MATres(uiloopRow, uiloopColumn) = 0;
        }
    }

    uinbAdd = MATgetCountColumns();

    for(uiloopRow = 0; uiloopRow < MATres.MATgetCountRows(); uiloopRow++)   //Calcul du r�sultat
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
* Entr�e: objet constant de type T
* Pr�-condition : la surcharge de la multiplication
des objets de type T est d�finie, la matrice est
multipliable par l'objet en param�tre
* Sortie : matrice r�sultat
* Post-condition : renvoie le r�sultat de la
multiplication de la matrice actuelle par la matrice
pass�e en param�tre.
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
* Entr�e: objet constant de type T
* Pr�-condition : la surcharge de la multiplication
des objets de type T est d�finie, la matrice est
multipliable par l'objet en param�tre
* Sortie :
* Post-condition : on stocke dans la matrice actuelle
le r�sultat de la multiplication par l'objet pass�
en param�tre.
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
* Entr�e: objet constant de type T
* Pr�-condition : la matrice doit �tre divisible par
le param�tre, la surcharge de la division des objets
de type T doit �tre d�finie
* Sortie : matrice r�sultat
* Post-condition : retourne le r�sultat de la division
de la matrice par l'objet pass� en param�tre.
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
* Entr�e: Objet constant de type T
* Pr�-condition : la matrice doit �tre divisible par
l'objet en param�tre. La surcharge de la division des
objets de type T doit �tre d�finie.
* Sortie :
* Post-condition : Stocke dans la matrice actuelle
le r�sultat de la division de la matrice par l'objet
en param�tre.
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
* Renvoie la matrice transpos�e
* *************************************************
* Entr�e:
* Pr�-condition :
* Sortie : Matrice transpos�e
* Post-condition : renvoie une nouvelle matrice �gale
� la transpos�e de la matrice actuelle.
* ************************************************/
template <class T>
CMatrix<T> CMatrix<T>::MATtranspose()
{
	CMatrix<T> MATres(uiCountColumns, uiCountRows);

	BEGIN_FOREACH_CELL
	/*uiCurrentRow et Column sont des variables de boucles sur les �l�ments de la matrice courante
	donc nous devons inverser ces deux index pour la matrice r�sultat */
	MATres(uiCurrentColumn, uiCurrentRow) = (*this)(uiCurrentRow, uiCurrentColumn);
	END_FOREACH_CELL

	return MATres;
}

/**************************************************
* operator=
* *************************************************
* surcharge de l'op�rateur d'affectation
* *************************************************
* Entr�e: matrice
* Pr�-condition : la surcharge de l'op�rateur = doit
�tre d�finie pour les objets de type T
* Sortie :
* Post-condition : stocke dans la matrice courante
le contenu de la matrice pass�e en param�tre.
* ************************************************/
template <class T>
CMatrix<T>& CMatrix<T>::operator=(const CMatrix<T>& MATparam)
{
	//On autorise pas que 2 matrices de taille diff�rentes puissent �tre mise � �galit�
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
* Surcharge de l'op�rateur de test d'�galit�
* *************************************************
* Entr�e: matrice
* Pr�-condition : les matrices sont comparable
(m�me taille), la surcharge de l'op�rateur == doit
�tre d�fini pour les objets de type T
* Sortie : bool�en
* Post-condition : renvoie faux si les matrices sont
diff�rentes, vrai sinon, lance une exception si elles
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
* Surcharge de l'op�rateur !=
* *************************************************
* Entr�e: matrice
* Pr�-condition : la surcharge de l'op�rateur ==
doit �tre d�finie pour les objets de type T
* Sortie : bool�en
* Post-condition : renvoie vrai si les matrices
sont diff�rentes, faux sinon, lance une exception
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
* Entr�e: num�ro ligne, num�ro colonne
* Pr�-condition :
* Sortie : valeur de la case cherch� (par r�f�rence)
* Post-condition : renvoie une exception si
l'emplacement recherch� n'est pas dans le tableau
de donn�es, sinon renvoie la valeur de la case
choisie, par r�f�rence
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
* Entr�e: num�ro ligne, num�ro colonne
* Pr�-condition :
* Sortie : valeur de la case cherch�
* Post-condition : renvoie une exception si
l'emplacement recherch� n'est pas dans le tableau
de donn�es, sinon renvoie la valeur de la case
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
* Entr�e:
* Pr�-condition :
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
* Entr�e:
* Pr�-condition :
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
* Surcharge de l'op�rateur de multiplication entre
un objet de type T et une matrice
* *************************************************
* Entr�e: Objet de type T, matrice d'objets de type T
* Pr�-condition : la matrice pass�e en param�tre peut
�tre multipli�e par l'objet pass� en param�tre, la
surcharge de la multiplication est d�finie pour les
objets de type T
* Sortie : matrice r�sultat
* Post-condition : renvoie la matrice r�sultant de
cette op�ration
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
* Surcharge de l'op�rateur de flux de sortie (permet
d'afficher la matrice comme n'importe quel autre objet)
* *************************************************
* Entr�e: flux de sortie, matrice
* Pr�-condition : la surcharge de l'op�rateur de flux
de sortie doit �tre d�finie pour les objets de type T
* Sortie : flux de sortie
* Post-condition : la matrice est �crite dans le
flux de sortie en param�tre
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
