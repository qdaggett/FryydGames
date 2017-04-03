#include "Boss.h"

Boss::Boss(float newX, float newY, int h, Sprite newM, int newS)
	: Monster(newX, newY, newS, h, newM)
{

}

void Boss::Collisions(float playerx, float playery, bool &attack, float &phealth)
{
	float distanceBetween;

	float radiuses = 60.0f;
	float attackR = 90.0f;

	float posx = getX();
	float posy = getY();

	//the formula
	distanceBetween = sqrt(pow(posy - playery, 2) + pow(posx - playerx, 2));

	if (attack == true && getD() == true)
	{
		if (distanceBetween < attackR)
		{
			int theHealth = getHealth();
			setHealth((theHealth -= 10));
			attack = false;
		}
	}
	if (distanceBetween < radiuses)
	{
		//if (phealth > 0)
			//phealth -= 5.0f;
	}
}

void Boss::move(int backLimit, int frontLimit, int & thecounter)
{
}
