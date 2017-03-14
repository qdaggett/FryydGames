#include "Meat.h"

Meat::Meat(int x, int y, int newS, int h, Sprite newM)
	: Monster(x, y, newS, h, newM)
{

}

void Meat::move(int backLimit, int frontLimit, int &thecounter)
{
	if (direction == true)
	{
		x -= speed;
		thecounter -= speed;
		monster.set_position(x, y);

		if (thecounter <= backLimit)
		{
			direction = false;
		}
	}
	else if (direction == false)
	{
		x += speed;
		thecounter += speed;
		monster.set_position(x, y);

		if (thecounter >= frontLimit)
		{
			direction = true;
		}
	}


}

void Meat::Update(int backLimit, int frontLimit, int &thecounter)
{

	monster.draw();
	move(backLimit, frontLimit, thecounter);
}
