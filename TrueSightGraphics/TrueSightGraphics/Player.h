#pragma once
class Player
{
private:

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

	Player() = default;
	~Player() = default;

	static Player* getInstance()
	{
		if (instance == nullptr) {
			instance = new Player;
		}
		return instance;
	}


};

