#pragma once
#include "ShapeBlueprint.h"
#include "FileReader.h"
class ShapeBuilder
{
	std::vector<ShapeBlueprint> blueprints;
	FileReader reader;
public:
	ShapeBuilder();
	~ShapeBuilder();
	void readFiles();
};

