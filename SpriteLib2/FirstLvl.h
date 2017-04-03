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

class FirstLvl
{
public:

	FirstLvl(Sprite b, Sprite p, Sprite e, Sprite e2, Sprite plat, Sprite floor, Sprite UI, Sprite dead, Sprite fall, Sprite k);

	~FirstLvl();

	void IterativeSelectionSort(std::vector<Sprite*>& a_sprites);

	void Restart(); //this is to restart the level 

	void scrollLeft(int sVal); //this makes all the images scroll as per the parameters

	void scrollRight(int sVal);

	void UI(float phealth, bool W1, bool W2, int W1H, int W2H); //prints out the UI

	void Update(); //Typically for updating animations

	void Draw(); //For drawing elements in the level

	void RunLevel(float &phealth, bool W1, bool W2, int W1H, int W2H, Player *thePlayer); //This runs all the necessary functions for the level

	void Pitfall(Sprite fall, Player *thePlayer, float length); //this is for the pitfalls in the level

	void setP(bool temp); //these are some setters and getters--for calculations about the level

	float getBX();

	float getBY();

	float getPX();

	float getPY();

	float getPX2();

	float getPY2();

	float getPX3();

	float getPY3();

	float getPX4();

	float getPY4();

	float getPX5();

	float getPY5();

	float getPX6();

	float getPY6();

	float getPX7();

	float getPY7();

	float getC1X();

	float getC1Y();

	float getC2X();
	
	float getC2Y();

	float getC3X(); //third column

	float getC3Y();

	float getC4X(); //fourth column

	float getC4Y();

	float getC5X(); //fifth column

	float getC5Y();

	float getC6X(); // sixth column

	float getC6Y();

	float getC7X(); // sixth column

	float getC7Y();

	float getRPX1(); //the refill platforms

	float getRPY1();

	float getRPX2();

	float getRPY2();

	bool getP() const;

	bool getLeave() const;

	bool getGoal() const;

	Sprite getPlat(); //this gets some of the sprites for, again, external calculations //namely collisions

	Sprite getPlat2();

	Sprite getPlat3();

	Sprite getPlat4();

	Sprite getPlat5();

	Sprite getPlat6();

	Sprite getPlat7();

	Sprite getFall();

	Sprite getFall2();

	Sprite getFall3();

	Sprite getC1(); //getting the sprites for columns

	Sprite getC2();

	Sprite getC3();

	Sprite getC4();

	Sprite getC5();

	Sprite getC6();

	Sprite getC7();

	Sprite getRP1(); //getting the sprites for the refill platforms

	Sprite getRP2();

private:

	//int counter = 600, counter2 = 2100, counter3 = 2800, counter4 = 5600, counter5 = 6200;
	int counter = 600, counter2 = 2100, counter3 = 3200, counter4 = 6100, counter5 = 6600;
	//	int mcounter = 3040, mcounter2 = 1400, mcounter3 = 8900;
	int mcounter = 3440, mcounter2 = 1400, mcounter3 = 9100;
	int cheese = 1, meat = 1, cheese2 = 1, cheese3 = 1, meat2 = 1;
	int life = 1;
	bool pause = false;
	bool leave = false;
	bool goalReached = false;
	std::vector<Sprite*> spritesToDraw;
	std::vector<Monster*> enemies;
	std::vector<FHazard*> hazard;
	std::vector<Launcher*> mLaunch;

	Sprite fbackground, fplatform, ftheFloor, ftheUI, fenemy, fenemy2, fdead, fpit, knives, fenemy3, fplatform2, fplatform3, pauseIcon, theLauncher, theMeatBall
		, column1, column2, fpit2, fplatform4, fplatform5, fplatform6, fplatform7, column3, column4, column5, column6, fpit3, column7, rplat1, rplat2, refill, exit;
};