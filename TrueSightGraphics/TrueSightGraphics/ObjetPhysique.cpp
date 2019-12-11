#include "ObjetPhysique.h"



ObjetPhysique::ObjetPhysique(ShapeBlueprint bluePrint, float size, float posX, float posY, float posZ, float angle)
	:mMovement{ 0,0,0,0 }, mCoords{ posX,posY,posZ,1 }, mAngle{ angle }
{
	mForme = &Shape(bluePrint);
	TMatrix scaleMatrix = MatrixCreator::scale(size);
	TMatrix angleMatrix = MatrixCreator::rotationY(angle);
	TMatrix positionMatrix = MatrixCreator::translation(posX, posY, posZ);

	TMatrix placementMatrix = ((scaleMatrix*angleMatrix)*positionMatrix);

	mForme->transform(placementMatrix);

}


ObjetPhysique::~ObjetPhysique()
{
}

void ObjetPhysique::normalize(TMatrix tMatrix)
{
	mForme->normalize(tMatrix);

}
Shape* ObjetPhysique::getShape()
{
	return mForme;
}

void ObjetPhysique::move()
{
	TMatrix placementMatrix;
	if (mDeltaAngle != 1) {
		TMatrix centerMatrix = MatrixCreator::translation(-mX,-mY,-mZ);
		TMatrix angleMatrix = MatrixCreator::rotationY(mDeltaAngle);
		TMatrix positionMatrix = MatrixCreator::translation(mDeltaX+mX, mDeltaY+mY, mDeltaZ+mZ);
		TMatrix placementMatrix = ((centerMatrix*angleMatrix)*positionMatrix);

	}
	else {
		TMatrix placemetMatrix = MatrixCreator::translation(mDeltaX,mDeltaY,mDeltaZ);
	}

	mForme->transform(placementMatrix);
}

void ObjetPhysique::clampAngle()
{
	if (mAngle > 360) {
		mAngle -= 360;
	}
	else if (mAngle< 0) {
		mAngle+= 360;
	}
}


