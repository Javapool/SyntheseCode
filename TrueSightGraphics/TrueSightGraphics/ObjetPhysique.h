#pragma once
#include "Vertex.h"
#include "Shape.h"
#include <string>
class ObjetPhysique
{
	std::string nom;
	//dans mMovement les 4 float représentent des vecteurs de déplacement(x,y,z et rotation)
	Vertex mMovement;
	//dans mCoords les 4 float représentent des vecteurs de position(x,y,x et angle)
	Vertex mCoords;
	Shape* forme;
public:
	ObjetPhysique(float posX, float posY, float posZ, float angle);
	~ObjetPhysique();
	void move();
};

