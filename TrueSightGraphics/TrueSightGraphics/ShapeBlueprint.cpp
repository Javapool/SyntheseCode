#include "ShapeBlueprint.h"




ShapeBlueprint::ShapeBlueprint()
{
}


ShapeBlueprint::~ShapeBlueprint()
{
}

void ShapeBlueprint::addVertex(float x, float y, float z, float h)
{
	mVertices.push_back(Vertex(x, y, z, h));
}

void ShapeBlueprint::addLine(int vertexIndexA, int vertexIndexB)
{
	mLines.push_back(lineIndex(vertexIndexA, vertexIndexB));
}

void ShapeBlueprint::addPlane(int vertexIndexA, int vertexIndexB, int vertexIndexC)
{
	mPlanes.push_back(planeIndex(vertexIndexA, vertexIndexB, vertexIndexC));
}

std::vector<Vertex> ShapeBlueprint::getVertices()
{
	return mVertices;
}
