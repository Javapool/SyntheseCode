#include "ObjetPhysique.h"
#include "MatrixCreator.h"



ObjetPhysique::ObjetPhysique(ShapeBlueprint bluePrint, float size, float posX, float posY, float posZ, float angle, float spin)
	:mX{ posX }, mY{ posY }, mZ{ posZ }, mAngle{ angle }, mForme(bluePrint), mDeltaAngle{spin}
{
	TMatrix scaleMatrix = MatrixCreator::scale(size);
	TMatrix angleMatrix = MatrixCreator::rotationY(angle);
	TMatrix positionMatrix = MatrixCreator::translation(posX, posY, posZ);

	TMatrix placementMatrix = scaleMatrix*angleMatrix*positionMatrix;

	mForme.transform(placementMatrix);

}


ObjetPhysique::~ObjetPhysique()
{
}

void ObjetPhysique::normalize(TMatrix tMatrix)
{
	mForme.transform(tMatrix);
	mForme.displayCheck();

}
Shape* ObjetPhysique::getShape()
{
	return &mForme;
}

void ObjetPhysique::move()
{
	mX += mDeltaX;
	mY += mDeltaY;
	mZ += mDeltaZ;
	mAngle += mDeltaAngle;
	clampAngle();
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


