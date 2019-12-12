#include "TMatrix.h"
#include <math.h>
#include <conio.h>
#include <iostream>
#include <iomanip>



TMatrix::TMatrix()
{
}

TMatrix::TMatrix(squareMatrix values)
	:mValues{ values }
{
}


TMatrix::~TMatrix()
{
}

void TMatrix::afficher()
{
	std::cout << std::fixed;
	std::cout << std::setprecision(2);
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			std::cout << mValues[4 * i + j];
			std::cout << "\t\t";


		}
		std::cout << "\n";
		std::cout << "\n";
	}
	std::cout << "\n";
	std::cout << "\n";
}


//void TMatrix::symmetrize()
//{
//	squareMatrix temp;
//	squareMatrix *listPointer = &mValues;
//	squareMatrix *readPointer = listPointer;
//	squareMatrix *tempPointer = &temp;
//	squareMatrix *writePointer = tempPointer;
//
//	for (size_t i = 0; i < 4; i++)
//	{
//		writePointer = tempPointer + i;
//		for (size_t j = 0; j < 4; j++)
//		{
//			*writePointer = *readPointer;
//			writePointer += 4;
//			readPointer++;
//
//		}
//
//	}
//
//	mValues = temp;
//}

TMatrix TMatrix::operator*(TMatrix const &matrix)
{
	TMatrix temp = TMatrix();
	float *tempStart = &temp.mValues[0];
	float *matAStart = &mValues[0];
	const float *matBStart = &matrix.mValues[0];

	//firstLine
	*tempStart =		(*matAStart)*(*matBStart) + (*(matAStart + 1)*(*(matBStart + 4))) + (*(matAStart + 2))*(*(matBStart + 8)) + (*(matAStart + 3))*(*(matBStart + 12));
	*(tempStart + 1) = (*matAStart)*(*(matBStart + 1)) + (*(matAStart + 1)*(*(matBStart + 5))) + (*(matAStart + 2))*(*(matBStart + 9)) + (*(matAStart + 3))*(*(matBStart + 13));
	*(tempStart + 2) = (*matAStart)*(*(matBStart + 2)) + (*(matAStart + 1)*(*(matBStart + 6))) + (*(matAStart + 2))*(*(matBStart + 10)) + (*(matAStart + 3))*(*(matBStart + 14));
	*(tempStart + 3) = (*matAStart)*(*(matBStart + 3)) + (*(matAStart + 1)*(*(matBStart + 7))) + (*(matAStart + 2))*(*(matBStart + 11)) + (*(matAStart + 3))*(*(matBStart + 15));

	//Nextline
	*(tempStart + 4) =	(*(matAStart+4))*(*matBStart) +		(*(matAStart + 5)*(*(matBStart + 4))) + (*(matAStart + 6))*(*(matBStart + 8)) +		(*(matAStart + 7))*(*(matBStart + 12));
	*(tempStart + 5) =	(*(matAStart+4))*(*(matBStart + 1)) + (*(matAStart + 5)*(*(matBStart + 5))) + (*(matAStart + 6))*(*(matBStart + 9)) +		(*(matAStart + 7))*(*(matBStart + 13));
	*(tempStart + 6) =	(*(matAStart+4))*(*(matBStart + 2)) + (*(matAStart + 5)*(*(matBStart + 6))) + (*(matAStart + 6))*(*(matBStart + 10)) +	(*(matAStart + 7))*(*(matBStart + 14));
	*(tempStart + 7) =	(*(matAStart+4))*(*(matBStart + 3)) + (*(matAStart + 5)*(*(matBStart + 7))) + (*(matAStart + 6))*(*(matBStart + 11)) +	(*(matAStart + 7))*(*(matBStart + 15));

	*(tempStart + 8) =	(*(matAStart+8))*(*matBStart) +		(*(matAStart + 9)*(*(matBStart + 4))) + (*(matAStart + 10))*(*(matBStart + 8)) +	(*(matAStart + 11))*(*(matBStart + 12));
	*(tempStart + 9) =	(*(matAStart+8))*(*(matBStart + 1)) +	(*(matAStart + 9)*(*(matBStart + 5))) + (*(matAStart + 10))*(*(matBStart + 9)) +	(*(matAStart + 11))*(*(matBStart + 13));
	*(tempStart + 10) = (*(matAStart+8))*(*(matBStart + 2)) +	(*(matAStart + 9)*(*(matBStart + 6))) + (*(matAStart + 10))*(*(matBStart + 10)) +	(*(matAStart + 11))*(*(matBStart + 14));
	*(tempStart + 11) = (*(matAStart+8))*(*(matBStart + 3)) +	(*(matAStart + 9)*(*(matBStart + 7))) + (*(matAStart + 10))*(*(matBStart + 11)) +	(*(matAStart + 11))*(*(matBStart + 15));

	*(tempStart + 12) = (*(matAStart+12))*(*matBStart) +			(*(matAStart + 13)*(*(matBStart + 4))) + (*(matAStart + 14))*(*(matBStart + 8)) +	(*(matAStart + 15))*(*(matBStart + 12));
	*(tempStart + 13) = (*(matAStart+12))*(*(matBStart + 1)) +	(*(matAStart + 13)*(*(matBStart + 5))) + (*(matAStart + 14))*(*(matBStart + 9)) +	(*(matAStart + 15))*(*(matBStart + 13));
	*(tempStart + 14) = (*(matAStart+12))*(*(matBStart + 2)) +	(*(matAStart + 13)*(*(matBStart + 6))) + (*(matAStart + 14))*(*(matBStart + 10)) +	(*(matAStart + 15))*(*(matBStart + 14));
	*(tempStart + 15) = (*(matAStart+12))*(*(matBStart + 3)) +	(*(matAStart + 13)*(*(matBStart + 7))) + (*(matAStart + 14))*(*(matBStart + 11)) +	(*(matAStart + 15))*(*(matBStart + 15));

	return temp;
}

Vertex TMatrix::operator*(Vertex const &matrix)
{
	Vertex temp = Vertex(0, 0, 0, 0);
	float *tempStart = &temp.mCoords[0];
	const float *matAStart = &matrix.mCoords[0];
	float *matBStart = &mValues[0];

	*tempStart = (*matAStart)*(*matBStart) + (*(matAStart + 1)*(*(matBStart + 4))) + (*(matAStart + 2))*(*(matBStart + 8)) + (*(matAStart + 3))*(*(matBStart + 12));
	*(tempStart + 1) = (*matAStart)*(*(matBStart + 1)) + (*(matAStart + 1)*(*(matBStart + 5))) + (*(matAStart + 2))*(*(matBStart + 9)) + (*(matAStart + 3))*(*(matBStart + 13));
	*(tempStart + 2) = (*matAStart)*(*(matBStart + 2)) + (*(matAStart + 1)*(*(matBStart + 6))) + (*(matAStart + 2))*(*(matBStart + 10)) + (*(matAStart + 3))*(*(matBStart + 14));
	*(tempStart + 3) = (*matAStart)*(*(matBStart + 3)) + (*(matAStart + 1)*(*(matBStart + 7))) + (*(matAStart + 2))*(*(matBStart + 11)) + (*(matAStart + 3))*(*(matBStart + 15));

	return temp;
}

