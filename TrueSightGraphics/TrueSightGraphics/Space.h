#pragma once
#include<list>
#include"ObjetPhysique.h"
#include "ShapeBuilder.h"
#include "MatrixCreator.h"
class Space
{
	std::list<ObjetPhysique> mObjets;
	TMatrix mMatriceObjet;
	TMatrix mMatciceGlobale;
	ShapeBuilder builder;



public:

	Space();
	~Space();
	void initialize();
	void createObject(int index, float size, float posX, float posY, float pozZ, float angle);
	void update();
};

