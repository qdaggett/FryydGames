#pragma once
#include "Monster.h"

class Boss : public Monster
{
public:
	Boss(float newX, float newY, int h, Sprite newM, int newS);

	void Collisions(float playerx, float playery, bool &attack, float &phealth);

	void move(int backLimit, int frontLimit, int &thecounter);


private:
	

};