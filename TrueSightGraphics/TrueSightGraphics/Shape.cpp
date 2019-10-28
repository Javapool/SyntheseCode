#include "Shape.h"


Shape::Shape(ShapeBlueprint BP)
{
	mVertices = BP.getVertices();
}

Shape::~Shape()
{
}
