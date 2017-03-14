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

	//virtual void Update() = 0;

	void Collisions(float playerx, float playery, bool &attack, bool weapon, float &phealth);

	int getH();

protected:
	float x, y;
	bool direction = true;
	int speed;
	int health;
	Sprite monster;
private:
};