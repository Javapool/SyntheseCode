#pragma once
#include "Vertex.h"
class ShapeBlueprint
{
	using lineIndex = std::pair<int, int>;
	using planeIndex = std::tuple<int, int, int>;

	std::vector<Vertex> mVertices;
	std::vector<lineIndex> mLines;
	std::vector<planeIndex> mPlanes;
public:
	ShapeBlueprint();
	~ShapeBlueprint();
	void resizeVerticesVector(uint16_t n);
	void resizeLinePlaneVectors(uint16_t n);
	void addVertex(float x, float y, float z, float h);
	void addLine(int vertexIndexA, int vertexIndexB);
	void addPlane(int vertexIndexA, int vertexIndexB, int vertexIndexC);
	std::vector<Vertex> getVertices();
	std::vector<std::pair<int, int>> getLines();
	std::vector<std::tuple<int, int, int>> getPlanes();

	void afficher();
};

