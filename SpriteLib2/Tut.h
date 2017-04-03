#pragma once

#include "spritelib/spritelib.h"
#include <fstream>
#include <streambuf>
#include <vector>
#include <iostream>
#include "Monster.h"
#include "Meat.h"
#include "Dairy.h"
#include "Player.h"
#include "FHazard.h"
#include "Launcher.h"

using namespace spritelib;


class Tut
{
public:
	Tut(Sprite floor, Sprite background, Sprite platform); //initializes all the sprites and positions?
	~Tut(); //deletes stuff

	void scrollLeft(int sVal); //this makes all the images scroll as per the parameters

	void scrollRight(int sVal);

	void Draw();

	void RunLevel(float phealth, bool W1, bool W2, int W1H, int W2H, Player *thePlayer);

	void setBackground(float x, float y);

	void UI(float phealth, bool W1, bool W2, int W1H, int W2H);

	void giveRefill(Player *thePlayer);

	float getBScale();

	float getBX();

	float getBY();

	float getPX();

	float getPY();

	bool getR();//get refill

	bool getL();//get leave

	Sprite getPlat();

	float getBackgroundX();

	float getBackgroundScale();

private:
	Sprite tfloor, dummy1, dummy2, tplatform, tbackground, tshift, tarrows, tspace, dred, dred2, refill, rinstruct, exit, infinity, infinity2, theUI;
	std::vector<Monster*> enemies;
	bool getRefill = false;
	bool leave = false;
};