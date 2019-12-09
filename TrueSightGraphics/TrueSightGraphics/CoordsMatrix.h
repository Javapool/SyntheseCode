#pragma once
#include "Matrix.h"
#include"TMatrix.h"
#include <conio.h>
#include <iostream>
class CoordsMatrix:
	public Matrix
{
	friend class TMatrix;
	float mCoords[4];
public:
	CoordsMatrix();
	CoordsMatrix(float x, float y, float z, float h);
	~CoordsMatrix()=default;
	void afficher();
	CoordsMatrix operator*(TMatrix matrix);
	void divideByH();

private:
};

