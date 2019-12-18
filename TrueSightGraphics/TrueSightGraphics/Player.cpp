#include "Player.h"

void Player::move()
{
	float angleRad = (mAngle/180)*M_PI;
	mZ += mZSpeed*(-(cos(angleRad)));
	mZ += mXSpeed * (-(sin(angleRad)));
	mX += mXSpeed*(cos(angleRad));
	mX += mZSpeed * (-sin(angleRad));
	mY += mYSpeed;
}

void Player::accelerateLeft()
{

	mXSpeed -= ACCELERATION; 
	mXSpeed = std::clamp(mXSpeed, MIN_SPEED, MAX_SPEED);

}

void Player::accelerateRight()
{
	mXSpeed += ACCELERATION;
	mXSpeed = std::clamp(mXSpeed, MIN_SPEED, MAX_SPEED);
}

void Player::accelerateForward()
{
	mZSpeed += ACCELERATION;
	mZSpeed = std::clamp(mZSpeed, MIN_SPEED, MAX_SPEED);
}

void Player::accelerateBackwards()
{
	mZSpeed -= ACCELERATION;
	mZSpeed = std::clamp(mZSpeed, MIN_SPEED, MAX_SPEED);
}

void Player::accelerateUp()
{
	mYSpeed += ACCELERATION;
	mYSpeed = std::clamp(mYSpeed, MIN_SPEED, MAX_SPEED);
}

void Player::accelerateDown()
{
	mYSpeed -= ACCELERATION;
	mYSpeed = std::clamp(mYSpeed, MIN_SPEED, MAX_SPEED);
}

void Player::decelerateLeft()
{
	if (mXSpeed < 0)
	{
		mXSpeed += ACCELERATION;

	}
}

void Player::decelerateRight()
{
	if (mXSpeed > 0)
	{
		mXSpeed -= ACCELERATION;

	}
}

void Player::decelerateForward()
{
	if (mZSpeed > 0)
	{
		mZSpeed -= ACCELERATION;

	}

}

void Player::decelerateBackwards()
{
	if (mZSpeed < 0)
	{
		mZSpeed += ACCELERATION;

	}
}

void Player::decelerateUp()
{
	if (mYSpeed > 0)
	{
		mYSpeed -= ACCELERATION;

	}
}

void Player::decelerateDown()
{
	if (mYSpeed < 0)
	{
		mYSpeed += ACCELERATION;

	}
}



void Player::turnY(float angle)
{
	mAngle += angle;
}
