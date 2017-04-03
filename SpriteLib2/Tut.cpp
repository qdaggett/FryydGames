#include "Tut.h"

Tut::Tut(Sprite floor, Sprite background, Sprite platform)
{
	tfloor = floor;
	tplatform = platform;
	tbackground.load_sprite_image("assets/images/tutorial_background.png")
		.set_scale(2900, 432);

//	dummy1.load_sprite_image("assets/images/dummy.png");
//	dummy2.load_sprite_image("assets/images/dummy.png");

	tshift.load_sprite_image("assets/images/shift.png")
		.set_scale(200, 200)
		.set_position(500, 200);

	theUI.load_sprite_image("assets/images/UI.png")
		.set_scale(660, 210)
		.set_center(0, 0)
		.set_position(-10, 390);

	tarrows.load_sprite_image("assets/images/arrowkeys.png")
		.set_scale(200, 200)
		.set_position(1000, 200);

	tspace.load_sprite_image("assets/images/space.png")
		.set_scale(200, 200)
		.set_position(2000, 200);

	tplatform.set_position(2200, 50);
	tplatform.set_scale(400, 90);

	dummy1.load_sprite_image("assets/images/cheese dummy ss.png")
		
		.set_sprite_frame_size(460, 460)
		.set_scale(100, 130)
		.push_frame_row("dum1",0,0,460,0,4)
		.push_frame("idle",0,0)
		.set_position(500, 50)
		.set_animation("idle")
		.set_center(0, 0);

	dummy2.load_sprite_image("assets/images/meat dummy ss.png")
		
		.set_sprite_frame_size(460, 460)
		.set_scale(130, 130)
		.push_frame_row("dum2", 0, 0, 460, 0, 4)
		.push_frame("idle", 0, 0)
		.set_position(1000, 50)
		.set_animation("idle")
		.set_center(0, 0);


	//dummy1.set_animation("dum1");
	dred.load_sprite_image("assets/images/dred2.png")
		.set_scale(100, 130);
	dred2.load_sprite_image("assets/images/dred.png")
		.set_scale(130, 130);

	enemies.push_back(new Dairy(500, 50, 2, 10, dummy1)); //0
	enemies.push_back(new Meat(1000, 50, 5, 30, dummy2)); //1

	refill.load_sprite_image("assets/images/refill.png")
		.set_scale(100, 100)
		.set_position(1500, 50);

	rinstruct.load_sprite_image("assets/images/refills.png")
		.set_scale(200, 200)
		.set_position(1500, 200);

	exit.load_sprite_image("assets/images/exit.png")
		.set_scale(100, 150)
		.set_position(2400, 140);

	infinity.load_sprite_image("assets/images/infinity.png")
		.set_scale(50, 20);
	infinity2.load_sprite_image("assets/images/infinity.png")
		.set_scale(50, 20);

	//2700 //432
	//432 //69.12
}

void Tut::scrollLeft(int sVal)
{
	float b = tbackground.get_position().x;
	float f = tfloor.get_position().x;
	float p = tplatform.get_position().x;
	float s = tshift.get_position().x;
	float a = tarrows.get_position().x;
	float s2 = tspace.get_position().x;
	float r = refill.get_position().x;
	float r2 = rinstruct.get_position().x;
	float e = exit.get_position().x;

	tbackground.set_position(b -= sVal, 0);
	//tfloor.set_position(f-=sVal, 0);
	tplatform.set_position(p-=sVal, 50);

	tshift.set_position(s -= sVal , 200);
	tarrows.set_position(a -= sVal , 200);
	tspace.set_position(s2 -= sVal ,200);
	refill.set_position(r -= sVal, 50);
	rinstruct.set_position(r2 -= sVal, 200);
	exit.set_position(e -= sVal, 150);

	enemies[0]->shiftLeft(sVal);
	enemies[1]->shiftLeft(sVal);
}

void Tut::scrollRight(int sVal)
{
	float b = tbackground.get_position().x;
	float f = tfloor.get_position().x;
	float p = tplatform.get_position().x;
	float s = tshift.get_position().x;
	float a = tarrows.get_position().x;
	float s2 = tspace.get_position().x;
	float r = refill.get_position().x;
	float r2 = rinstruct.get_position().x;
	float e = exit.get_position().x;

	tbackground.set_position(b += sVal, 0);
	//tfloor.set_position(f += sVal, 0);
	tplatform.set_position(p += sVal, 50);

	tshift.set_position(s += sVal, 200);
	tarrows.set_position(a += sVal, 200);
	tspace.set_position(s2 += sVal, 200);
	refill.set_position(r += sVal, 50);
	rinstruct.set_position(r2 += sVal, 200);
	exit.set_position(e += sVal, 150);

	enemies[0]->shiftRight(sVal);
	enemies[1]->shiftRight(sVal);
}

void Tut::Draw()
{
	tbackground.draw();
	tfloor.draw();
	tplatform.draw();
	theUI.draw();

	tshift.draw();
	tarrows.draw();
	tspace.draw();

	enemies[0]->draw();
	enemies[1]->draw();


	infinity.set_position(enemies[0]->getX()+25, (185));
	infinity.draw();

	infinity2.set_position(enemies[1]->getX()+35, (190));
	infinity2.draw();

	refill.draw();
	rinstruct.draw();

	exit.draw();

}

void Tut::RunLevel(float phealth, bool W1, bool W2, int W1H, int W2H, Player *thePlayer)
{
	Draw();
	UI(phealth, W1, W2, W1H, W2H);
	thePlayer->draw();

	bool temp = thePlayer->getA();
	bool temp2 = thePlayer->getW1();
	enemies[0]->dummyCollisions(thePlayer->getX(), thePlayer->getY(), temp, temp2, dred);
	thePlayer->setA(temp);
	thePlayer->setW1(temp2);

	bool temp3 = thePlayer->getW2();
	enemies[1]->dummyCollisions(thePlayer->getX(), thePlayer->getY(), temp, temp3, dred2);
	thePlayer->setA(temp);
	thePlayer->setW2(temp3);

	//to get refill
	if (thePlayer->getX() > refill.get_position().x - 60 && thePlayer->getX() <( refill.get_position().x + 100))
	{
		Text::set_color(0.0f, 0.0f, 1.0f);
		Text::draw_string("Press E!", "TEMP", thePlayer->getX(), thePlayer->getY() + 120);
		getRefill = true;
	}
	else
	{
		getRefill = false;
	}

	//to leave
	if (thePlayer->getX() > exit.get_position().x - 60 && thePlayer->getX() <(exit.get_position().x + 100))
	{
		if (thePlayer->getY() >= 129)
		{
			Text::set_color(0.0f, 0.0f, 1.0f);
			Text::draw_string("Press E!", "TEMP", thePlayer->getX(), thePlayer->getY() + 120);
			leave = true;
		}
	}
	else
	{
		leave = false;
	}


}

void Tut::setBackground(float x, float y)
{
	tbackground.set_position(x, y);
}

void Tut::UI(float phealth, bool W1, bool W2, int W1H, int W2H)
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


	Text::draw_string("None", "TEMP", 520.0f, 500.0f);
}

void Tut::giveRefill(Player *thePlayer)
{
	thePlayer->setW1H(10);
	thePlayer->setW2H(10);
}

float Tut::getBScale()
{
	return tbackground.get_scale().x;
}

float Tut::getBX()
{
	return tbackground.get_position().x;
}

float Tut::getBY()
{
	return tbackground.get_position().y;
}

float Tut::getPX()
{
	return tplatform.get_position().x;
}

float Tut::getPY()
{
	return tplatform.get_position().y;
}

bool Tut::getR()
{
	return getRefill;
}

bool Tut::getL()
{
	return leave;
}

Sprite Tut::getPlat()
{
	return tplatform;
}

float Tut::getBackgroundX()
{
	return tbackground.get_position().x;
}

float Tut::getBackgroundScale()
{
	return 2900;
}