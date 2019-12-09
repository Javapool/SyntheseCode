#include "Shape.h"

Shape::Shape(ShapeBlueprint BP)
{
	mVertices = BP.getVertices();
	std::vector<std::pair<int, int>> lines = BP.getLines();
	std::vector<std::tuple<int, int, int>> planes = BP.getPlanes();
	mLines.resize(lines.size());
	mPlanes.resize(planes.size());
	for (size_t i = 0; i < lines.size(); i++)
	{
		mLines[i].first = &(mVertices[lines[i].first]);
		mLines[i].second = &(mVertices[lines[i].second]);
	}

	for (size_t j = 0; j < planes.size(); j++)
	{
		std::get<0>(mPlanes[j]) = &(mVertices[std::get<0>(planes[j])]);
		std::get<1>(mPlanes[j]) = &(mVertices[std::get<1>(planes[j])]);
		std::get<2>(mPlanes[j]) = &(mVertices[std::get<2>(planes[j])]);
	}

}

float * Shape::getCoords()
{
	return mCoords.getCoords();
}

float * Shape::getDeltas()
{
	return mMovement.getCoords();
}

void Shape::move(TMatrix * matriceTrans)
{
	mCoords*(*matriceTrans);
}

void Shape::
normalize(TMatrix * matriceNorm)
{
}

Shape::~Shape()
{
}
