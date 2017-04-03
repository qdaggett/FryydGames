#include "Launcher.h"
#include <iostream>

Launcher::Launcher(float newX, float newY, int newS, int h, Sprite newM, Sprite newSta, float newX2, float newY2)
	:Monster(newX, newY, newS, h, newM)
{
	stationary = newSta;
	stationary.set_position(newX2, newY2);
}

void Launcher::statDraw()
{
	stationary.draw();
}

void Launcher::moveLeft(float temp)
{
	float tempy = stationary.get_position().y;
	float tempx = (stationary.get_position().x);
	stationary.set_position(tempx -= temp, tempy);
}

void Launcher::moveRight(float temp)
{
	float tempy = stationary.get_position().y;
	float tempx = (stationary.get_position().x);
	stationary.set_position(tempx += temp, tempy);
}

void Launcher::move(int backLimit, int frontLimit, int & thecounter)
{
	float posx = getX();
	float posy = getY();

	setX(posx -= getSpeed());
	thecounter -= getSpeed();
	
	monster.set_position(posx, posy);

	if (thecounter <= backLimit)
	{
		setX(posx += (frontLimit - backLimit));
		thecounter += (frontLimit - backLimit);
	}

}

void Launcher::vmove(int backLimit, int frontLimit, int & thecounter, bool &temp)
{
	float posx = getX();
	float posy = getY();

	setY(posy -= getSpeed());
	thecounter -= getSpeed();

	monster.set_position(posx, posy);

	if (thecounter <= frontLimit)
	{
		setY(posy += (backLimit - frontLimit));
		thecounter += (backLimit - frontLimit);
		temp = false;
	}

}

void Launcher::Collisions(float playerx, float playery, float & phealth)
{
	float distanceBetween;
	float radiuses = 50.0f;

	//the formula
	distanceBetween = sqrt(pow(getY() - playery, 2) + pow(getX() - playerx, 2));

	if (distanceBetween < radiuses)
	{
		phealth -= 2;
	}
}

void Launcher::vCollisions(float playerx, float playery, bool &attack, bool weapon, float &phealth, int &counter, bool &blaunch, int& mcounter)
{
	//using the formula it gets the distance between and does different things with it
	float distanceBetween;

	float radiuses = 60.0f;
	float attackR = 110.0f;

	//the formula
	distanceBetween = sqrt(pow(getY() - playery, 2) + pow(getX() - playerx, 2));

	if (attack == true)
	{
		if (distanceBetween < attackR && weapon == true)
		{
			if (counter > 0) counter--;
			attack = false;
			blaunch = false;

			float tempx = getX();
			pReset(tempx, 380);
			mcounter = 380;
			
		}
	}
	
	if (distanceBetween < radiuses)
	{
		if (phealth > 0)
			phealth -= 7.0f;
		
		blaunch = false;
		float tempx = getX();
		pReset(tempx, 380);
		mcounter = 380;
	}
}

void Launcher::lReset(float x, float y)
{
	stationary.set_position(x, y);

}

void Launcher::pReset(float x, float y)
{
	monster.set_position(x, y);
	setX(x);
	setY(y);
}