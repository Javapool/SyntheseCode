#include "Vertex.h"
#include "TMatrix.h"





Vertex::Vertex(float x, float y, float z, float h)
	:mCoords{ x,y,z, h}
{
}

Vertex::~Vertex()
{
}

float *Vertex::getCoords()
{
	return &mCoords[0];
}

void Vertex::afficher()
{
	std::cout << "\n";
	for (size_t j = 0; j < 4; j++)
	{

		
		std::cout << mCoords[j];
		std::cout << "\t";

	}
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";

}

Vertex Vertex::operator*(TMatrix &right)
{
	Vertex temp = Vertex(0, 0, 0, 0);
	float *tempStart = temp.mCoords;
	float *matAStart = mCoords;
	float *matBStart = &right.mValues[0];

	*tempStart = (*matAStart)*(*matBStart) + (*(matAStart + 1)*(*(matBStart + 4))) + (*(matAStart + 2))*(*(matBStart + 8)) + (*(matAStart + 3))*(*(matBStart + 12));
	*(tempStart + 1) = (*matAStart)*(*(matBStart + 1)) + (*(matAStart + 1)*(*(matBStart + 5))) + (*(matAStart + 2))*(*(matBStart + 9)) + (*(matAStart + 3))*(*(matBStart + 13));
	*(tempStart + 2) = (*matAStart)*(*(matBStart + 2)) + (*(matAStart + 1)*(*(matBStart + 6))) + (*(matAStart + 2))*(*(matBStart + 10)) + (*(matAStart + 3))*(*(matBStart + 14));
	*(tempStart + 3) = (*matAStart)*(*(matBStart + 3)) + (*(matAStart + 1)*(*(matBStart + 7))) + (*(matAStart + 2))*(*(matBStart + 11)) + (*(matAStart + 3))*(*(matBStart + 15));
	divideByH();
	return temp;
}

Vertex& Vertex::operator+=(Vertex &right)
{
	this->mCoords[0] += right.mCoords[0];
	this->mCoords[1] += right.mCoords[1];
	this->mCoords[2] += right.mCoords[2];
	this->mCoords[3] += right.mCoords[3];
	return *this;
}


void Vertex::divideByH()
{
	float *matStart = mCoords;
	float &xCoord = *matStart;
	float &yCoord = *(matStart + 1);
	float &hCoord = *(matStart + 3);
	 

	if (hCoord <= 0) {

		if (hCoord < -1) {
			hCoord = -1 / hCoord;
		}
		else {
			hCoord = -hCoord;
		}
	}

	*matStart /= hCoord;
	*(matStart + 1) /= hCoord;
	//*(matStart + 2) /= *(matStart + 3);
	*(matStart + 3) = 1;

}
//
//void Vertex::divideByZ()
//{
//	float *matStart = mCoords;
//	*matStart /= (*(matStart + 2));
//	*(matStart + 1) /= (*(matStart + 2));
//}


