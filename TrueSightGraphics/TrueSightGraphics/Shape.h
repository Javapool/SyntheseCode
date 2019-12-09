#pragma once

#include<vector>
#include <utility>
#include "Vertex.h"
#include "ShapeBlueprint.h"
class Shape
{

	using line = std::pair<Vertex*, Vertex*>;
	using plane = std::tuple<Vertex*, Vertex*, Vertex*>;

	//dans mMovement les 4 float représentent des vecteurs de déplacement(x,y,z et rotation)
	Vertex mMovement;
	//dans mCoords les 4 float représentent des vecteurs de position(x,y,x et angle)
	Vertex mCoords;

	std::vector<Vertex> mVertices;
	std::vector<line> mLines;
	std::vector<plane> mPlanes;


public:
	Shape(ShapeBlueprint BP);
	float* getCoords();
	float* getDeltas();
	void move(TMatrix *matriceTrans);
	void normalize(TMatrix *matriceNorm);
	~Shape();
};

