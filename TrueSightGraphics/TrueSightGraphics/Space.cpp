#include "Space.h"



Space::Space()
{
	builder.readFiles();
}


Space::~Space()
{
}

void Space::initialize()
{
}

void Space::createObject(int index, float size, float posX, float posY, float posZ, float angle)
{
	ShapeBlueprint bluePrint = builder.getShape(index);

	ObjetPhysique nouveau = ObjetPhysique(bluePrint, size, posX, posY, posZ, angle);

}

void Space::update()
{

	for (ObjetPhysique objet : mObjets) {
		MatrixCreator::movement(&objet, mMatriceObjet);
		objet.transform(mMatriceObjet);
	}
}
