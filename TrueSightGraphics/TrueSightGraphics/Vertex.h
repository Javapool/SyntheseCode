#pragma once
#include <vector>
#include <iostream>
class TMatrix;

class Vertex
{
	friend class TMatrix;
	float mCoords[4];

public:
	Vertex(float x, float y, float z, float h);
	~Vertex();

	float* getCoords();
	void afficher();
	Vertex operator*(TMatrix &right);
	Vertex& operator+=(Vertex &right);
	void divideByH();
	void divideByZ();
};

