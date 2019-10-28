#include "TMatrix.h"
#include <math.h>



TMatrix::TMatrix()
{
}

TMatrix::TMatrix(std::array<float, 16> values)
	:mValues{values}
{
}


TMatrix::~TMatrix()
{
}


void TMatrix::symmetrize()
{
	std::array<float, 16> temp;
	std::array<float, 16> *listPointer = &mValues;
	std::array<float, 16> *readPointer = listPointer;
	std::array<float, 16> *tempPointer = &temp;
	std::array<float, 16> *writePointer = tempPointer;

	for (size_t i = 0; i < 4; i++)
	{
		writePointer = tempPointer + i;
		for (size_t j = 0; j < 4; j++)
		{
			*writePointer = *readPointer;
			writePointer += 4;
			readPointer++;

		}

	}

	mValues = temp;
}

//TMatrix TMatrix::operator*(const TMatrix &matrix)
//{
//	std::array<float, 16> temp = mValues;
//	for (size_t i = 0; i < 4; i++)
//	{
//		for (size_t j = 0; j < 4; j++)
//		{
//			for (size_t k = 0; k < 4; k++)
//			{
//				temp[j*4+i] += (mValues[j * 4 + i]*matrix.mValues[k*4+i]);
//			}
//		}
//	}
//	return NULL;
//
////}
//
//TMatrix TMatrix::operator*(CoordsMatrix *matrix)
//{
//	float temp[4]{ *(matrix->mCoords) };
//	for (size_t i = 0; i < 4; i++)
//	{
//		for (size_t j = 0; j < 4; j++)
//		{
//			temp[i] += (matrix->mCoords[i] * mValues[j*4+i]);
//		}
//	}
//	*(matrix->mCoords) = *temp;
//}
