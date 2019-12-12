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


std::list<std::pair<Vertex*, Vertex*>>  Space::getLines() {

	std::list<std::pair<Vertex*, Vertex*>> tempListe;

	for(ObjetPhysique obj : mObjets)
	{
		std::vector<pLine> *lines = (*(obj.getShape())).getLines();
		for (pLine line : *lines ) {
			if (std::get<2>(line)) {
				std::pair<Vertex*, Vertex*> tempLigne;
				tempLigne.first = std::get<0>(line);
				tempLigne.second = std::get<1>(line);
				tempListe.push_back(tempLigne);
			}
		}

	}
	return tempListe;

}


void Space::createObject(int index, float size, float posX, float posY, float posZ, float angle)
{
	ShapeBlueprint bluePrint = builder.getShape(index);

	ObjetPhysique nouveau = ObjetPhysique(bluePrint, size, posX, posY, posZ, angle);
	mObjets.push_back(nouveau);

}

void Space::update()
{
	MatrixCreator::normalization(&player, mMatciceGlobale);
	for (ObjetPhysique objet : mObjets) {
		MatrixCreator::movement(&objet, mMatriceObjet);
		mMatriceCourante = mMatriceObjet * mMatciceGlobale;
		objet.normalize(mMatriceCourante);
	}
}
