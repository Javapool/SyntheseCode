#pragma once
#include <array>
#include "CoordsMatrix.h"
#include "Vertex.h"

	typedef std::array<float, 16> squareMatrix;
	typedef std::array<float*, 16> squareIndexMatrix;

class TMatrix
{
	friend class Vertex;
	friend class MatrixCreator;
	squareMatrix mValues{ 1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1 };
public:
	TMatrix();
	TMatrix(squareMatrix values);
	~TMatrix();

	void afficher();
	TMatrix operator*(TMatrix const &matrix);
	Vertex operator*(Vertex const &matrix);
private:


};

