#include "ShapeBlueprint.h"



ShapeBlueprint::ShapeBlueprint()
{
}


ShapeBlueprint::~ShapeBlueprint()
{
}

void ShapeBlueprint::resizeVerticesVector(uint16_t n)
{
	mVertices.reserve(n);
}

void ShapeBlueprint::resizeLinePlaneVectors(uint16_t n)
{
	mPlanes.reserve(n);
	mLines.reserve((n * 3 / 2));
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

std::vector<std::pair<int, int>> ShapeBlueprint::getLines()
{
	return mLines;
}

std::vector<std::tuple<int, int, int>> ShapeBlueprint::getPlanes()
{
	return mPlanes;
}

void ShapeBlueprint::afficher()
{
	std::cout << "Vertices : "<< mVertices.size();
	for (Vertex v : mVertices) {
		std::cout << "\n";
		v.afficher();

	}
	std::cout << "\n\nLines : "<<mLines.size();
	for (lineIndex l : mLines) {
		std::cout << "\n"<<l.first<<" - "<<l.second;

	}

	std::cout << "\n\nPlanes : "<<mPlanes.size();
	for (planeIndex p : mPlanes) {
		std::cout << "\n" << std::get<0>(p) << " - " << std::get<1>(p) << " - " << std::get<2>(p);

	}

}


