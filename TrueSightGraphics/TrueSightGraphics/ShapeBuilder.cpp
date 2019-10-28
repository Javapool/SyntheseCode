#include "ShapeBuilder.h"



ShapeBuilder::ShapeBuilder()
{
}


ShapeBuilder::~ShapeBuilder()
{
}

void ShapeBuilder::readFiles()
{
	blueprints.push_back(reader.readFile("..\\OBJFILES\\cube.obj"));
}
