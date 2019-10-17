#include "CoordsMatrix.h"



CoordsMatrix::CoordsMatrix(float x, float y, float z, float h)
	:mCoords{ x,y,z,h }
{

}

void CoordsMatrix::operator*(TMatrix &matrix)
{
	std::array<float, 4> temp = mCoords;
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			temp[i] += (mCoords[i] * matrix.mValues[j * 4 + i]);
		}
	}
	mCoords = temp;
}

