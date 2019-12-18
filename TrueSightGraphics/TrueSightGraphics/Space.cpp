#include "Space.h"



Space::Space()
{
	builder.generateGrid(20);
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

	for(ObjetPhysique* obj : mObjets)
	{
		std::vector<pLine> *lines = (*((*obj).getShape())).getLines();
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


void Space::createObject(int index, float size, float posX, float posY, float posZ, float angle,float spin)
{
	ShapeBlueprint bluePrint = builder.getShape(index);

	ObjetPhysique* nouveau = new ObjetPhysique(bluePrint, size, posX, posY, posZ, angle,  spin);
	mObjets.push_back(nouveau);

}

void Space::update()
{
	player.move();
	MatrixCreator::normalization(&player, mMatciceGlobale);
	mMatciceGlobale = mMatciceGlobale * mMatriceProjection;
	for (ObjetPhysique *objet : mObjets) {
		objet->move();
		MatrixCreator::movement(objet, mMatriceObjet);
		mMatriceCourante = mMatriceObjet * mMatciceGlobale;
		(*objet).normalize(mMatriceCourante);
	}
}

void Space::setup(float fov, float nearPlane, float farPlane)
{
	MatrixCreator::projection(fov, nearPlane, farPlane, mMatriceProjection);
}

void Space::turnPlayer(int angle)
{
	player.turnY(angle);
}

void Space::movePlayer(int direction)
{
	switch (direction) {
	case Player::FORWARD:
		player.accelerateForward();
		break;
	case Player::LEFT:
		player.accelerateLeft();
		break;
	case Player::BACK:
		player.accelerateBackwards();
		break;
	case Player::RIGHT:
		player.accelerateRight();
		break;
	case Player::UP:
		player.accelerateUp();
		break;
	case Player::DOWN:
		player.accelerateDown();
		break;
	}
}

void Space::deceleratePlayer(int direction)
{
	switch (direction) {
	case Player::FORWARD:
		player.decelerateForward();
		break;
	case Player::LEFT:
		player.decelerateLeft();
		break;
	case Player::BACK:
		player.decelerateBackwards();
		break;
	case Player::RIGHT:
		player.decelerateRight();
		break;
	case Player::UP:
		player.decelerateUp();
		break;
	case Player::DOWN:
		player.decelerateDown();
		break;
	}
}
