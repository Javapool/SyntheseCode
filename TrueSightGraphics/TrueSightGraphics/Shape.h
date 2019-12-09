#pragma once

#include<vector>
#include <utility>
#include "Vertex.h"
#include "ShapeBlueprint.h"
class Shape
{

	using line = std::pair<Vertex*, Vertex*>;
	using plane = std::tuple<Vertex*, Vertex*, Vertex*>;

	std::vector<Vertex> mVertices;
	std::vector<line> mLines;
	std::vector<plane> mPlanes;
	Vertex mPosition;


public:
	Shape(ShapeBlueprint BP);
	~Shape();
};

