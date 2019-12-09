#pragma once
#include "TMatrix.h"
#include "Player.h"
#include "Shape.h"
const std::array<float, 16> identityArray{ 1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1 };
class MatrixCreator
{
public:
	MatrixCreator();
	~MatrixCreator();
	static TMatrix rotationY(float deg);
	static TMatrix translation(float x, float y, float z);
	static TMatrix identity();
	static TMatrix composite(float x, float y, float z, float degY);
	static TMatrix scaleNew(float size);
	static TMatrix normalization(Player *player);
	static TMatrix movement(Shape *shape);
};

