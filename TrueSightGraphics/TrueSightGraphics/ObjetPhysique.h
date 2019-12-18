#pragma once
#include "Vertex.h"
#include "Shape.h"
#include <string>

class MatrixCreator;

class ObjetPhysique
{
	friend class MatrixCreator;
	std::string nom{"salut"};
	float mX;
	float mY;
	float mZ;
	float mAngle;

	float mDeltaX{0};
	float mDeltaY{0};
	float mDeltaZ{0};
	float mDeltaAngle;



	Shape mForme;
public:
	ObjetPhysique(ShapeBlueprint bluePrint, float size, float posX, float posY, float posZ, float angle, float spin);
	~ObjetPhysique();
	void normalize(TMatrix tMatrix);
	Shape* getShape();
	void clampAngle();
	void move();
};

