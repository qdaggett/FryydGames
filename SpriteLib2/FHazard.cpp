#include "FHazard.h"
#include <iostream>
FHazard::FHazard(float newX, float newY, int newS, int h, Sprite newM, float w, float g)
	:Monster(newX, newY, newS, h, newM)
{
	theWidth = w;
	gLvl = g;
}

void FHazard::move(int backLimit, int frontLimit, int &thecounter)
{
	//try to incorporate physics here
	float temp = getY() - 5;
	float xtemp = getX();
	setY(temp);
	monster.set_position(xtemp, temp);

}

void FHazard::Collisions(float playerx, float playery, float &phealth)
{
	float distanceBetween;

	float radiuses = 50.0f;

	//the formula
	distanceBetween = sqrt(pow(getY() - playery, 2) + pow(getX() - playerx, 2));
	if (distanceBetween < radiuses && getHealth() > 0)
	{	
		phealth -= 30;
		setHealth(0);
	}

}

void FHazard::checkTrigger(float playerx, float playery)
{
	if (playerx > monster.get_position().x-60 && playerx < monster.get_position().x + theWidth)
	{
		if (playery >= 50)
		{
			Move = true;
		}
	}
}

bool FHazard::getMove()
{
	return Move;
}

void FHazard::setMove(bool temp)
{
	Move = temp;
}

void FHazard::reset(float x, float y)
{
	setX(x);
	setY(y);
	monster.set_position(x, y);
}