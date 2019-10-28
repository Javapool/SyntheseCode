#pragma once
#include "Matrix.h"
#include"TMatrix.h"
class CoordsMatrix:
	public Matrix
{
	friend class TMatrix;
	float mCoords[4];
public:
	CoordsMatrix(float x, float y, float z, float h);
	~CoordsMatrix()=default;

private:
	void operator*(TMatrix &matrix);
};

