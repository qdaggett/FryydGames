#include "BossLvl.h"

BossLvl::BossLvl(Sprite floor, Sprite background, Sprite Gordon)
{
	bfloor = floor;
	bbackground = background;
	btheUI.load_sprite_image("assets/images/UI.png")
		.set_scale(660, 210)
		.set_center(0, 0)
		.set_position(-10, 390);

	refill.load_sprite_image("assets/images/refill.png")
		.set_scale(75, 75)
		.set_position(refillx, refilly);

	cheese.load_sprite_image("assets/images/cheese 1 proj.png")
		.set_scale(50, 50);

	cheese2.load_sprite_image("assets/images/cheese 2 proj.png")
		.set_scale(50, 50);

	meat.load_sprite_image("assets/images/meat 1 proj.png")
		.set_scale(50, 50);

	meat2.load_sprite_image("assets/images/meat 2 proj.png")
		.set_scale(50, 50);

	enemies.push_back(new Boss(Gordon.get_position().x, Gordon.get_position().y, 50, Gordon, 2));

	mLaunch.push_back(new Launcher(80, 380, 2, 1, cheese, launch, 80, 370));
	mLaunch.push_back(new Launcher(180, 380, 2, 1, meat, launch, 180, 370));
	mLaunch.push_back(new Launcher(280, 380, 2, 1, cheese2, launch, 280, 370));
	mLaunch.push_back(new Launcher(380, 380, 2, 1, meat2, launch, 380, 370));

}

void BossLvl::Draw()
{
	bbackground.draw();
	btheUI.draw();
	bfloor.draw();
	
}

void BossLvl::RunLevel(float phealth, bool W1, bool W2, int W1H, int W2H, Player *thePlayer)
{
	Draw();

	if (reload == false)
	{
		//furst projectile
		if (blaunch == false)
		{
			int temp = rand() % 400;
			if (temp > 0 && temp < 10)
			{
				blaunch = true;
			}
		}

		if (blaunch == true)
		{
			mLaunch[0]->vmove(380, 0, bcounter, blaunch);
			mLaunch[0]->draw();

			bool temp = thePlayer->getA();
			bool temp2 = thePlayer->getW1();
			float htemp = thePlayer->getH();
			mLaunch[0]->vCollisions(thePlayer->getX(), thePlayer->getY(), temp, temp2, htemp, cheeseCounter, blaunch, bcounter);

			thePlayer->setA(temp);
			thePlayer->setW1(temp2);
			thePlayer->setH(htemp);
		}

		//second projectile
		if (blaunch2 == false)
		{
			int temp = rand() % 400;
			if (temp > 0 && temp < 10)
			{
				blaunch2 = true;
			}
		}

		if (blaunch2 == true)
		{
			mLaunch[1]->vmove(380, 0, bcounter2, blaunch2);
			mLaunch[1]->draw();

			bool temp = thePlayer->getA();
			bool temp2 = thePlayer->getW2();
			float htemp = thePlayer->getH();
			mLaunch[1]->vCollisions(thePlayer->getX(), thePlayer->getY(), temp, temp2, htemp, meatCounter, blaunch2, bcounter2);

			thePlayer->setA(temp);
			thePlayer->setW2(temp2);
			thePlayer->setH(htemp);
		}

		//third projectile
		if (blaunch3 == false)
		{
			int temp = rand() % 400;
			if (temp > 0 && temp < 10)
			{
				blaunch3 = true;
			}
		}

		if (blaunch3 == true)
		{
			mLaunch[2]->vmove(380, 0, bcounter3, blaunch3);
			mLaunch[2]->draw();

			bool temp = thePlayer->getA();
			bool temp2 = thePlayer->getW1();
			float htemp = thePlayer->getH();
			mLaunch[2]->vCollisions(thePlayer->getX(), thePlayer->getY(), temp, temp2, htemp, cheeseCounter, blaunch3, bcounter3);

			thePlayer->setA(temp);
			thePlayer->setW1(temp2);
			thePlayer->setH(htemp);
		}

		//fourth projectile
		if (blaunch4 == false)
		{
			int temp = rand() % 400;
			if (temp > 0 && temp < 10)
			{
				blaunch4 = true;
			}
		}

		if (blaunch4 == true)
		{
			mLaunch[3]->vmove(380, 0, bcounter4, blaunch4);
			mLaunch[3]->draw();

			bool temp = thePlayer->getA();
			bool temp2 = thePlayer->getW2();
			float htemp = thePlayer->getH();
			mLaunch[3]->vCollisions(thePlayer->getX(), thePlayer->getY(), temp, temp2, htemp, meatCounter, blaunch4, bcounter4);

			thePlayer->setA(temp);
			thePlayer->setW2(temp2);
			thePlayer->setH(htemp);
		}

		if (thePlayer->getW1H() <= 5 || thePlayer->getW2H() <= 5)
		{
			dropR = true;
		}

		if (dropR == true && calculateRefill == true)
		{
			int temp = rand() % 400;

			if (temp < 100)
			{
				refillx = 80;
			}
			else if (temp < 200)
			{
				refillx = 180;
			}
			else if (temp < 300)
			{
				refillx = 280;
			}
			else if (temp < 400)
			{
				refillx = 380;
			}
			calculateRefill = false;

		}

		else if (dropR == true)
		{
			refill.set_position(refillx, refilly);

			int temp = thePlayer->getW1H();
			int temp2 = thePlayer->getW2H();
			moveRefill(temp, temp2, thePlayer->getX(), thePlayer->getY());
			thePlayer->setW1H(temp);
			thePlayer->setW2H(temp2);

			refill.draw();
		}

	}

	UI(phealth, W1, W2, W1H, W2H);

	if (thePlayer->getH() > 0)
		thePlayer->draw();

	if (cheeseCounter == 0 && meatCounter == 0)
	{
		reload = true;
	}
	
	if (enemies[0]->getHealth() > 0 && reload == false)
	{
		((Boss*)enemies[0])->draw();
	}

	else if (enemies[0]->getHealth() > 0 && reload == true)
	{
		resetTimer--;
		if (resetTimer <= 0)
		{
			resetBoss();
		}
		bool temp = thePlayer->getA();
		float htemp = thePlayer->getH();

		((Boss*)enemies[0])->draw();

		((Boss*)enemies[0])->Collisions(thePlayer->getX(), thePlayer->getY(), temp, htemp);

		thePlayer->setA(temp);
		thePlayer->setH(htemp);

		Shapes::set_color(0.0f, 1.0f, 0.0f);
		Shapes::draw_rectangle(true, enemies[0]->getX() + 30, enemies[0]->getY() + 300, enemies[0]->getHealth() * 2, 10, 0);

	}

}

void BossLvl::UI(float phealth, bool W1, bool W2, int W1H, int W2H)
{
	//Displays the UI
	if (phealth > 0)
	{
		if (phealth>70) Shapes::set_color(0.0f, 1.0f, 0.0f);
		else if (phealth >40) Shapes::set_color(1.0f, 1.0f, 0.0f);
		else Shapes::set_color(1.0f, 0.0f, 0.0f);

		Shapes::draw_rectangle(true, 10, 490, 2 * phealth, 30, 0.0f); //x, y, width, height
	}

	if (W1 == true)
	{
		Shapes::set_color(0.0f, 0.0f, 0.9f);
		Shapes::draw_rectangle(true, 325, 480, 45, 45, 0);
	}
	else if (W2 == true)
	{
		Shapes::set_color(0.0f, 0.0f, 0.9f);
		Shapes::draw_rectangle(true, 375, 480, 45, 45, 0);
	}

	Shapes::set_color(1.0f, 1.0f, 0.0f);
	Shapes::draw_rectangle(true, 330, 485, 35, 35, 0);


	Shapes::set_color(1.0f, 0.0f, 0.0f);
	Shapes::draw_rectangle(true, 380, 485, 35, 35, 0);

	Text::load_font("assets/KBZipaDeeDooDah.ttf", "TEMP");

	Text::set_color(0.0f, 0.0f, 0.0f);
	Text::draw_string("Health", "TEMP", 10.0f, 530.0f);

	Text::draw_string("Weapons", "TEMP", 325.0f, 530.0f);
	
	Shapes::set_color(1.0f, 0.0f, 1.0f);
	if (W1H > 0)
	{
		Shapes::draw_rectangle(true, 10, 470, W1H * 10, 15, 0); //the first weapon
	}
	if (W2H > 0)
	{
		Shapes::draw_rectangle(true, 10, 450, W2H * 10, 15, 0); //the first weapon
	}

	if (meatCounter == 0 && cheeseCounter == 0)
	{
		Text::draw_string("BEAT", "TEMP", 500.0f, 500.0f);
		Text::draw_string("JORDAN", "TEMP", 500.0f, 460.0f);
	}

	else
	{
		Text::set_color(0.0f, 0.0f, 0.0f);
		std::string s = std::to_string(cheeseCounter);
		Text::draw_string("Cheese " + s, "TEMP", 500.0f, 500.0f);

		std::string s2 = std::to_string(meatCounter);
		Text::draw_string("Meat " + s2, "TEMP", 500.0f, 460.0f);
	}

	if (reload == true)
	{
		Text::set_color(1.0f, 0.0f, 0.0f);
		Shapes::draw_rectangle(true, 10, 10, resetTimer * 1.5, 50, 0);
	}

}

void BossLvl::checkRefill(int &WH, int&WH2, float playerx, float playery)
{
	float distanceBetween;

	float radiuses = 50.0f;
	float attackR = 100.0f;

	//the formula
	distanceBetween = sqrt(pow(refilly - playery, 2) + pow(refillx - playerx, 2));
	
	if (distanceBetween < radiuses)
	{
		WH = 10;
		WH2 = 10;
		resetRefill();
	}
	else if (refilly <= 0 || refill.get_position().y <= 0)
	{
		resetRefill();
	}
}

void BossLvl::moveRefill(int &WH, int&WH2, float playerx, float playery)
{
	refilly -= 3;
	refillCounter -= 3;
	checkRefill(WH, WH2, playerx, playery);
}

void BossLvl::resetRefill()
{
	dropR = false;
	refillx = 0;
	refilly = 380;
	refillCounter = 380;
	refill.set_position(refillx, refilly);
	calculateRefill = true;
}

void BossLvl::resetBoss()
{
	cheeseCounter = 10;
	meatCounter = 5;
	reload = false;

	blaunch = false;
	blaunch2 = false;
	blaunch3 = false;
	blaunch4 = false;

	bcounter = 380;
	bcounter2 = 380;
	bcounter3 = 380;
	bcounter4 = 380;

	mLaunch[0]->setY(380);
	mLaunch[1]->setY(380);
	mLaunch[2]->setY(380);
	mLaunch[3]->setY(380);

	enemies[0]->setHealth(50);
}