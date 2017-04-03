#include "Monster.h"

#include <iostream>

using namespace std;

Monster::Monster(float newX, float newY, int newS, int h, Sprite newM)
{
	monster = newM;
	x = newX;
	y = newY;
	try
	{
		speed = newS;
		health = h;

		if (speed < 0 || health < 0)
		{
			throw 1;
		}
		
	}
	catch (...)
	{
		std::cout << "Monster Err: Negative Values" << std::endl;
	}
	

}

void Monster::nextFrame()
{
	monster.next_frame();
}

void Monster::shiftLeft(float shift)
{
	//this is for when the level is scrolling
	x -= shift;
	monster.set_position(x,y);
}

void Monster::draw()
{
	monster.draw();
	
}

void Monster::shiftRight(float shift)
{
	//this is for the level scrolling
	x += shift;
	monster.set_position(x, y);
}

void Monster::Collisions(float playerx, float playery, bool &attack, bool weapon, float &phealth)
{
	//using the formula it gets the distance between and does different things with it
	float distanceBetween;

	float radiuses = 60.0f;
	float attackR = 100.0f;

	//the formula
	distanceBetween = sqrt(pow(y - playery, 2) + pow(x - playerx, 2));

	if (attack == true)
	{
		if (distanceBetween < attackR && weapon == true)
		{
			health -= 10;
			attack = false;
		}
	}
	if (distanceBetween < radiuses)
	{
		if (phealth > 0)
		phealth -= 1.0f;
	}
}

void Monster::dummyCollisions(float playerx, float playery, bool &attack, bool weapon, Sprite &dummy)
{
	//using the formula it gets the distance between and does different things with it
	float distanceBetween;

	float radiuses = 60.0f;
	float attackR = 100.0f;

	//the formula
	distanceBetween = sqrt(pow(y - playery, 2) + pow(x - playerx, 2));

	if (attack == true)
	{
		if (distanceBetween < attackR && weapon == true)
		{
			dummy.set_position(getX(), getY());
			dummy.draw();
			//dummy.set_animation(animation);
			//dummy.set_animation(animation);
			//dummy.next_frame();
			
			/*if (dummy.get_current_frame() == 3)
			{
				dummy.set_animation("idle");
			}*/
			attack = false;
		}
		if (distanceBetween < attackR && weapon == false)
		{
			Text::set_color(0.0f, 0.0f, 1.0f);
			Text::draw_string("Wrong weapon!", "TEMP", playerx, playery + 120);
		}
	}
	if (distanceBetween < radiuses)
	{
		Text::set_color(1.0f, 0.0f, 0.0f);
		Text::draw_string("OWWW", "TEMP", playerx, playery + 100);
	}
}

//the setters
void Monster::setD(bool newD)
{
	direction = newD;
}

void Monster::setHealth(int newH)
{
	health = newH;
}

void Monster::setX(int newX)
{
	x = newX;
}

void Monster::setY(int newY)
{
	y = newY;
}

void Monster::setSpeed(int newS)
{
	speed = newS;
}

//the getters
int Monster::getHealth()
{
	return health;
}

bool Monster::getD()
{
	return direction;
}

float Monster::getX()
{
	return x;
}

float Monster::getY()
{
	return y;
}

int Monster::getSpeed()
{
	return speed;
}

void Monster::pause()
{
	if (direction == true)
	{
		monster.set_flipped(true);
		monster.set_animation("idle");
	}

	else if (direction == false)
	{
		monster.set_flipped(false);
		monster.set_animation("idle");
	}
}