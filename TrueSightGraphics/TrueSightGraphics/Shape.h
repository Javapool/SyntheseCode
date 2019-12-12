#pragma once

#include<vector>
#include <utility>
#include "Vertex.h"
#include "ShapeBlueprint.h"
#include <tuple>

	using pLine= std::tuple<Vertex*, Vertex*, bool>;
	using line = std::pair<Vertex*, Vertex*>;
	using plane = std::tuple<Vertex*, Vertex*, Vertex*>;

class Shape
{
	//Pvertices et Plines sont les lignes et les vertex après normalisation

	std::vector<Vertex> mVertices;
	std::vector<Vertex> mPVertices;
	//std::vector<line> mLines;
	std::vector<pLine> mPLines;
	std::vector<plane> mPlanes;


public:
	Shape(ShapeBlueprint BP);
	void transform(TMatrix matriceTrans);
	std::vector<pLine> *getLines();
	//void normalize(TMatrix matriceNorm);
	~Shape();
};

