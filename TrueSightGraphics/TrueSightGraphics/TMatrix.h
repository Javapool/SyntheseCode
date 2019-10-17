#pragma once
#include "Matrix.h"
#include "CoordsMatrix.h"
class TMatrix:
	public Matrix
{
	friend class CoordsMatrix;

	std::array<float, 16> mValues;
public:
	TMatrix();
	~TMatrix();
private:
	void operator*(const TMatrix &matrix);
	void operator*(CoordsMatrix *matrix);

};

