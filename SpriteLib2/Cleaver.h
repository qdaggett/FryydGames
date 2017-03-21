#pragma once

#include "Monster.h"

class Cleaver : public Monster
{
public:
	Cleaver(int x, int y, int newS, int h, Sprite newM);

	void move(int backLimit, int frontLimit, int &thecounter);

private:
};