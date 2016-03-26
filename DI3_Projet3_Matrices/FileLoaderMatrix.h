#ifndef FILELOADERMATRIX_H
#define FILELOADERMATRIX_H

#include "Mat2D.h"
#include <iostream>
#include <fstream>

using namespace std;

class CFileLoaderMatrix
{
	//Constructeur
private:
	CFileLoaderMatrix(void){};
	~CFileLoaderMatrix(void){};

	//Methode
public:	
	CMatrix<double> static FLMload(char* pcPath);
};

#endif //FILELOADERMAT2D_H