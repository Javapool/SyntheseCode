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
	temp.mValues[0] = cos(deg*M_PI/180);
	temp.mValues[2] = -sin(deg*M_PI / 180);
	temp.mValues[8] = sin(deg*M_PI / 180);
	temp.mValues[10] = cos(deg*M_PI / 180);

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

TMatrix MatrixCreator::scale(float size)
{
	TMatrix temp = TMatrix(identityArray);
	temp.mValues[0] = size;
	temp.mValues[5] = size;
	temp.mValues[10] = size;
	return temp;
}

void MatrixCreator::projection(float fov , float near, float far, TMatrix & source)
{
	float scale = 1 / (tan((fov / 2)*(M_PI / 180)));
	//source = identityArray;
	//source.mValues[0] = scale;
	//source.mValues[5] = scale;
	//source.mValues[10] = -(far / (far - near));
	source.mValues[11] = -1;
	source.mValues[15] = 0;

}


void MatrixCreator::normalization(Player * player, TMatrix & source)
{

	const float posX{ player->mX };
	const float posY{ player->mY };
	const float posZ{ player->mZ };
	const float angle{ player->mAngle };

	source = translation(-(posX), -(posY), -(posZ))*rotationY(-(angle));
}

void MatrixCreator::movement(ObjetPhysique *objet, TMatrix & source)
{

	const float posX{ objet->mX };
	const float posY{ objet->mY };
	const float posZ{ objet->mZ };
	const float angle{ objet->mAngle };

	const float deltaX{ objet->mDeltaX };
	const float deltaY{ objet->mDeltaY };
	const float deltaZ{ objet->mDeltaZ };

	const float deltaAngle{ objet->mDeltaAngle };

	source = rotationY(angle)* translation(posX, posY, posZ);
}

