#pragma once
#include <vector>

#include "CoordsMatrix.h"
class Vertex
{
	friend class TMatrix;
	float mCoords[4];

public:
	Vertex(float x, float y, float z, float h);
	~Vertex();

	float* getCoords();
	void afficher();
	Vertex operator*(TMatrix matrix);
	void divideByH();
};

