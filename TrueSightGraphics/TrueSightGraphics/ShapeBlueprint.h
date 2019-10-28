#pragma once
#include "Vertex.h"
class ShapeBlueprint
{
	using lineIndex = std::pair<uint8_t, uint8_t>;
	using planeIndex = std::tuple<uint8_t, uint8_t, uint8_t>;

	std::vector<Vertex> mVertices;
	std::vector<lineIndex> mLines;
	std::vector<planeIndex> mPlanes;
public:
	ShapeBlueprint();
	~ShapeBlueprint();
	void addVertex(float x, float y, float z, float h);
	void addLine(int vertexIndexA, int vertexIndexB);
	void addPlane(int vertexIndexA, int vertexIndexB, int vertexIndexC);
	std::vector<Vertex> getVertices();
};

