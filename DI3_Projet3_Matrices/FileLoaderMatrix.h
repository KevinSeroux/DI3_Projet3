#ifndef FILELOADERMAT2D_H
#define FILELOADERMAT2D_H

#include "Matrix.h"

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