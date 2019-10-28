#pragma once
#include <vector>

#include "CoordsMatrix.h"
class Vertex
{
	CoordsMatrix mCoords;

public:
	Vertex(float x, float y, float z, float h);
	~Vertex();
};

