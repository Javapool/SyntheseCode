#include "Vertex.h"





Vertex::Vertex(float x, float y, float z, float h)
	:mCoords(x,y,z,h)
{
}

Vertex::~Vertex()
{
}

float *Vertex::getCoords()
{
	return mCoords.getCoords();
}

void Vertex::afficher()
{
	mCoords.afficher();
}
