#include "FirstLvl.h"

FirstLvl::FirstLvl(Sprite b, Sprite p, Sprite e, Sprite e2, Sprite plat, Sprite floor, Sprite UI, Sprite dead, Sprite fall, Sprite k)
{
	//shift everything by 
	fbackground = b;
	fplatform = p;
	fenemy = e;
	fenemy2 = e2;
	fenemy3 = e;
	fplatform = plat;
	ftheFloor = floor;
	ftheUI = UI;
	fdead = dead;
	fpit = fall;
	fpit2 = fall;
	fpit3 = fall;
	knives = k;
	fplatform2 = plat;
	fplatform3 = plat;
	fplatform4 = plat;
	fplatform5 = plat;
	fplatform6 = plat;
	fplatform7 = plat;

	rplat1.load_sprite_image("assets/images/fridge.png");
	rplat2.load_sprite_image("assets/images/crate.png");

	pauseIcon.load_sprite_image("assets/images/pause.png")
		.set_position(150, 200)
		.set_scale(400, 300);

	exit.load_sprite_image("assets/images/exit.png")
		.set_scale(100, 150)
		.set_position(9700, 50);

	theLauncher.load_sprite_image("assets/images/launcher.png")
		.set_position(3920, 140)
		.set_scale(200, 100); 

	theMeatBall.load_sprite_image("assets/images/meatball.png")
		.set_position(3920, 170) 
		.set_scale(50, 50);

	column1.load_sprite_image("assets/images/crate.png") //shift by 400
		.set_position(4720, 50) 
		.set_scale(100, 100);
	column2.load_sprite_image("assets/images/fridge.png")
		.set_position(4920, 50) 
		.set_scale(100, 200);

	column3.load_sprite_image("assets/images/crate.png")
		.set_position(7300, 50) 
		.set_scale(200,100);
	column4.load_sprite_image("assets/images/crate.png")
		.set_position(7700, 50) 
		.set_scale(100, 100);
	column5.load_sprite_image("assets/images/crate.png")
		.set_position(7900, 50) 
		.set_scale(200,100);
	column6.load_sprite_image("assets/images/fridge.png")
		.set_position(8200, 50) 
		.set_scale(100, 200);

	column7.load_sprite_image("assets/images/crate.png")
		.set_position(8900, 50)
		.set_scale(200, 100);

	fpit2.set_position(5100, 0) //shift by 400
		.set_scale(1200, 50);
	fpit3.set_position(7300, 0) 
		.set_scale(900, 50);

	rplat1.set_position(2450, 50)
		.set_scale(150,200);
	rplat2.set_position(2600, 50)
		.set_scale(100,100);

	refill.load_sprite_image("assets/images/refill.png")
		.set_scale(100, 100)
		.set_position(rplat1.get_position().x+20, rplat1.get_position().y+200);

	fplatform2.set_position(1200, 50);
	fplatform3.set_position(3500, 50); //shift by 400
	fplatform4.set_position(3700, 150); 
	fplatform5.set_position(5100, 150)
		.set_scale(250, 100);
	fplatform6.set_position(5500, 150) 
		.set_scale(250, 100);
	fplatform7.set_position(5900, 50); 

	enemies.push_back(new Dairy(fenemy.get_position().x, fenemy.get_position().y, 2, 10, fenemy)); //0
	enemies.push_back(new Meat(fenemy2.get_position().x, fenemy2.get_position().y, 5, 30, fenemy2)); //1 //shift by 400
	enemies.push_back(new Dairy(3200, 50, 2, 10, fenemy)); //2 
	enemies.push_back(new Dairy(6000, 150, 2, 10, fenemy)); //3 
	enemies.push_back(new Meat(6700, 50, 5, 30, fenemy2)); //4 

	hazard.push_back(new FHazard(knives.get_position().x, knives.get_position().y, 3, 1, knives, 100, 50)); //shift by 400
	hazard.push_back(new FHazard(7300, 350, 0.5, 1, knives, 100, 130));
	hazard.push_back(new FHazard(7700, 350, 0.5, 1, knives, 100, 130));
	hazard.push_back(new FHazard(8700, 350, 0.5, 1, knives, 100, 50)); 
	hazard.push_back(new FHazard(9100, 350, 0.5, 1, knives, 100, 50)); 

	mLaunch.push_back(new Launcher(theMeatBall.get_position().x, theMeatBall.get_position().y, 4, 1, theMeatBall, theLauncher, theLauncher.get_position().x, theLauncher.get_position().y));
	mLaunch.push_back(new Launcher(1600, 75, 2, 1, theMeatBall, theLauncher, 1500, 50)); //shift by 400
	mLaunch.push_back(new Launcher(9100, 75, 2, 1, theMeatBall, theLauncher, 9100,50)); 

	spritesToDraw.push_back(&fenemy);
	spritesToDraw.push_back(&fenemy2);
}

FirstLvl::~FirstLvl()
{
	for (int i = 0; i < enemies.size(); i++)
	{
		delete enemies[i];
	}

	for (int i = 0; i < hazard.size(); i++)
	{
		delete hazard[i];
	}


	for (int i = 0; i < mLaunch.size(); i++)
	{
		delete mLaunch[i];
	}


	
}

void FirstLvl::IterativeSelectionSort(std::vector<Sprite*>& a_sprites)
{
	for (unsigned int i = 0; i < a_sprites.size(); i++)
	{
		int minIndex = i;
		for (unsigned int j = i; j < a_sprites.size(); j++)
		{
			if (a_sprites[j]->get_depth() < a_sprites[minIndex]->get_depth())
			{
				minIndex = j;
			}
		}
		std::swap(a_sprites[minIndex], a_sprites[i]);
	}
}

void FirstLvl::Restart()
{
	//this basically resets all the positions and stats
	cheese = 1;
	cheese2 = 1;
	cheese3 = 1;
	meat = 1;
	meat2 = 1;

	//this resets the counters for the enemy movements
	counter = 600;
	counter2 = 2100;
	counter3 = 3200;
	counter4 = 6100;
	counter5 = 6600;

	life = 1;

	//this resets the enemy positions
	((Dairy*)enemies[0])->setX(600);
	((Dairy*)enemies[0])->setY(130);

	((Meat*)enemies[1])->setX(2000);
	((Meat*)enemies[1])->setY(50);

	((Dairy*)enemies[2])->setX(3200);
	((Dairy*)enemies[2])->setY(50);

	((Dairy*)enemies[3])->setX(6000);
	((Dairy*)enemies[3])->setY(150);

	((Meat*)enemies[4])->setX(6700);
	((Meat*)enemies[4])->setY(50);

	fbackground.set_position(0, 0);
	

	//this resets the hazards
	(hazard[0])->setMove(false);
	(hazard[0])->reset(3000, 350);
	(hazard[0])->setHealth(1);

	(hazard[1])->setMove(false);
	(hazard[1])->reset(7300, 350);
	(hazard[1])->setHealth(1);

	(hazard[2])->setMove(false);
	(hazard[2])->reset(7700, 350);
	(hazard[2])->setHealth(1);

	(hazard[3])->setMove(false);
	(hazard[3])->reset(8700, 350);
	(hazard[3])->setHealth(1);

	(hazard[4])->setMove(false);
	(hazard[4])->reset(9100, 350);
	(hazard[4])->setHealth(1);
	
	//this resets the health
	((Dairy*)enemies[0])->setHealth(10);
	((Meat*)enemies[1])->setHealth(30);
	((Dairy*)enemies[2])->setHealth(10);
	((Dairy*)enemies[3])->setHealth(10);
	((Meat*)enemies[4])->setHealth(30);

	//this resets the platforms
	fplatform.set_position(400, 50);
	fplatform2.set_position(1200, 50);
	fplatform3.set_position(3500, 50);
	fplatform4.set_position(3700, 150);
	fplatform5.set_position(5100, 150);
	fplatform6.set_position(5500, 150);
	fplatform7.set_position(5900, 50);

	//this resets the pitfalls
	fpit.set_position(3800, 0);
	fpit2.set_position(5100, 0);
	fpit3.set_position(7300, 0);

	//this resets the refill stuff

	rplat1.set_position(2450, 50);
	rplat2.set_position(2600, 50);
	refill.set_position(rplat1.get_position().x + 20, rplat1.get_position().y + 200);

	//this resets the columns
	column1.set_position(4720,50);
	column2.set_position(4920, 50);
	column3.set_position(7300, 50);
	column4.set_position(7700, 50);
	column5.set_position(7900, 50);
	column6.set_position(8200, 50);
	column7.set_position(8900, 50);

	//this stuff is for resetting the launchers

	mcounter = 3440;
	mcounter2 = 1400;
	mcounter3 = 8900;

	mLaunch[0]->setX(3920);
	mLaunch[0]->setY(170);
	mLaunch[0]->lReset(3920, 140);

	mLaunch[1]->setX(1600);
	mLaunch[1]->setY(75);
	mLaunch[1]->lReset(1500, 50);

	mLaunch[2]->setX(9100);
	mLaunch[2]->setY(75);
	mLaunch[2]->lReset(9100, 50);

	exit.set_position(9700, 50);

	

} 

void FirstLvl::scrollLeft(int sVal)
{
	//this shifts everything to the left
	float plx = fplatform.get_position().x;
	float ply = fplatform.get_position().y;

	float plx2 = fplatform2.get_position().x;
	float ply2 = fplatform2.get_position().y;

	float plx3 = fplatform3.get_position().x;
	float ply3 = fplatform3.get_position().y;

	float plx4 = fplatform4.get_position().x;
	float ply4 = fplatform4.get_position().y;

	float plx5 = fplatform5.get_position().x;
	float ply5 = fplatform5.get_position().y;

	float plx6 = fplatform6.get_position().x;
	float ply6 = fplatform6.get_position().y;

	float plx7 = fplatform7.get_position().x;
	float ply7 = fplatform7.get_position().y;

	float rx1 = rplat1.get_position().x;
	float ry1 = rplat1.get_position().y;

	float rx2 = rplat2.get_position().x;
	float ry2 = rplat2.get_position().y;

	float refillx = refill.get_position().x;
	float refilly = refill.get_position().y;

	float exitx = exit.get_position().x;

	float x = fbackground.get_position().x;
	//float y = fbackground.get_position().y;

	//these are the pitfalls. 
	float px = fpit.get_position().x;
	float px2 = fpit2.get_position().x;
	float px3 = fpit3.get_position().x;

	float cx = column1.get_position().x;
	float cx2 = column2.get_position().x;
	float cx3 = column3.get_position().x;
	float cx4 = column4.get_position().x;
	float cx5 = column5.get_position().x;
	float cx6 = column6.get_position().x;
	float cx7 = column7.get_position().x;

	fbackground.set_position(x -= sVal, 0);//This makes everything scroll as per the player

	fplatform.set_position(((plx) -= sVal), (ply));
	fplatform2.set_position(plx2 -= sVal, ply2);
	fplatform3.set_position(((plx3) -= sVal), (ply3));
	fplatform4.set_position(((plx4) -= sVal), (ply4));
	fplatform5.set_position(((plx5) -= sVal), (ply5));
	fplatform6.set_position(((plx6) -= sVal), (ply6));
	fplatform7.set_position(((plx7) -= sVal), (ply7));

	enemies[0]->shiftLeft(sVal);
	enemies[1]->shiftLeft(sVal);
	enemies[2]->shiftLeft(sVal);
	enemies[3]->shiftLeft(sVal);
	enemies[4]->shiftLeft(sVal);

	fpit.set_position(px -= sVal, 0);
	fpit2.set_position(px2 -= sVal, 0);
	fpit3.set_position(px3 -= sVal, 0);

	hazard[0]->shiftLeft(sVal);
	hazard[1]->shiftLeft(sVal);
	hazard[2]->shiftLeft(sVal);
	hazard[3]->shiftLeft(sVal);
	hazard[4]->shiftLeft(sVal);

	mLaunch[0]->shiftLeft(sVal);
	mLaunch[0]->moveLeft(sVal);

	mLaunch[1]->shiftLeft(sVal);
	mLaunch[1]->moveLeft(sVal);

	mLaunch[2]->shiftLeft(sVal);
	mLaunch[2]->moveLeft(sVal);

	column1.set_position(cx  -=sVal,50);
	column2.set_position(cx2 -=sVal,50);
	column3.set_position(cx3 -= sVal, 50);
	column4.set_position(cx4 -= sVal, 50);
	column5.set_position(cx5 -= sVal, 50);
	column6.set_position(cx6 -= sVal, 50);
	column7.set_position(cx7 -= sVal, 50);

	rplat1.set_position(rx1 -= sVal, ry1);
	rplat2.set_position(rx2 -= sVal, ry2);

	refill.set_position(refillx -= sVal, refilly);

	exit.set_position(exitx -= sVal, 50);
}

void FirstLvl::scrollRight(int sVal)
{
	//shifts everything to the right
	float plx = fplatform.get_position().x;
	float ply = fplatform.get_position().y;

	float plx2 = fplatform2.get_position().x;
	float ply2 = fplatform2.get_position().y;

	float plx3 = fplatform3.get_position().x;
	float ply3 = fplatform3.get_position().y;

	float plx4 = fplatform4.get_position().x;
	float ply4 = fplatform5.get_position().y;

	float plx5 = fplatform5.get_position().x;
	float ply5 = fplatform5.get_position().y;

	float plx6 = fplatform6.get_position().x;
	float ply6 = fplatform6.get_position().y;

	float plx7 = fplatform7.get_position().x;
	float ply7 = fplatform7.get_position().y;

	float rx1 = rplat1.get_position().x;
	float ry1 = rplat1.get_position().y;

	float rx2 = rplat2.get_position().x;
	float ry2 = rplat2.get_position().y;

	float refillx = refill.get_position().x;
	float refilly = refill.get_position().y;

	float exitx = exit.get_position().x;

	float x = fbackground.get_position().x;

	float px = fpit.get_position().x;
	float px2 = fpit2.get_position().x;
	float px3 = fpit3.get_position().x;

	float cx = column1.get_position().x;
	float cx2 = column2.get_position().x;
	float cx3 = column3.get_position().x;
	float cx4 = column4.get_position().x;
	float cx5 = column5.get_position().x;
	float cx6 = column6.get_position().x;
	float cx7 = column7.get_position().x;

	fbackground.set_position(x += sVal, 0); //making sure the background is greater than zero in order for it to scroll back
	fplatform.set_position(((plx) += sVal), (ply));
	fplatform2.set_position(((plx2) += sVal), (ply2));
	fplatform3.set_position(((plx3) += sVal), (ply3));
	fplatform4.set_position(((plx4) += sVal), (ply4));
	fplatform5.set_position(((plx5) += sVal), (ply5));
	fplatform6.set_position(((plx6) += sVal), (ply6));
	fplatform7.set_position(((plx7) += sVal), (ply7));

	enemies[0]->shiftRight(sVal);
	enemies[1]->shiftRight(sVal);
	enemies[2]->shiftRight(sVal);
	enemies[3]->shiftRight(sVal);
	enemies[4]->shiftRight(sVal);

	fpit.set_position(px += sVal, 0);
	fpit2.set_position(px2 += sVal, 0);
	fpit3.set_position(px3 += sVal, 0);

	hazard[0]->shiftRight(sVal);
	hazard[1]->shiftRight(sVal);
	hazard[2]->shiftRight(sVal);
	hazard[3]->shiftRight(sVal);
	hazard[4]->shiftRight(sVal);

	mLaunch[0]->shiftRight(sVal);
	mLaunch[0]->moveRight(sVal);

	mLaunch[1]->shiftRight(sVal);
	mLaunch[1]->moveRight(sVal);

	mLaunch[2]->shiftRight(sVal);
	mLaunch[2]->moveRight(sVal);

	column1.set_position(cx += sVal, 50);
	column2.set_position(cx2 += sVal, 50);
	column3.set_position(cx3 += sVal, 50);
	column4.set_position(cx4 += sVal, 50);
	column5.set_position(cx5 += sVal, 50);
	column6.set_position(cx6 += sVal, 50);
	column7.set_position(cx7 += sVal, 50);

	rplat1.set_position(rx1 += sVal, ry1);
	rplat2.set_position(rx2 += sVal, ry2);

	refill.set_position(refillx += sVal, refilly);

	exit.set_position(exitx += sVal, 50);
}

void FirstLvl::UI(float phealth, bool W1, bool W2, int W1H, int W2H)
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


	if (cheese == 0 && meat == 0 && cheese2 == 0 && cheese3 == 0 && meat2 == 0)
	{
		Text::set_color(0.0f, 0.0f, 0.0f);
		Text::draw_string("REACHED", "TEMP", 500.0f, 460.0f);
		Text::draw_string("GOAL", "TEMP", 520.0f, 500.0f);
	}
	else
	{
		if (cheese == 0 && cheese2 == 0 && cheese3 == 0)
		{
			Text::set_color(0.0f, 1.0f, 0.0f);
			Text::draw_string("Cheese", "TEMP", 500.0f, 500.0f);
		}
		else if (cheese == 1 && cheese2 == 0 && cheese3 == 0 || cheese == 0 && cheese2 == 1  && cheese3 == 0 || cheese3 == 1 && cheese == 0 &&cheese2 == 0)
		{
			Text::set_color(1.0f, 0.0f, 0.0f);
			Text::draw_string("Cheese x1", "TEMP", 500.0f, 500.0f);
		}
		else if (cheese == 1 && cheese2 == 1 && cheese3 == 0 || cheese == 0 && cheese2 == 1 && cheese3 == 1 || cheese == 1 && cheese2 == 0 && cheese3 == 1)
		{
			Text::set_color(1.0f, 0.0f, 0.0f);
			Text::draw_string("Cheese x2", "TEMP", 500.0f, 500.0f);
		}
		else if (cheese == 1 && cheese2 == 1 && cheese3 == 1)
		{
			Text::set_color(1.0f, 0.0f, 0.0f);
			Text::draw_string("Cheese x3", "TEMP", 500.0f, 500.0f);
		}
	
		if (meat == 1 && meat2 == 1)
		{
			Text::set_color(1.0f, 0.0f, 0.0f);
			Text::draw_string("Meat x2", "TEMP", 500.0f, 460.0f);
		}
		if (meat == 1 && meat2 == 0 || meat == 0 && meat2 == 1)
		{
			Text::set_color(1.0f, 0.0f, 0.0f);
			Text::draw_string("Meat x1", "TEMP", 500.0f, 460.0f);
		}
		else if (meat == 0 && meat2 == 0)
		{
			Text::set_color(0.0f, 1.0f, 0.0f);
			Text::draw_string("Meat", "TEMP", 500.0f, 460.0f);
		}
	}

	//also the health bars
	Shapes::set_color(0.0f, 1.0f, 0.0f);
	Shapes::draw_rectangle(true, enemies[0]->getX(), enemies[0]->getY()+120, enemies[0]->getHealth()*10, 10, 0); //the first cheese
	Shapes::draw_rectangle(true, enemies[1]->getX()+40, enemies[1]->getY() + 160, enemies[1]->getHealth() * 3, 10, 0); //the first meat
	Shapes::draw_rectangle(true, enemies[2]->getX(), enemies[2]->getY() + 120, enemies[2]->getHealth() * 10, 10, 0); //the second cheese
	Shapes::draw_rectangle(true, enemies[3]->getX(), enemies[3]->getY() + 120, enemies[3]->getHealth() * 10, 10, 0); //the third cheese
	Shapes::draw_rectangle(true, enemies[4]->getX() + 40, enemies[4]->getY() + 160, enemies[4]->getHealth() * 3, 10, 0); //the second meat

	//durability bars
	Shapes::set_color(1.0f, 0.0f, 1.0f);
	if (W1H > 0)
	{
		Shapes::draw_rectangle(true, 10, 470, W1H * 10, 15, 0); //the first weapon
	}
	if (W2H > 0)
	{
		Shapes::draw_rectangle(true, 10, 450, W2H * 10, 15, 0); //the first weapon
	}

}

void FirstLvl::Update()
{
	//updates the animations
	((Dairy*)enemies[0])->nextFrame();
	((Meat*)enemies[1])->nextFrame();
	((Dairy*)enemies[2])->nextFrame();
	((Dairy*)enemies[3])->nextFrame();
	((Meat*)enemies[4])->nextFrame();
}

void FirstLvl::Draw()
{
	//draws everything
	fbackground.draw();
	ftheUI.draw();
	ftheFloor.draw();

	fplatform.draw();
	fplatform2.draw();
	fplatform3.draw();
	fplatform4.draw();
	fplatform5.draw();
	fplatform6.draw();
	fplatform7.draw();

	fpit.draw();
	fpit2.draw();
	fpit3.draw();

	column1.draw();
	column2.draw();
	column3.draw();
	column4.draw();
	column5.draw();
	column6.draw();
	column7.draw();

	((Launcher*)mLaunch[0])->statDraw();
	((Launcher*)mLaunch[1])->statDraw();
	((Launcher*)mLaunch[2])->statDraw();

	rplat1.draw();
	rplat2.draw();

	refill.draw();

	exit.draw();
}
 
void FirstLvl::RunLevel(float &phealth, bool W1, bool W2, int W1H, int W2H, Player *thePlayer)
{
	//This is for if the game is paused
	if (pause == true)
	{
		Update();
		Draw();
		UI(phealth, W1, W2, W1H, W2H);
		
		//if the enemies are alive it draws them
		if (((Dairy*)enemies[0])->getHealth() > 0)
		{
			((Dairy*)enemies[0])->draw();
			((Dairy*)enemies[0])->pause();
		}

		if (((Meat*)enemies[1])->getHealth() > 0)
		{
			((Meat*)enemies[1])->draw();
			((Meat*)enemies[1])->pause();
		}

		if (((Dairy*)enemies[2])->getHealth() > 0)
		{
			((Dairy*)enemies[2])->draw();
			((Dairy*)enemies[2])->pause();
		}

		if (((Dairy*)enemies[3])->getHealth() > 0)
		{
			((Dairy*)enemies[3])->draw();
			((Dairy*)enemies[3])->pause();
		}

		if (((Meat*)enemies[4])->getHealth() > 0)
		{
			((Meat*)enemies[4])->draw();
			((Meat*)enemies[4])->pause();
		}

		//the player death and stuff
		if (thePlayer->getH() > 0)
			thePlayer->draw();
		if (thePlayer->getH() <= 0)
		{
			fdead.set_position(thePlayer->getX(), thePlayer->getY() - 40);
			fdead.draw();
		}
		
		if (hazard[0]->getHealth() > 0)
		{
			(hazard[0])->draw();
		}
		if (hazard[1]->getHealth() > 0)
		{
			(hazard[1])->draw();
		}
		if (hazard[2]->getHealth() > 0)
		{
			(hazard[2])->draw();
		}

		mLaunch[0]->draw();
		mLaunch[1]->draw();
		mLaunch[2]->draw();

		pauseIcon.draw();
	}

	//This is for if the game is still running
	else if (pause == false)
	{
		//Updates, draws, and the UI
		Update();
		Draw();
		UI(phealth, W1, W2, W1H, W2H);

		if (hazard[0]->getHealth() > 0) //the first falling knives
		{
			(hazard[0])->draw();
		}

		if (hazard[0]->getMove() == false)
		{
			(hazard[0])->checkTrigger(thePlayer->getX(), thePlayer->getY());
		}
		else if (hazard[0]->getMove() == true)
		{
			(hazard[0])->move(0,0,life);
			(hazard[0])->Collisions(thePlayer->getX(), thePlayer->getY(), phealth);
	
		}

		if (hazard[1]->getHealth() > 0) //the second falling knives
		{
			(hazard[1])->draw();
		}

		if (hazard[1]->getMove() == false)
		{
			(hazard[1])->checkTrigger(thePlayer->getX(), thePlayer->getY());
		}
		else if (hazard[1]->getMove() == true)
		{
			(hazard[1])->move(0, 0, life);
			(hazard[1])->Collisions(thePlayer->getX(), thePlayer->getY(), phealth);

		}
		
		if (hazard[2]->getHealth() > 0) //third falling knives
		{
			(hazard[2])->draw();
		}

		if (hazard[2]->getMove() == false)
		{
			(hazard[2])->checkTrigger(thePlayer->getX(), thePlayer->getY());
		}
		else if (hazard[2]->getMove() == true)
		{
			//float temp = thePlayer->getH();
			(hazard[2])->move(0, 0, life);
			(hazard[2])->Collisions(thePlayer->getX(), thePlayer->getY(), phealth);
			//thePlayer->setH(temp);
		}

		if (hazard[3]->getHealth() > 0) //third falling knives
		{
			(hazard[3])->draw();
		}

		if (hazard[3]->getMove() == false)
		{
			(hazard[3])->checkTrigger(thePlayer->getX(), thePlayer->getY());
		}
		else if (hazard[3]->getMove() == true)
		{
		//	std::cout << "HI" << std::endl;
			//float temp = thePlayer->getH();
			(hazard[3])->move(0, 0, life);
			(hazard[3])->Collisions(thePlayer->getX(), thePlayer->getY(), phealth);
			
			//thePlayer->setH(temp);
		}

		if (hazard[4]->getHealth() > 0) //third falling knives
		{
			(hazard[4])->draw();
		}

		if (hazard[4]->getMove() == false)
		{
			(hazard[4])->checkTrigger(thePlayer->getX(), thePlayer->getY());
		}
		else if (hazard[4]->getMove() == true)
		{
			//float temp = thePlayer->getH();
			(hazard[4])->move(0, 0, life);
			(hazard[4])->Collisions(thePlayer->getX(), thePlayer->getY(), phealth);
			//thePlayer->setH(temp);
		}

		//Only draws the player if the player is alive
		if (thePlayer->getH() > 0)
			thePlayer->draw();
		if (thePlayer->getH() <= 0)
		{
			fdead.set_position(thePlayer->getX(), thePlayer->getY() - 40);
			fdead.draw();
		}

		//these are the functions we need to run for the enemies. 
		if (enemies[0]->getHealth() > 0)
		{
			bool temp = thePlayer->getA();
			bool temp2 = thePlayer->getW1();

			((Dairy*)enemies[0])->move(400, 700, counter);
			((Dairy*)enemies[0])->draw();
			enemies[0]->Collisions(thePlayer->getX(), thePlayer->getY(), temp, temp2, phealth);

			thePlayer->setA(temp);
			thePlayer->setW1(temp2);
		}
		if (enemies[1]->getHealth() > 0)
		{
			//subtract 600
			bool temp = thePlayer->getA();
			bool temp2 = thePlayer->getW2();
			((Meat*)enemies[1])->move(2200, 2400, counter2); //subtract 400
			((Meat*)enemies[1])->draw();
			enemies[1]->Collisions(thePlayer->getX(), thePlayer->getY(), temp, temp2, phealth);

			thePlayer->setA(temp);
			thePlayer->setW2(temp2);
		}
		if (enemies[2]->getHealth() > 0)
		{
			bool temp = thePlayer->getA();
			bool temp2 = thePlayer->getW1();

			((Dairy*)enemies[2])->move(3100, 3400, counter3); //subtract 400
			((Dairy*)enemies[2])->draw();
			enemies[2]->Collisions(thePlayer->getX(), thePlayer->getY(), temp, temp2, phealth);

			thePlayer->setA(temp);
			thePlayer->setW1(temp2);
		
		}
		if (enemies[3]->getHealth() > 0)
		{
			bool temp = thePlayer->getA();
			bool temp2 = thePlayer->getW1();
			((Dairy*)enemies[3])->move(6000, 6300, counter4); //subtract 400
			((Dairy*)enemies[3])->draw();
			enemies[3]->Collisions(thePlayer->getX(), thePlayer->getY(), temp, temp2, phealth);

			thePlayer->setA(temp);
			thePlayer->setW1(temp2);
		}
		if (enemies[4]->getHealth() > 0)
		{
			bool temp = thePlayer->getA();
			bool temp2 = thePlayer->getW2();
			((Meat*)enemies[4])->move(6400, 6800, counter5); //subtract 400
			((Meat*)enemies[4])->draw();
			enemies[4]->Collisions(thePlayer->getX(), thePlayer->getY(), temp, temp2, phealth);

			thePlayer->setA(temp);
			thePlayer->setW2(temp2);
		}

		if (mLaunch[0]->getHealth() > 0)
		{
			//float htemp = thePlayer->getH();
			mLaunch[0]->draw();
			mLaunch[0]->move(3040, 3520, mcounter);
			mLaunch[0]->Collisions(thePlayer->getX(), thePlayer->getY(), phealth);

			//thePlayer->setH(htemp);
		}
		if (mLaunch[1]->getHealth() > 0)
		{
		//	float htemp = thePlayer->getH();
			mLaunch[1]->draw();
			mLaunch[1]->move(970, 1300, mcounter2);
			mLaunch[1]->Collisions(thePlayer->getX(), thePlayer->getY(), phealth);

		//	thePlayer->setH(htemp);
		}
		if (mLaunch[2]->getHealth() > 0)
		{
			//float htemp = thePlayer->getH();
			mLaunch[2]->draw();
			mLaunch[2]->move(8600, 9100, mcounter3);
			mLaunch[2]->Collisions(thePlayer->getX(), thePlayer->getY(), phealth);

			//thePlayer->setH(htemp);
		}

		if (enemies[0]->getHealth() == 0)
		{
			cheese = 0;
		}
		if (enemies[1]->getHealth() == 0)
		{
			meat = 0;
		}
		if (enemies[2]->getHealth() == 0)
		{
			cheese2 = 0;
		}
		if (enemies[3]->getHealth() == 0)
		{
			cheese3 = 0;
		}
		if (enemies[4]->getHealth() == 0)
		{
			meat2 = 0;
		}

		if (thePlayer->getX() > exit.get_position().x - 60 + thePlayer->getX() < exit.get_position().x + 60)
		{
			leave = true;
		}

		if (cheese == 0 && cheese2 == 0 && cheese3 == 0 && meat == 0 && meat2 == 0)
		{
			goalReached = true;
		}
	}
}

void FirstLvl::Pitfall(Sprite fall, Player *thePlayer, float length)
{
	//this is for the pitfalls
	if (thePlayer->getX() > fall.get_position().x-50 && thePlayer->getX() < fall.get_position().x + (length))
	{
		if (thePlayer->getY() == 50)
		thePlayer->setH(0);
	}
}

void FirstLvl::setP(bool temp)
{
	pause = temp;
}
	 
bool FirstLvl::getP() const
{
	return pause;
}

bool FirstLvl::getLeave() const
{
	return leave;
}

bool FirstLvl::getGoal() const
{
	return goalReached;
}

float FirstLvl::getBX() 
{
	return fbackground.get_position().x;
}

float FirstLvl::getBY() 
{
	return fbackground.get_position().y;
}

float FirstLvl::getPX() 
{
	return fplatform.get_position().x;
}

float FirstLvl::getPY() 
{
	return fplatform.get_position().y;
}

float FirstLvl::getPX2()
{
	return fplatform2.get_position().x;
}

float FirstLvl::getPY2()
{
	return fplatform2.get_position().y;
}

float FirstLvl::getPX3()
{
	return fplatform3.get_position().x;
}

float FirstLvl::getPY3()
{
	return fplatform3.get_position().y;
}

float FirstLvl::getPX4()
{
	return fplatform4.get_position().x;
}

float FirstLvl::getPY4()
{
	return fplatform4.get_position().y;
}

float FirstLvl::getPX5()
{
	return fplatform5.get_position().x;
}

float FirstLvl::getPY5()
{
	return fplatform5.get_position().y;
}

float FirstLvl::getPX6()
{
	return fplatform6.get_position().x;
}

float FirstLvl::getPY6()
{
	return fplatform6.get_position().y;
}

float FirstLvl::getPX7()
{
	return fplatform7.get_position().x;
}

float FirstLvl::getPY7()
{
	return fplatform7.get_position().y;
}

float FirstLvl::getC1X()
{
	return column1.get_position().x;
}

float FirstLvl::getC1Y()
{
	return column1.get_position().y;
}
//second column
float FirstLvl::getC2X()
{
	return column2.get_position().x;
}

float FirstLvl::getC2Y()
{
	return column2.get_position().y;
}
//third column
float FirstLvl::getC3X()
{
	return column3.get_position().x;
}

float FirstLvl::getC3Y()
{
	return column3.get_position().y;
}
//fourth column
float FirstLvl::getC4X()
{
	return column4.get_position().x;
}

float FirstLvl::getC4Y()
{
	return column4.get_position().y;
}
//fifth column
float FirstLvl::getC5X()
{
	return column5.get_position().x;
}

float FirstLvl::getC5Y()
{
	return column5.get_position().y;
}
//sixth column
float FirstLvl::getC6X()
{
	return column6.get_position().x;
}

float FirstLvl::getC6Y()
{
	return column6.get_position().y;
}

//seventh column
float FirstLvl::getC7X()
{
	return column7.get_position().x;
}

float FirstLvl::getC7Y()
{
	return column7.get_position().y;
}

//refill platform 1
float FirstLvl::getRPX1()
{
	return rplat1.get_position().x;
}

float FirstLvl::getRPY1()
{
	return rplat1.get_position().y;
}

//refill platform 2
float FirstLvl::getRPX2()
{
	return rplat2.get_position().x;
}

float FirstLvl::getRPY2()
{
	return rplat2.get_position().y;
}

//getting the platforms
Sprite FirstLvl::getPlat() 
{
	return fplatform;
}

Sprite FirstLvl::getPlat2()
{
	return fplatform2;
}

Sprite FirstLvl::getPlat3()
{
	return fplatform3;
}

Sprite FirstLvl::getPlat4()
{
	return fplatform4;
}

Sprite FirstLvl::getPlat5()
{
	return fplatform5;
}

Sprite FirstLvl::getPlat6()
{
	return fplatform6;
}

Sprite FirstLvl::getPlat7()
{
	return fplatform7;
}

//getting the pitfalls
Sprite FirstLvl::getFall()
{
	return fpit;
}

Sprite FirstLvl::getFall2()
{
	return fpit2;
}

Sprite FirstLvl::getFall3()
{
	return fpit3;
}

//getting the columns
Sprite FirstLvl::getC1()
{
	return column1;
}

Sprite FirstLvl::getC2()
{
	return column2;
}

Sprite FirstLvl::getC3()
{
	return column3;
}

Sprite FirstLvl::getC4()
{
	return column4;
}

Sprite FirstLvl::getC5()
{
	return column5;
}

Sprite FirstLvl::getC6()
{
	return column6;
}

Sprite FirstLvl::getC7()
{
	return column7;
}

//getting the refill platforms
Sprite FirstLvl::getRP1()
{
	return rplat1;
}

Sprite FirstLvl::getRP2()
{
	return rplat2;
}