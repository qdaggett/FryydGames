#pragma once
#include "spritelib/spritelib.h"
#include "Monster.h"

using namespace spritelib;

class Player
{
public:
	Player(Sprite newPlayer, float newX, float newY);

	void setX(float newX);

	void setY(float newY);

	void setW1(bool temp);

	void setW2(bool temp);

	void setW1H(int temp);

	void setW2H(int temp);

	void subW1();

	void subW2();

	void setA(bool temp);

	void setH(float newH);

	void setFlipped(bool temp);

	void setAnimation(std::string animation);

	float getX();

	float getY();

	float getH();

	bool getW1();

	bool getW2();

	bool getA();

	int getW1H();

	int getW2H();

	void draw();

	void nextFrame();

	//i should get rid of this
	friend void Monster::Collisions(float playerx, float playery, bool &attack, bool weapon, float &phealth);

private:
	Sprite player;
	float x, y;
	float health;
	bool weapon1 = true, weapon2 = false, attack = false;
	int weapon1H = 10;
	int weapon2H = 10;

};