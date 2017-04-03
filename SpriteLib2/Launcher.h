#pragma once

#include "Monster.h"

class Launcher : public Monster
{
public:
	Launcher(float newX, float newY, int newS, int h, Sprite newM, Sprite newSta, float newX2, float newY2);

	void statDraw(); //stationary draw

	void moveLeft(float temp);

	void moveRight(float temp);

	void move(int backLimit, int frontLimit, int &thecounter);

	void vmove(int backLimit, int frontLimint, int &thecounter, bool &temp);

	void Collisions(float playerx, float playery, float &phealth);

	void vCollisions(float playerx, float playery, bool &attack, bool weapon, float &phealth, int &counter, bool &blaunch, int &mcounter);

	void lReset(float x, float y);

	void pReset(float x, float y);

private:
	//the variables needed for the stationary object
	Sprite stationary;
	float sX;
	float sY;
	float width;


};