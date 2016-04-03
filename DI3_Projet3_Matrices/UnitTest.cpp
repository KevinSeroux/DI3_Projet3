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
Titre: Classe pour la gestion du chargement des fichier txt
***************************************************
Corps de la Classe CUnitTest
Permet de tester les fonctions et surcharges de CMatrix
**************************************************/

#include "UnitTest.h"
#include "Cexception.h"

/**************************************************
* CUnitTest
* *************************************************
* Constructeur par défaut
* *************************************************
* Entrée :
* Pré-condition :
* Sortie :
* Post-condition : Instanciation de CUnitTest
* ************************************************/
CUnitTest::CUnitTest()
{
}

/**************************************************
* CUnitTest
* *************************************************
* Destructeur par défaut
* *************************************************
* Entrée :
* Pré-condition :
* Sortie :
* Post-condition : Destruction de l'instanciation de CUnitTest
* ************************************************/
CUnitTest::~CUnitTest()
{
}

/**************************************************
* testMatrixConstructor
* *************************************************
* Test des constructeurs
* *************************************************
* Entrée :
* Pré-condition :
* Sortie :
* Post-condition : aucun assert déclenché = Constructeurs
fonctionnel
* ************************************************/
static void testMatrixConstructor()
{
	CMatrix<int> MAT(3, 4);
	assert(MAT.MATgetCountRows() == 3);
	assert(MAT.MATgetCountColumns() == 4);
}

/**************************************************
* testMatrixConstructorByCopy
* *************************************************
* Test de constructeur de recopie
* *************************************************
* Entrée :
* Pré-condition :
* Sortie :
* Post-condition : aucun assert déclenché = fonctionnel
* ************************************************/
static void testMatrixConstructorByCopy()
{
	CMatrix<int> MAT(3, 2);
	MAT(0, 0) = 11;
	MAT(0, 1) = 12;
	MAT(1, 0) = 21;
	MAT(1, 1) = 22;
	MAT(2, 0) = 31;
	MAT(2, 1) = 32;

	CMatrix<int> MATCopy(MAT);

	MAT(1, 0) = 42;//To test if there is a copy of value and not a copy of address

	assert(MATCopy.MATgetCountRows() == 3);
	assert(MATCopy.MATgetCountColumns() == 2);
	assert(MATCopy(0, 0) == 11);
	assert(MATCopy(0, 1) == 12);
	assert(MATCopy(1, 0) == 21);
	assert(MATCopy(1, 1) == 22);
	assert(MATCopy(2, 0) == 31);
	assert(MATCopy(2, 1) == 32);
}

/**************************************************
* testMatrixOperatorAdd
* *************************************************
* Test de l'opérateur +
* *************************************************
* Entrée :
* Pré-condition :
* Sortie :
* Post-condition : aucun assert déclenché = addition
fonctionnelle
* ************************************************/
static void testMatrixOperatorAdd()
{
	CMatrix<int> MAT1(2, 2);
	MAT1(0, 0) = 111;
	MAT1(0, 1) = 112;
	MAT1(1, 0) = 121;
	MAT1(1, 1) = 122;

	CMatrix<int> MAT2(2, 2);
	MAT2(0, 0) = 211;
	MAT2(0, 1) = 212;
	MAT2(1, 0) = 221;
	MAT2(1, 1) = 222;

	CMatrix<int> MAT3(3, 2);
	try
	{
	    MAT2 = MAT2 + MAT3;
	    assert(false);
	}
	catch(Cexception&){}

	CMatrix<int> MAT(2, 2);
	MAT = MAT1 + MAT2;

	assert(MAT(0, 0) == 322);
	assert(MAT(0, 1) == 324);
	assert(MAT(1, 0) == 342);
	assert(MAT(1, 1) == 344);
}


/**************************************************
* testMatrixOperatorAddEqual
* *************************************************
* Test de l'opérateur +=
* *************************************************
* Entrée :
* Pré-condition :
* Sortie :
* Post-condition : aucun assert déclenché = operateur +=
fonctionnel
* ************************************************/
static void testMatrixOperatorAddEqual()
{
	CMatrix<int> MAT1(2, 2);
	MAT1(0, 0) = 111;
	MAT1(0, 1) = 112;
	MAT1(1, 0) = 121;
	MAT1(1, 1) = 122;

	CMatrix<int> MAT2(2, 2);
	MAT2(0, 0) = 211;
	MAT2(0, 1) = 212;
	MAT2(1, 0) = 221;
	MAT2(1, 1) = 222;

	CMatrix<int> MAT(2, 2);
	MAT(0, 0) = 0;
	MAT(0, 1) = 0;
	MAT(1, 0) = 0;
	MAT(1, 1) = 0;
	MAT += MAT1 += MAT2;

	assert(MAT(0, 0) == 322);
	assert(MAT(0, 1) == 324);
	assert(MAT(1, 0) == 342);
	assert(MAT(1, 1) == 344);

	CMatrix<int> MAT3(3, 2);

	try
	{
	    MAT1 += MAT3;
	    assert(false);
	}
	catch(Cexception& e){ }
}

/**************************************************
* testMatrixOperatorSub
* *************************************************
* Test de l'opérateur -
* *************************************************
* Entrée :
* Pré-condition :
* Sortie :
* Post-condition : aucun assert déclenché = soustraction
fonctionnelle
* ************************************************/
static void testMatrixOperatorSub()
{
	CMatrix<int> MAT1(2, 2);
	MAT1(0, 0) = 1;
	MAT1(0, 1) = 2;
	MAT1(1, 0) = 3;
	MAT1(1, 1) = 4;

	CMatrix<int> MAT2(2, 2);
	MAT2(0, 0) = 4;
	MAT2(0, 1) = 3;
	MAT2(1, 0) = 2;
	MAT2(1, 1) = 1;

	CMatrix<int> MAT(2, 2);
	MAT = MAT2 - MAT1;

	assert(MAT(0, 0) == 3);
	assert(MAT(0, 1) == 1);
	assert(MAT(1, 0) == -1);
	assert(MAT(1, 1) == -3);

	CMatrix<int> MAT3(3, 2);

	try
	{
	    MAT1 = MAT1 - MAT3;
	    assert(false);
	}
	catch(Cexception& e){ }
}

/**************************************************
* testMatrixOperatorSubEqual
* *************************************************
* Test de l'opérateur -=
* *************************************************
* Entrée :
* Pré-condition :
* Sortie :
* Post-condition : aucun assert déclenché = operateur -=
fonctionnel
* ************************************************/
static void testMatrixOperatorSubEqual()
{
	CMatrix<int> MAT(2, 2);
	MAT(0, 0) = 1;
	MAT(0, 1) = 2;
	MAT(1, 0) = 3;
	MAT(1, 1) = 4;

	CMatrix<int> MAT2(2, 2);
	MAT2(0, 0) = 4;
	MAT2(0, 1) = 3;
	MAT2(1, 0) = 2;
	MAT2(1, 1) = 1;

	MAT -= MAT2;

	assert(MAT(0, 0) == -3);
	assert(MAT(0, 1) == -1);
	assert(MAT(1, 0) == 1);
	assert(MAT(1, 1) == 3);

	CMatrix<int> MAT3(3, 2);

	try
	{
	    MAT = MAT - MAT3;
	    assert(false);
	}
	catch(Cexception& e){ }
}

/**************************************************
* testMatrixOperatorMultMat
* *************************************************
* Test de operator*(CMatrix<T>)
* *************************************************
* Entrée :
* Pré-condition :
* Sortie :
* Post-condition : aucun assert déclenché = operateur *
fonctionnel pour les matrices
* ************************************************/
static void testMatrixOperatorMultMat()
{
    CMatrix<int> O(2, 2);
	O(0, 0) = 0;
	O(0, 1) = 0;
	O(1, 0) = 0;
	O(1, 1) = 0;

	CMatrix<int> I(2, 2);
	I(0, 0) = 1;
	I(0, 1) = 0;
	I(1, 0) = 0;
	I(1, 1) = 1;

	CMatrix<int> MAT(2, 2);
	MAT(0, 0) = 11;
	MAT(0, 1) = 12;
	MAT(1, 0) = 21;
	MAT(1, 1) = 22;

    assert((MAT * O) == O);	//Test avec element nul
    assert((MAT * I) == MAT);	//Test avec element neutre

    CMatrix<int> MATLig(1, 3); //Déclaration matrice ligne
	MATLig(0, 0) = 1;
	MATLig(0, 1) = 2;
	MATLig(0, 2) = 1;

	CMatrix<int> MATCol(3, 1); //Déclaration matrice Colonne
	MATCol(0, 0) = 2;
	MATCol(1, 0) = 4;
	MATCol(2, 0) = 8;

	CMatrix<int> MATres1(1,1); //Déclaration matrice résultat attendu
	MATres1(0,0) = 18;

	CMatrix<int> MATres2(3, 3); //Déclaration matrice résultat attendu
	MATres2(0, 0) = 2;
	MATres2(0, 1) = 4;
	MATres2(0, 2) = 2;
	MATres2(1, 0) = 4;
	MATres2(1, 1) = 8;
	MATres2(1, 2) = 4;
	MATres2(2, 0) = 8;
	MATres2(2, 1) = 16;
	MATres2(2, 2) = 8;

	assert((MATLig * MATCol) == MATres1);	//Test avec matrices non carrées
	assert((MATCol * MATLig) == MATres2);

	try
	{
		MAT = MAT * MATLig;	//Test de l'exception matrices non compatibles
		assert(false);
	}
	catch(Cexception&){}
}

/**************************************************
* testMatrixOperatorMultConst
* *************************************************
* Test de operator*(const T)
* *************************************************
* Entrée :
* Pré-condition :
* Sortie :
* Post-condition : aucun assert déclenché = operateur *
fonctionnel pour un objet T constant
* ************************************************/
static void testMatrixOperatorMultConst()
{
    CMatrix<int> MAT(2, 2);
	MAT(0, 0) = 11;
	MAT(0, 1) = 12;
	MAT(1, 0) = 21;
	MAT(1, 1) = 22;

	assert((2 *MAT) == (MAT * 2));	//Test commutativité
	MAT = 2 * MAT;

	assert(MAT(0, 0) == 22);	//Test des bonnes valeurs
	assert(MAT(0, 1) == 24);
	assert(MAT(1, 0) == 42);
	assert(MAT(1, 1) == 44);
}

/**************************************************
* testMatrixOperatorMultEqualConst
* *************************************************
* Test de operator*=(const T)
* *************************************************
* Entrée :
* Pré-condition :
* Sortie :
* Post-condition : aucun assert déclenché = operateur *=
fonctionnel pour un objet T constant
* ************************************************/
static void testMatrixOperatorMultEqualConst()
{
    CMatrix<int> MAT(2, 2);
	MAT(0, 0) = 11;
	MAT(0, 1) = 12;
	MAT(1, 0) = 21;
	MAT(1, 1) = 22;

	MAT *= 2;

	assert(MAT(0, 0) == 22);	//Test des bonnes valeurs
	assert(MAT(0, 1) == 24);
	assert(MAT(1, 0) == 42);
	assert(MAT(1, 1) == 44);
}

/**************************************************
* testMatrixOperatorDiv
* *************************************************
* Test du bon retour de l'opérateur /(const T)
* *************************************************
* Entrée :
* Pré-condition :
* Sortie :
* Post-condition : aucun assert déclenché = operateur /
fonctionnel (niveau valeurs de retour)
* ************************************************/
static void testMatrixOperatorDiv()
{
	CMatrix<int> MAT2(2, 2);
	MAT2(0, 0) = 0;
	MAT2(0, 1) = -2;
	MAT2(1, 0) = 4;
	MAT2(1, 1) = -6;

	CMatrix<int> MAT(2, 2);
	MAT = MAT2 / -2;

	assert(MAT(0, 0) == 0); //Test des valeurs attendues
	assert(MAT(0, 1) == 1);
	assert(MAT(1, 0) == -2);
	assert(MAT(1, 1) == 3);
}

/**************************************************
* testMatrixOperatorDivExc
* *************************************************
* Test de du bon envoi des exceptions de l'opérateur /(const T)
* *************************************************
* Entrée :
* Pré-condition :
* Sortie :
* Post-condition : aucun assert déclenché = operateur /
fonctionnel (niveau lancement d'exceptions)
* ************************************************/
static void testMatrixOperatorDivExc()
{
	CMatrix<int> MAT2(2, 2);
	MAT2(0, 0) = 0;
	MAT2(0, 1) = 2;
	MAT2(1, 0) = 4;
	MAT2(1, 1) = 6;

	CMatrix<int> MAT(2, 2);
	try
	{
		MAT = MAT2 / 0; //Should throw an exception
		assert(false);
	}
	catch(Cexception& e)
	{
		assert(e.EXClire_valeur() == DIVIDE_BY_ZERO);
	};
}

/**************************************************
* testMatrixOperatorDivEqual
* *************************************************
* Test du bon retour l'opérateur /=(const T)
* *************************************************
* Entrée :
* Pré-condition :
* Sortie :
* Post-condition : aucun assert déclenché =
operateur /= fonctionnel (niveau valeurs)
* ************************************************/
static void testMatrixOperatorDivEqual()
{
	CMatrix<int> MAT(2, 2);
	MAT(0, 0) = 0;
	MAT(0, 1) = -2;
	MAT(1, 0) = 4;
	MAT(1, 1) = -6;

	MAT /= -2;

	assert(MAT(0, 0) == 0);	//Test des valeurs attendues
	assert(MAT(0, 1) == 1);
	assert(MAT(1, 0) == -2);
	assert(MAT(1, 1) == 3);
}

/**************************************************
* testMatrixOperatorDivEqualExc
* *************************************************
* Test du retour d'exception de l'opérateur /=(const T)
* *************************************************
* Entrée :
* Pré-condition :
* Sortie :
* Post-condition : aucun assert déclenché =
operateur /= fonctionnel (niveau lancement d'exceptions)
* ************************************************/
static void testMatrixOperatorDivEqualExc()
{
	CMatrix<int> MAT(2, 2);
	MAT(0, 0) = 0;
	MAT(0, 1) = 2;
	MAT(1, 0) = 4;
	MAT(1, 1) = 6;

	try
	{
		MAT /= 0; //Should throw an exception
		assert(false);
	}
	catch(Cexception& e)
	{
		assert(e.EXClire_valeur() == DIVIDE_BY_ZERO);
	};
}

/**************************************************
* testMatrixOperatorEqual
* *************************************************
* Test de l'opérateur =
* *************************************************
* Entrée :
* Pré-condition :
* Sortie :
* Post-condition : aucun assert déclenché = operateur "=" fonctionnel
* ************************************************/
static void testMatrixOperatorEqual()
{
	CMatrix<int> MAT(2, 2);
	MAT(0, 0) = 11;
	MAT(0, 1) = 12;
	MAT(1, 0) = 21;
	MAT(1, 1) = 22;

	CMatrix<int> MATCopy(2,2);
	MATCopy = MAT;

	assert(MATCopy(0, 0) == 11);
	assert(MATCopy(0, 1) == 12);
	assert(MATCopy(1, 0) == 21);
	assert(MATCopy(1, 1) == 22);
}

/**************************************************
* testMatrixOperatorEquality
* *************************************************
* Test de l'opérateur ==
* *************************************************
* Entrée :
* Pré-condition :
* Sortie :
* Post-condition : aucun assert déclenché = operateur == fonctionnel
* ************************************************/
static void testMatrixOperatorEquality()
{
    CMatrix<int> MAT(2, 2);
	MAT(0, 0) = 11;
	MAT(0, 1) = 12;
	MAT(1, 0) = 21;
	MAT(1, 1) = 22;

	CMatrix<int> MAT2(2, 2);
	MAT2(0, 0) = 11;
	MAT2(0, 1) = 12;
	MAT2(1, 0) = 21;
	MAT2(1, 1) = 0;

	CMatrix<int> MAT3(1, 2);
	MAT3(0, 0) = 11;
	MAT3(0, 1) = 12;

    if(!(MAT == MAT))
        assert(false);
    if(MAT == MAT2)
        assert(false);
    try{
        MAT == MAT3;
        assert(false);
    }catch(Cexception& e)
    {
        //Gestion de l'exception
    }
}

/**************************************************
* testMatrixOperatorInequality
* *************************************************
* Test de l'opérateur !=
* *************************************************
* Entrée :
* Pré-condition :
* Sortie :
* Post-condition : aucun assert déclenché = operateur != fonctionnel
* ************************************************/
static void testMatrixOperatorInequality()
{
	CMatrix<int> MAT(2, 2);
	MAT(0, 0) = 11;
	MAT(0, 1) = 12;
	MAT(1, 0) = 21;
	MAT(1, 1) = 22;

	CMatrix<int> MAT2(2, 2);
	MAT2(0, 0) = 11;
	MAT2(0, 1) = 12;
	MAT2(1, 0) = 21;
	MAT2(1, 1) = 0;

	CMatrix<int> MAT3(1, 2);
	MAT3(0, 0) = 11;
	MAT3(0, 1) = 12;

    if(MAT != MAT)
        assert(false);
    if(!(MAT != MAT2))
        assert(false);
    try{
        MAT != MAT3;
        assert(false);
    }catch(Cexception& e)
    {
        //Gestion de l'exception
    }
}

/**************************************************
* testMatrixOperator()
* *************************************************
* Test de l'opérateur () (en set et en get)
* *************************************************
* Entrée :
* Pré-condition :
* Sortie :
* Post-condition : aucun assert déclenché = operateur () fonctionnel
* ************************************************/
static void testMatrixOperatorParenthesis()
{
	CMatrix<int> MAT(2, 3);
	MAT(1,2) = 43;
	assert(MAT(1,2) == 43);
}

/**************************************************
* testMatrixOperatorStream
* *************************************************
* Test de l'opérateur <<
* *************************************************
* Entrée :
* Pré-condition :
* Sortie :
* Post-condition : aucun assert déclenché = operateur << fonctionnel
* ************************************************/
static void testMatrixOperatorStream()
{
    CMatrix<int> MAT1(2, 2);
	MAT1(0, 0) = 111;
	MAT1(0, 1) = 112;
	MAT1(1, 0) = 121;
	MAT1(1, 1) = 122;
	cout << MAT1;

	CMatrix<double> MAT2(2, 2);
	MAT2(0, 0) = .111;
	MAT2(0, 1) = 1.12;
	MAT2(1, 0) = 12.1;
	MAT2(1, 1) = 122.;
	cout << MAT2;
}


/**************************************************
* testMatrix
* *************************************************
* Fonction d'appel des tests unitaires des fonctions
* *************************************************
* Entrée :
* Pré-condition :
* Sortie :
* Post-condition : Aucune assert déclenchée = librairie fonctionnelle
* ************************************************/
void CUnitTest::testMatrix()
{
	testMatrixConstructor();
	testMatrixConstructorByCopy();
	testMatrixOperatorAdd();
	testMatrixOperatorAddEqual();
	testMatrixOperatorSub();
	testMatrixOperatorSubEqual();
	testMatrixOperatorMultMat();
	testMatrixOperatorMultConst();
	testMatrixOperatorMultEqualConst();
	testMatrixOperatorDiv();
	testMatrixOperatorDivExc();
	testMatrixOperatorDivEqual();
	testMatrixOperatorDivEqualExc();
	testMatrixOperatorEqual();
	testMatrixOperatorEquality();
	testMatrixOperatorInequality();
	testMatrixOperatorParenthesis();

	testMatrixOperatorStream();
}
