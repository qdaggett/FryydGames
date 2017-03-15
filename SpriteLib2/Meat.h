#pragma once
#include "Monster.h"

class  Meat : public Monster
{
public:
	Meat(int x, int y, int newS, int h, Sprite newM);

	void move(int backLimit, int frontLimit, int &thecounter);

};

