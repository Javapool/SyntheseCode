#pragma once
#include<list>
#include"ObjetPhysique.h"
#include "ShapeBuilder.h"
#include "MatrixCreator.h"
#include "Player.h"
class Space
{
	std::list<ObjetPhysique*> mObjets;
	TMatrix mMatciceGlobale;
	TMatrix mMatriceObjet;
	TMatrix mMatriceProjection;
	TMatrix mMatriceCourante;
	ShapeBuilder builder;
	Player player;



public:

	Space();
	~Space();
	void initialize();
	std::list<std::pair<Vertex*, Vertex*>>  getLines();
	void createObject(int index, float size, float posX, float posY, float pozZ, float angle, float spin);
	void update();
	void setup(float fov, float nearPlane, float farPlane);
	//0forward, 1 left, 2backwards, 3 right
	void turnPlayer(int angle);
	void movePlayer(int direction);
	void deceleratePlayer(int direction);
};

