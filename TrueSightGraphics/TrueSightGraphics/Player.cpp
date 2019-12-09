#include "Player.h"



Player::Player()
	:mXSpeed{ 0 }, mYSpeed{ 0 }, mZSpeed{ 0 }, mAngle{0}
{

}

float * Player::getCoords()
{
	return mCoords.getCoords();
}

Player::~Player()
{
}
