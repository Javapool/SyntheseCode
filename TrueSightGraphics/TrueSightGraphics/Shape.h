#pragma once
#include "types.h"
#include<vector>
#include <utility>
#include "Vertex.h"
class Shape
{

	using line = std::pair<Vertex*, Vertex*>;
	using plane = std::tuple<Vertex*, Vertex*, Vertex*>;

	std::vector<Vertex> mVertices;
	std::vector<line> mLines;
	std::vector<plane> mPlanes;


public:
	Shape();
	~Shape();
};

