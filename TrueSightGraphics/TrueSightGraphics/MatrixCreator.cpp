#include "MatrixCreator.h"



MatrixCreator::MatrixCreator()
{
}


MatrixCreator::~MatrixCreator()
{
}

TMatrix MatrixCreator::rotationY(float deg)
{
	//deg est en radians
	TMatrix temp = TMatrix(identityArray);
	temp.mValues[0] = cos(deg);
	temp.mValues[2] = -sin(deg);
	temp.mValues[9] = sin(deg);
	temp.mValues[10] = cos(deg);

	return temp;
}

TMatrix MatrixCreator::translation(float x, float y, float z)
{

	TMatrix temp = TMatrix(identityArray);
	temp.mValues[12] = x;
	temp.mValues[13] = y;
	temp.mValues[14] = z;
	return temp;

}

TMatrix MatrixCreator::identity()
{
	return TMatrix(identityArray);
}

TMatrix MatrixCreator::composite(float x, float y, float z, float degY)
{
	return translation(x,y,z)*rotationY(degY);

}

TMatrix MatrixCreator::scaleNew(float size)
{
	TMatrix temp = TMatrix(identityArray);
	temp.mValues[0] = size;
	temp.mValues[5] = size;
	temp.mValues[10] = size;
	return temp;
}

TMatrix MatrixCreator::normalization(Player * player)
{
	float* coords{ player->getCoords() };

	const float posX{ *coords };
	const float posY{ *(coords + 1) };
	const float posZ{ *(coords + 2) };
	const float angle{ *(coords + 3) };

	return translation(-(posX), -(posY), -(posZ))*rotationY(-(angle));
}

TMatrix MatrixCreator::movement(Shape * shape)
{
	const float * coords{ shape->getCoords() };
	const float * deltas{ shape->getDeltas() };
	const float posX{ *coords };
	const float posY{ *(coords + 1) };
	const float posZ{ *(coords + 2) };

	const float deltaX{ * deltas};
	const float deltaY{ *(deltas+ 1) };
	const float deltaZ{ *(deltas+ 2) };

	const float deltaAngle{ *(deltas + 3) };

	return translation(-(posX), -(posY), -(posZ))*rotationY(deltaAngle)* translation(posX+deltaX, posY+deltaY, posZ+deltaZ);
}

