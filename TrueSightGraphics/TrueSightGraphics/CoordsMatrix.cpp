#include "CoordsMatrix.h"



CoordsMatrix::CoordsMatrix()
	:mCoords{ 0,0,0,1 }
{

}
CoordsMatrix::CoordsMatrix(float x, float y, float z, float h)
	:mCoords{ x,y,z,h }
{

}

void CoordsMatrix::afficher()
{
	for (size_t j = 0; j < 4; j++)
	{
		std::cout << mCoords[j];
		std::cout << "\t";

	}
}

CoordsMatrix CoordsMatrix::operator*(TMatrix matrix)
{
	CoordsMatrix temp = CoordsMatrix(0, 0, 0, 0);
	float *tempStart = temp.mCoords;
	float *matAStart = mCoords;
	float *matBStart = &matrix.mValues[0];

	*tempStart = (*matAStart)*(*matBStart) + (*(matAStart + 1)*(*(matBStart + 4))) + (*(matAStart + 2))*(*(matBStart + 8)) + (*(matAStart + 3))*(*(matBStart + 12));
	*(tempStart + 1) = (*matAStart)*(*(matBStart + 1)) + (*(matAStart + 1)*(*(matBStart + 5))) + (*(matAStart + 2))*(*(matBStart + 9)) + (*(matAStart + 3))*(*(matBStart + 13));
	*(tempStart + 2) = (*matAStart)*(*(matBStart + 2)) + (*(matAStart + 1)*(*(matBStart + 6))) + (*(matAStart + 2))*(*(matBStart + 10)) + (*(matAStart + 3))*(*(matBStart + 14));
	*(tempStart + 3) = (*matAStart)*(*(matBStart + 3)) + (*(matAStart + 1)*(*(matBStart + 7))) + (*(matAStart + 2))*(*(matBStart + 11)) + (*(matAStart + 3))*(*(matBStart + 15));

	return temp;
}

void CoordsMatrix::divideByH()
{
	float *matStart = mCoords;
	*matStart /= *(matStart + 3);
	*(matStart + 1) /= *(matStart + 3);
	*(matStart + 2) /= *(matStart + 3);
}

float * CoordsMatrix::getCoords()
{
	return mCoords;
}



