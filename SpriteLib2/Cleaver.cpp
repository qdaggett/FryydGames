#include "Cleaver.h"

Cleaver::Cleaver(int x, int y, int newS, int h, Sprite newM)
	: Monster(x, y, newS, h, newM)
{
	setD(true);
}



void Cleaver::move(int backLimit, int frontLimit, int &thecounter)
{
	float posx = getX();
	float posy = getY();
	if (getD() == true)
	{
		monster.set_flipped(true);
		monster.set_animation("walk");
		setX(posx -= getSpeed());
		thecounter -= getSpeed();
		monster.set_position(posx, posy);

		if (thecounter <= backLimit)
		{
			setD(false);
		}
	}
	else if (getD() == false)
	{
		monster.set_flipped(false);
		monster.set_animation("walk");
		setX(posx += getSpeed());
		thecounter += getSpeed();
		monster.set_position(posx, posy);

		if (thecounter >= frontLimit)
		{
			setD(true);
		}
	}
}