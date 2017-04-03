#pragma once
#include "spritelib/spritelib.h"

using namespace spritelib;
class Monster
{
public:
	Monster(float newX, float newY, int newS, int h, Sprite newM);

	void shiftRight(float shift);

	void shiftLeft(float shift);

	virtual void move(int backLimit, int frontLimit, int &thecounter) = 0;

	void draw();

	void nextFrame();

	virtual void Collisions(float playerx, float playery, bool &attack, bool weapon, float &phealth);

	//for the tutorial
	void dummyCollisions(float playerx, float playery, bool &attack, bool weapon, Sprite &dummy);

	//All the getters
	bool getD();

	int getHealth();

	float getX();

	float getY();
	
	int getSpeed();

	//The setters

	void setD(bool newD);

	void setHealth(int newH);

	void setX(int newX);

	void setY(int newY);

	void setSpeed(int newS);

	void pause();

protected:
	
	Sprite monster;
private:

	float x, y;
	bool direction = true;
	int speed;
	int health;
};