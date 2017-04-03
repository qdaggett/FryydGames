#include "Player.h"

Player::Player(Sprite newPlayer, float newX, float newY)
{
	player = newPlayer;
	x = newX;
	y = newY;
	health = 100;
}

void Player::setX(float newX)
{
	x = newX;
	player.set_position(x, y);
}

void Player::setY(float newY)
{
	y = newY;
	player.set_position(x, y);
}

void Player::setW1(bool temp)
{
	weapon1 = temp;
}

void Player::setW2(bool temp)
{
	weapon2 = temp;
}

void Player::setW1H(int temp)
{
	weapon1H = temp;
}

void Player::setW2H(int temp)
{
	weapon2H = temp;
}

void Player::subW1()
{
	weapon1H--;
}

void Player::subW2()
{
	weapon2H--;
}

void Player::setA(bool temp)
{
	attack = temp;
}

void Player::setH(float newH)
{
	health = newH;
}

void Player::setFlipped(bool temp)
{
	player.set_flipped(temp);
}

void Player::setAnimation(std::string animation)
{
	player.set_animation(animation);
}

float Player::getX()
{
	return x;
}

float Player::getY()
{
	return y;
}

float Player::getH()
{
	return health;
}

bool Player::getW1()
{
	return weapon1;
}

bool Player::getW2()
{
	return weapon2;
}

bool Player::getA()
{
	return attack;
}

int Player::getW1H()
{
	return weapon1H;
}

int Player::getW2H()
{
	return weapon2H;
}

void Player::draw()
{
	player.draw();
}

void Player::nextFrame()
{
	player.next_frame();
}