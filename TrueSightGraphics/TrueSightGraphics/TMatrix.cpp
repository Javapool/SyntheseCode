#include "TMatrix.h"



TMatrix::TMatrix()
{
}


TMatrix::~TMatrix()
{
}

void TMatrix::operator*(const TMatrix &matrix)
{
	std::array<float, 16> temp = mValues;
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			for (size_t k = 0; k < 4; k++)
			{
				temp[j*4+i] += (mValues[j * 4 + i]*matrix.mValues[k*4+i]);
			}
		}
	}
}

void TMatrix::operator*(CoordsMatrix *matrix)
{
	std::array<float, 4> temp = matrix->mCoords;
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			temp[i] += (matrix->mCoords[i] * mValues[j*4+i]);
		}
	}
	matrix->mCoords = temp;
}
