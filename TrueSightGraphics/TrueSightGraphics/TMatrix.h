#pragma once
#include "Matrix.h"
#include "CoordsMatrix.h"

typedef std::array<float, 16> squareMatrix;
typedef std::array<float*, 16> squareIndexMatrix;

class TMatrix:
	public Matrix
{
	friend class CoordsMatrix;
	friend class MatrixCreator;
	squareMatrix mValues;
public:
	TMatrix();
	TMatrix(squareMatrix values);
	~TMatrix();

	void afficher();
	TMatrix operator*(TMatrix matrix);
	CoordsMatrix operator*(CoordsMatrix matrix);
private:


};

