#include "Shape.h"

Shape::Shape(ShapeBlueprint BP)
{
	mVertices = BP.getVertices();
	mPVertices = BP.getVertices();
	std::vector<std::pair<int, int>> lines = BP.getLines();
	std::vector<std::tuple<int, int, int>> planes = BP.getPlanes();
	mLines.resize(lines.size());
	mPLines.resize(lines.size());
	mPlanes.resize(planes.size());
	for (size_t i = 0; i < lines.size(); i++)
	{
		mLines[i].first = &(mVertices[lines[i].first]);
		mLines[i].second = &(mVertices[lines[i].second]);

		std::get<0>(mPLines[i]) = &(mPVertices[lines[i].first]);
		std::get<1>(mPLines[i]) = &(mPVertices[lines[i].second]);
	}

	for (size_t j = 0; j < planes.size(); j++)
	{
		std::get<0>(mPlanes[j]) = &(mVertices[std::get<0>(planes[j])]);
		std::get<1>(mPlanes[j]) = &(mVertices[std::get<1>(planes[j])]);
		std::get<2>(mPlanes[j]) = &(mVertices[std::get<2>(planes[j])]);
	}

}


void Shape::transform(TMatrix matriceTrans)
{
	for (Vertex v : mVertices) {
		v = v * (matriceTrans);
		v.divideByH();
	}
}

void Shape::
normalize(TMatrix  matriceNorm)
{
	std::vector<Vertex>::iterator it1 = mVertices.begin();
	std::vector<Vertex>::iterator it2 = mPVertices.begin();

	while (it1 != mVertices.end() && it2 != mPVertices.end()) {

		*it1 = *it2 * matriceNorm;
		//make sure H is 1
		it1->divideByH();
		//project onto z=-1  plane
		it1->divideByZ();

		it1++;
		it2++;
	}
}

Shape::~Shape()
{
}
