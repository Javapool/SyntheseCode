#include "CoordsMatrix.h"



CoordsMatrix::CoordsMatrix(float x, float y, float z, float h)
	:mCoords{ x,y,z,h }
{

}

void CoordsMatrix::operator*(TMatrix &matrix)
{
	float *temp = mCoords;
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			*temp += (mCoords[i] * matrix.mValues[j * 4 + i]);
		}
		temp++;
	}
	*mCoords = *temp;
}

