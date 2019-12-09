#include "ObjetPhysique.h"



ObjetPhysique::ObjetPhysique(float posX, float posY, float posZ, float angle)
	:mMovement{ 0,0,0,0 }, mCoords{posX,posY,posZ,angle}
{
}


ObjetPhysique::~ObjetPhysique()
{
}

void ObjetPhysique::move()
{
	mCoords += mMovement;
	mCoords.clampAngle();
}
