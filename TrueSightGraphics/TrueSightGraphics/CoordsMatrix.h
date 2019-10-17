#pragma once
#include "Matrix.h"
#include"TMatrix.h"
class CoordsMatrix:
	public Matrix
{
	friend class TMatrix;

	std::array<float, 4> mCoords;
public:
	CoordsMatrix(float x, float y, float z, float h);
	~CoordsMatrix()=default;

private:
	void operator*(TMatrix &matrix);
};

