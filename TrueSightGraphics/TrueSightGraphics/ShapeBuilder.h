#pragma once
#include "ShapeBlueprint.h"
#include "FileReader.h"
#include <string>
#include <iostream>
#include <filesystem>
#include <Windows.h>
#include "Shape.h"

class ShapeBuilder
{
	std::vector<ShapeBlueprint> mBlueprints;
	FileReader reader;
public:
	ShapeBuilder()=default;
	~ShapeBuilder()=default;
	void generateGrid(float);
	void readFiles();
	void showFiles();
	ShapeBlueprint getShape(int index);
	
};



