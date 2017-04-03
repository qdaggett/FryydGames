#pragma once
#include "Monster.h"

class  Dairy : public Monster
{
public:
	Dairy(int x, int y, int newS, int h, Sprite newM);

	void move(int backLimit, int frontLimit, int &thecounter);

	
private:
	
};