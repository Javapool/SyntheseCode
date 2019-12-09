#pragma once
#include "CoordsMatrix.h"
class Player
{
private:
	static Player *instance;
	CoordsMatrix mCoords;
	float mXSpeed;
	float mYSpeed;
	float mZSpeed;
	float mAngle;
	Player();

public:

	static Player* getInstance()
	{
		if (instance == nullptr) {
			instance = new Player;
		}
		return instance;
	}

	float* getCoords();

	~Player();
};

