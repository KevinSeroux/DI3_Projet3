#ifndef FILELOADERMATRIX_H
#define FILELOADERMATRIX_H

#include <iostream>
#include <fstream>
#include "Matrix.h"

using namespace std;

class CFileLoaderMatrix
{
	//Constructeur
private:
	CFileLoaderMatrix(void){};
	~CFileLoaderMatrix(void){};

	//Methode
public:	
	static CMatrix<double> FLMload(char* pcPath);
};

#endif //FILELOADERMAT2D_H