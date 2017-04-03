#pragma once
#include "Player.h"
#include "Boss.h"
#include <iostream>
#include "Launcher.h"
#include <random>
#include <ostream>

class BossLvl
{
public:

	BossLvl(Sprite floor, Sprite background, Sprite Gordon);

	void RunLevel(float phealth, bool W1, bool W2, int W1H, int W2H, Player *thePlayer);

	void Draw();

	void UI(float phealth, bool W1, bool W2, int W1H, int W2H);

	void checkRefill(int &WH1, int&WH2, float playerx, float playery);

	void moveRefill(int &WH, int&WH2, float playerx, float playery);

	void resetRefill();

	void resetBoss();
private:
	Sprite bfloor, bbackground, cheese, cheese2, meat, meat2, launch, btheUI, refill;

	std::vector<Monster*> enemies;
	std::vector<Launcher*> mLaunch; //this is the vector to the launcher class

	bool blaunch = false, blaunch2 = false, blaunch3 = false, blaunch4 = false, dropR = false, calculateRefill = true, reload = false;
	int bcounter = 380, bcounter2 = 380, bcounter3 = 380, bcounter4 = 380, resetTimer = 400;
	int cheeseCounter = 10, meatCounter = 5;
	int refillCounter = 380;
	float refillx = 0, refilly = 380;

};