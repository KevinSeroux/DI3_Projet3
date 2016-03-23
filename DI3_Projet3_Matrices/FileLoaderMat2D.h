#include "Mat2D.h"

#pragma once
class CFileLoaderMat2D
{
	//Constructeur
private:
	CFileLoaderMat2D(void){};
	~CFileLoaderMat2D(void){};

	//Methode
	CMat2D<double> FLMload(char* pcPath);
};

