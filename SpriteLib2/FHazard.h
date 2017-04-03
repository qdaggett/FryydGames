#pragma once
#include "Monster.h"

class FHazard : public Monster
{
public:
	FHazard(float newX, float newY, int newS, int h, Sprite newM, float w, float g);

	void Collisions(float playerx, float playery, float &phealth);

	void move(int backLimit, int frontLimit, int &thecounter);

	void checkTrigger(float playerx, float playery);

	//the getters
	bool getMove();

	//the setters
	void setMove(bool temp);

	void reset(float x, float y);

private:
	float theWidth;
	float gLvl;
	bool Move = false;
	
};