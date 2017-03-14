#include "Monster.h"

#include <iostream>

using namespace std;

Monster::Monster(float newX, float newY, int newS, int h, Sprite newM)
{
	monster = newM;
	x = newX;
	y = newY;
	speed = newS;
	health = h;

}

void Monster::shiftLeft(float shift)
{
	x -= shift;
	monster.set_position(x, y);
}

int Monster::getH()
{
	return health;
}

void Monster::draw()
{
	monster.draw();

}

void Monster::shiftRight(float shift)
{
	x += shift;
	monster.set_position(x, y);
}

void Monster::Collisions(float playerx, float playery, bool &attack, bool weapon, float &phealth)
{
	float distanceBetween;

	float radiuses = 60.0f;
	float attackR = 90.0f;

	//the formula
	distanceBetween = sqrt(pow(y - playery, 2) + pow(x - playerx, 2));

	if (attack == true)
	{
		if (distanceBetween < attackR && weapon == true)
		{
			cout << "YOU ATTACKED" << endl;
			health -= 10;
			attack = false;
		}
	}
	if (distanceBetween < radiuses)
	{
		if (phealth > 0)
			phealth -= 1.0f;
	}
}
