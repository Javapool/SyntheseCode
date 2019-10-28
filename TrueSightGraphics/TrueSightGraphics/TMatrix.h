#pragma once
#include "Matrix.h"
#include "CoordsMatrix.h"
class TMatrix:
	public Matrix
{
	friend class CoordsMatrix;
	friend class MatrixCreator;
	std::array<float, 16> mValues;
public:
	TMatrix();
	TMatrix(std::array<float, 16> values);
	~TMatrix();

	void symmetrize();
private:
	//TMatrix operator*(const TMatrix &matrix);
	//TMatrix operator*(CoordsMatrix *matrix);

};

