#pragma once
#include "Vertex.h"
#include "Shape.h"
#include "MatrixCreator.h"
#include <string>
class ObjetPhysique
{
	std::string nom;
	Vertex mMovement;
	Vertex mCoords;
	float mX;
	float mY;
	float mZ;
	float mAngle;

	float mDeltaX;
	float mDeltaY;
	float mDeltaZ;
	float mDeltaAngle;


	Shape *mForme;
public:
	ObjetPhysique(ShapeBlueprint bluePrint, float size, float posX, float posY, float posZ, float angle);
	~ObjetPhysique();
	void normalize(TMatrix tMatrix);
	Shape* getShape();
	void clampAngle();
	void move();
};

