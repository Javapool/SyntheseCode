#pragma once
#include <math.h>
#include <algorithm>
#define M_PI 3.14159265
class Player
{

private:
	const float ACCELERATION{ 0.0001f };
	const float MAX_SPEED{0.1f};
	const float MIN_SPEED{-MAX_SPEED};

	friend class MatrixCreator;

	static Player *instance;
	float mX{0};
	float mY{0};
	float mZ{0};


	float mXSpeed{0};
	float mYSpeed{0};
	float mZSpeed{0};
	float mAngle{0};

public:

	enum DIRECTION
	{
		FORWARD,
		LEFT,
		BACK,
		RIGHT,
		UP,
		DOWN
	};
	Player() = default;
	~Player() = default;

	static Player* getInstance()
	{
		if (instance == nullptr) {
			instance = new Player;
		}
		return instance;
	}

	void move();

	void accelerateLeft();
	void accelerateRight();
	void accelerateForward();
	void accelerateBackwards();
	void accelerateUp();
	void accelerateDown();
	void decelerateLeft();
	void decelerateRight();
	void decelerateForward();
	void decelerateBackwards();
	void decelerateUp();
	void decelerateDown();
	void turnY(float angle);


};

