#include "spritelib/spritelib.h"
#include <vector>
#include <iostream>
#include <Windows.h>
#include "FirstLvl.h"
#include "BossLvl.h"
#include "Tut.h"

using namespace spritelib;

Sprite background, background2, player, enemy, enemy2, platform, theFloor, theUI, dead, menu, fpit, bossTest, knives;

float playerHealth = 100.0f;
float groundLvl = 50;
int gamestates = 0;

std::vector<Player*> thePlayer;
std::vector<FirstLvl*> theFirst;
std::vector<BossLvl*> theBoss;
std::vector<Tut*> tutorial;

//physics
float magnitude = 10;
float acc_y = 9.8;
int jumpCounter = 0;
bool stopJump = false;
bool ignore = false;
float m = 3;
int timer = 5;

enum states
{
	face_left,
	face_right
};

enum jstates
{
	jumped,
	Platform,
	ground,
	fall,
	
};

enum pstates
{
	none,
	platform1, //the platforms
	platform2,
	platform3,
	platform4,
	platform5,
	platform6,
	platform7,
	column1, //the columns
	column2,
	column3,
	column4,
	column5,
	column6,
	column7,
	rplat1, //the refill platforms
	rplat2
};

states curr_states = face_right;
jstates jump_state = ground;
pstates plat_state = none;

void LoadSprites()
{
	//loading the sprites
	background.load_sprite_image("assets/images/bg_temp_1_.png")
		.set_scale(10434, 432);

	fpit.load_sprite_image("assets/images/pitfall.png")
		.set_scale(260, 50)
		//.set_position(3400, 0);
		.set_position(3800, 0);

	/*player.load_sprite_image("assets/images/main char SS.png")
		.set_scale(100, 120)
		.set_sprite_frame_size(540, 14)
		.push_frame_row("walk", 0, 0, 141.2, 0, 5)
		.push_frame("idle", 0, 0)
		.push_frame("attack", 2700, 0)
		.set_center(0, 0)
		.set_position(300, groundLvl)
		.set_animation("idle");*/

	player.load_sprite_image("assets/images/main char SS.png")
		.set_sprite_frame_size(540, 540)
		.set_scale(120, 120)
		.push_frame_row("walk", 0, 0, 540, 0, 5)
		.push_frame("idle", 0, 0)
		.push_frame("attack", 2700, 0)
		.set_center(0, 0)
		.set_position(300, groundLvl)
		.set_animation("idle");

	enemy.load_sprite_image("assets/images/cheese walk ss.png")
		.set_sprite_frame_size(460, 460)
		.push_frame_row("walk", 0, 0, 460, 0, 8)
		.push_frame("idle", 0, 0)
		.set_scale(100, 100)
		.set_position(600, 130)
		.set_center(0, 0);

	enemy2.load_sprite_image("assets/images/meat walk ss.png")
		.set_scale(130, 130)
		.set_sprite_frame_size(160, 160)
		.push_frame_row("walk", 0, 0, 160, 0, 4)
		.push_frame("idle", 160, 0)
		//.set_position(1800, 50)
		.set_position(2000, 50)
		.set_animation("idle")
		.set_center(0, 0);

	platform.load_sprite_image("assets/images/Table.png")
		.set_scale(400, 100)
		.set_position(400, 50);

	theFloor.load_sprite_image("assets/images/floor.png")
		.set_scale(640, 50)
		.set_position(0, 0);

	theUI.load_sprite_image("assets/images/UI.png")
		.set_scale(660, 210)
		.set_center(0, 0)
		.set_position(-10, 390);

	dead.load_sprite_image("assets/images/Dead.png")
		.set_scale(140, 160);

	menu.load_sprite_image("assets/images/main_menu_1.png")
		.set_sprite_frame_size(640, 562);

	bossTest.load_sprite_image("assets/images/Gordon_Ramsay.png")
		.set_scale(200, 300)
		.set_position(500, 50);

	knives.load_sprite_image("assets/images/knives.png")
		.set_scale(100, 100)
		//.set_position(2600, 300);
		.set_position(3000, 350);
}

void platformCollision(Sprite &platform, float plw, float plh, pstates &p, pstates temp)
{
	if ((thePlayer[0]->getX() > platform.get_position().x-60) && thePlayer[0]->getX() < (platform.get_position().x + plw) )
	{
		if (thePlayer[0]->getY() >= platform.get_position().y + (plh-5) && thePlayer[0]->getY() <= platform.get_position().y + (plh))
		{
			jump_state = Platform; //if the player is within range of the top of the platform then it sets the jump state to platform
			thePlayer[0]->setY(platform.get_position().y + plh); //it also sets the new player y coordinate
			stopJump = false; //makes it so that the player can jump again
			p = temp;//gets the platform state
		}
	}
}

void KeyboardFunc(Window::Key a_key, Window::EventType a_eventType)
{
	float x = theFirst[0]->getBX();
	float y = theFirst[0]->getBY();

	float px = thePlayer[0]->getX();
	float py = thePlayer[0]->getY();

	float tx = tutorial[0]->getBX();
	float ty = tutorial[0]->getBY();

	switch (a_eventType)
	{
		case Window::EventType::KeyPressed:
		{
			if (gamestates == 1)
			{
				if (a_key == Window::Key::Space)
				{	
					if (Window::EventType::KeyReleased && thePlayer[0]->getH() > 0 && stopJump == false)
					{
						if ((tutorial[0]->getBackgroundX() <= 0) && (tutorial[0]->getBackgroundX() + 2900 > Window::get_game_window().get_width(true) ))
						{
							jump_state = jumped; //this sets it so that the player can jump
							jumpCounter = 0; //this is for the jump itself
							stopJump = true; //This makes it so that they cant jump twice in a row
						}
						if (tutorial[0]->getBackgroundX() > 0 && curr_states == face_right)
						{
							float temp = 0 - tutorial[0]->getBackgroundX();
							tutorial[0]->scrollRight(temp);

							jump_state = jumped; //this sets it so that the player can jump
							jumpCounter = 0; //this is for the jump itself
							stopJump = true; //This makes it so that they cant jump twice in a row

						}
						if (tutorial[0]->getBackgroundX()+2900 < Window::get_game_window().get_width(true) && curr_states == face_left)
						{
							//float temp = tutorial[0]->getBackgroundX()-2200;
							//tutorial[0]->scrollLeft(temp);

							jump_state = jumped; //this sets it so that the player can jump
							jumpCounter = 0; //this is for the jump itself
							stopJump = true; //This makes it so that they cant jump twice in a row
						}

					}
				}
				else if (a_key == Window::Key::D && thePlayer[0]->getH() > 0) //move right
				{
					thePlayer[0]->setFlipped(false);
					thePlayer[0]->setY(py); //if the player is less than the right boundary they can move forward
					thePlayer[0]->setAnimation("walk");
					if (tx + tutorial[0]->getBScale() > Window::get_game_window().get_width(true))
					{
						tutorial[0]->scrollLeft(10); //Moves the level
					}

					curr_states = face_right;
				}
				else if (a_key == Window::Key::A && thePlayer[0]->getH() > 0)//moving left
				{
					thePlayer[0]->setY(py);// if the player is before the left boundary they can move back
					thePlayer[0]->setFlipped(true);
					thePlayer[0]->setAnimation("walk");
					if (2 * tx < 0)
					{
						tutorial[0]->scrollRight(10);
					}

					curr_states = face_left;
				}
				else if (a_key == Window::Key::LShift && thePlayer[0]->getH() > 0  || a_key == Window::Key::RShift && thePlayer[0]->getH() > 0)
				{
					//This sets it so that they can attack
					if (Window::EventType::KeyReleased)
					{
						if (thePlayer[0]->getW1() == true && thePlayer[0]->getW1H() > 0)
						{
							thePlayer[0]->subW1();
							thePlayer[0]->setA(true);
							thePlayer[0]->setAnimation("attack");
						}
						else  if (thePlayer[0]->getW2() == true && thePlayer[0]->getW2H() > 0)
						{
							thePlayer[0]->subW2();
							thePlayer[0]->setA(true);
							thePlayer[0]->setAnimation("attack");

						}
						if (thePlayer[0]->getW1H() <= 0)
						{
							Text::set_color(0.0f, 0.0f, 1.0f);
							Text::draw_string("X", "TEMP", thePlayer[0]->getX(), thePlayer[0]->getY() + 120);
						}
						if (thePlayer[0]->getW2H() <= 0)
						{
							Text::set_color(0.0f, 0.0f, 1.0f);
							Text::draw_string("X", "TEMP", thePlayer[0]->getX(), thePlayer[0]->getY() + 120);
						}

					}
					break;
				}
				else if (a_key == Window::Key::Right && thePlayer[0]->getH() > 0)
				{
					//switches between the weapons
					thePlayer[0]->setW2(true);
					thePlayer[0]->setW1(false);
				}
				else if (a_key == Window::Key::Left && thePlayer[0]->getH() > 0)
				{
					//sets the weapons
					thePlayer[0]->setW1(true);
					thePlayer[0]->setW2(false);
				}
				else if (a_key == Window::Key::E && tutorial[0]->getR() == true)
				{
					tutorial[0]->giveRefill(thePlayer[0]);
				}
				else if (a_key == Window::Key::E && tutorial[0]->getL() == true)
				{
					gamestates = 2;
				}
			}
			if (gamestates == 2)
			{
				if (theFirst[0]->getP() == false)
				{
					if (a_key == Window::Key::Space)
					{	
						if (Window::EventType::KeyReleased && thePlayer[0]->getH() > 0 && stopJump == false)
						{
							if ((x <= 0) && (x + 10434 > Window::get_game_window().get_width(true)))
							{
								jump_state = jumped; //this sets it so that the player can jump
								jumpCounter = 0; //this is for the jump itself
								stopJump = true; //This makes it so that they cant jump twice in a row
							}
							else if (x > 0 && curr_states == face_right)
							{
								jump_state = jumped; //this sets it so that the player can jump
								jumpCounter = 0; //this is for the jump itself
								stopJump = true; //This makes it so that they cant jump twice in a row
							}
						}
					}
					else if (a_key == Window::Key::D && thePlayer[0]->getH() > 0) //move right
					{	
						thePlayer[0]->setFlipped(false);
						thePlayer[0]->setY(py); //if the player is less than the right boundary they can move forward
						thePlayer[0]->setAnimation("walk");

						if (x + background.get_scale().x > Window::get_game_window().get_width(true))
						{
							theFirst[0]->scrollLeft(10); //Moves the level
						}

						curr_states = face_right;
					}
					else if (a_key == Window::Key::A && thePlayer[0]->getH() > 0)//moving left
					{
						thePlayer[0]->setY(py);// if the player is before the left boundary they can move back
						thePlayer[0]->setFlipped(true);
						thePlayer[0]->setAnimation("walk");

						if (2 * x < 0)
						{
							theFirst[0]->scrollRight(10);
						}

						curr_states = face_left;
					}
					else if (a_key == Window::Key::LShift && thePlayer[0]->getH() > 0 || a_key == Window::Key::RShift && thePlayer[0]->getH() > 0)
					{
						//This sets it so that they can attack
						if (Window::EventType::KeyReleased)
						{
							thePlayer[0]->setA(true);
							
							if (thePlayer[0]->getW1() == true)
							{
								thePlayer[0]->subW1();
								thePlayer[0]->setAnimation("attack");
							}
							if (thePlayer[0]->getW2() == true)
							{
								thePlayer[0]->subW2();
								thePlayer[0]->setAnimation("attack");
							}
						}
						break;
					}
					else if (a_key == Window::Key::Right && thePlayer[0]->getH() > 0)
					{
						//switches between the weapons
						thePlayer[0]->setW2(true);
						thePlayer[0]->setW1(false);
					}
					else if (a_key == Window::Key::Left && thePlayer[0]->getH() > 0)
					{
						//sets the weapons
						thePlayer[0]->setW1(true);
						thePlayer[0]->setW2(false);
					}
					else if (a_key == Window::Key::R && thePlayer[0]->getH() <= 0)
					{
						//this is to restart
						theFirst[0]->Restart();
						thePlayer[0]->setH(100.0f);
						thePlayer[0]->setW1(false);
						thePlayer[0]->setW1(false);

						groundLvl = 50;
						thePlayer[0]->setX(300);
						thePlayer[0]->setY(groundLvl);
						thePlayer[0]->setH(100.0f);
					}
					else if (a_key == Window::Key::E && plat_state == rplat1)
					{
						thePlayer[0]->setW1H(10);
						thePlayer[0]->setW2H(10);
					}
					else if (a_key == Window::Key::E && theFirst[0]->getLeave() == true && theFirst[0]->getGoal() == true)
					{
						gamestates = 3;
					}
			
				}

				//The P pauses the game, the B goes straight to the boss
				if (a_key == Window::Key::P)
				{
					//this sets the boolean for pause 
					if (Window::EventType::KeyReleased)
					{
						if (theFirst[0]->getP() == true) theFirst[0]->setP(false);
						else if (theFirst[0]->getP() == false) theFirst[0]->setP(true);
					}

				}
				
			}
			if (gamestates == 3)
			{
				if (a_key == Window::Key::Space)
				{	
					if (Window::EventType::KeyReleased && thePlayer[0]->getH() > 0 && stopJump == false)
					{
						jump_state = jumped; //this sets it so that the player can jump
						jumpCounter = 0; //this is for the jump itself
						stopJump = true; //This makes it so that they cant jump twice in a row
					}
				}
				else if (a_key == Window::Key::D && thePlayer[0]->getH() > 0) //move right
				{
					thePlayer[0]->setFlipped(false);
					thePlayer[0]->setY(py); //if the player is less than the right boundary they can move forward
					thePlayer[0]->setAnimation("walk");
				
					float px = thePlayer[0]->getX();
					
					thePlayer[0]->setX(px + 10);

					curr_states = face_right;
				}
				else if (a_key == Window::Key::A && thePlayer[0]->getH() > 0)//moving left
				{
					thePlayer[0]->setY(py);// if the player is before the left boundary they can move back
					thePlayer[0]->setFlipped(true);
					thePlayer[0]->setAnimation("walk");

					float px = thePlayer[0]->getX();

					thePlayer[0]->setX(px - 10);
					
					curr_states = face_left;
				}
				else if (a_key == Window::Key::LShift && thePlayer[0]->getH() > 0 || a_key == Window::Key::RShift && thePlayer[0]->getH() > 0)
				{
					//This sets it so that they can attack
					if (Window::EventType::KeyReleased)
					{
						thePlayer[0]->setA(true);
						if (thePlayer[0]->getW1() == true)
						{
							thePlayer[0]->subW1();
						}
						if (thePlayer[0]->getW2() == true)
						{
							thePlayer[0]->subW2();
						}
					}
					break;
				}
				else if (a_key == Window::Key::Right && thePlayer[0]->getH() > 0)
				{
					//switches between the weapons
					thePlayer[0]->setW2(true);
					thePlayer[0]->setW1(false);
				}
				else if (a_key == Window::Key::Left && thePlayer[0]->getH() > 0)
				{
					//sets the weapons
					thePlayer[0]->setW1(true);
					thePlayer[0]->setW2(false);
				}
			}
			if (a_key == Window::Key::B)
			{
				//the boss fight
				gamestates = 3;
				thePlayer[0]->setY(50);
				thePlayer[0]->setX(300);
				thePlayer[0]->setH(100);
				thePlayer[0]->setW1H(10);
				thePlayer[0]->setW2H(10);
				thePlayer[0]->setW1(true);
				thePlayer[0]->setW2(false);

			}
			
			if (a_key == Window::Key::T)
			{
				gamestates = 1;
				thePlayer[0]->setY(50);
				thePlayer[0]->setX(300);
				thePlayer[0]->setH(100);
				thePlayer[0]->setW1H(10);
				thePlayer[0]->setW2H(10);
				thePlayer[0]->setW1(true);
				thePlayer[0]->setW2(false);
			}
			if (a_key == Window::Key::F)
			{
				gamestates = 2;
				thePlayer[0]->setY(50);
				thePlayer[0]->setX(300);
				thePlayer[0]->setH(100);
				thePlayer[0]->setW1H(10);
				thePlayer[0]->setW2H(10);
				thePlayer[0]->setW1(true);
				thePlayer[0]->setW2(false);
			}

		}
		break;
		case Window::EventType::KeyReleased:
		{
			if (gamestates == 1 || gamestates == 2 || gamestates == 3)
			{
				if (curr_states == face_right)
					thePlayer[0]->setAnimation("idle");

				if (curr_states == face_left)
					thePlayer[0]->setAnimation("idle");
			}
		}
	}
}

void Jump()
{
	float x = background.get_position().x;
	float y = background.get_position().y;

	float posx = thePlayer[0]->getX();
	float posy = thePlayer[0]->getY();
	
	if (jump_state == jumped)
	{
		jumpCounter++;
		
		if (gamestates == 1)
		{
			if (tutorial[0]->getBackgroundX() >= 0 || tutorial[0]->getBackgroundX() + 2900 < Window::get_game_window().get_width(true))
			{
				jump_state = fall;
				stopJump = false;
			}
		}
		if (gamestates == 2)
		{
			if ((theFirst[0]->getBX() >= 0 || theFirst[0]->getBX() + 10434 < Window::get_game_window().get_width(true)))
			{
				jump_state = fall;
				stopJump = false;
			}
		}

		if (jumpCounter >= 10)
		{
			if (gamestates == 2)
			{
				//the platforms
				platformCollision(theFirst[0]->getPlat(), 400, 100, plat_state, platform1);
				platformCollision(theFirst[0]->getPlat2(), 400, 100, plat_state, platform2);
				platformCollision(theFirst[0]->getPlat3(), 400, 100, plat_state, platform3);
				platformCollision(theFirst[0]->getPlat4(), 400, 100, plat_state, platform4);
				platformCollision(theFirst[0]->getPlat5(), 250, 100, plat_state, platform5);
				platformCollision(theFirst[0]->getPlat6(), 250, 100, plat_state, platform6);
				platformCollision(theFirst[0]->getPlat7(), 400, 100, plat_state, platform7);
				
				//the columns
				platformCollision(theFirst[0]->getC1(), 100, 100, plat_state, column1);
				platformCollision(theFirst[0]->getC2(), 100, 200, plat_state, column2);
				platformCollision(theFirst[0]->getC3(), 200, 100, plat_state, column3);
				platformCollision(theFirst[0]->getC4(), 100, 100, plat_state, column4);
				platformCollision(theFirst[0]->getC5(), 200, 100, plat_state, column5);
				platformCollision(theFirst[0]->getC6(), 100, 200, plat_state, column6);
				platformCollision(theFirst[0]->getC7(), 200, 100, plat_state, column7);

				//the refill platforms
				platformCollision(theFirst[0]->getRP1(), 150, 200, plat_state, rplat1);
				platformCollision(theFirst[0]->getRP2(), 100, 100, plat_state, rplat2);
			}
			if (gamestates == 1)
			{
				platformCollision(tutorial[0]->getPlat(), 400, 100, plat_state, platform1);
			}
		}	
		if (curr_states == face_right)
		{	
			if (jumpCounter <= 6)
			{
				if (gamestates == 1)
					tutorial[0]->scrollLeft((magnitude + 6));
				else if (gamestates == 2)
					theFirst[0]->scrollLeft((magnitude+6));
				
				posy = posy + (magnitude + acc_y);
			}
			else if (jumpCounter > 7 && jumpCounter <= 10)
			{
				posy = posy;

				if (gamestates == 1)
					tutorial[0]->scrollLeft((magnitude + 6));
				else if (gamestates == 2)
					theFirst[0]->scrollLeft((magnitude + 6));
				
			}
			else if (jumpCounter > 10 && jumpCounter < 17)
			{
				posy = posy - (magnitude + acc_y);
				if (gamestates == 1)
					tutorial[0]->scrollLeft((magnitude + 6));
				else if (gamestates == 2)
					theFirst[0]->scrollLeft((magnitude + 6));
				
				
			}
			else if (jumpCounter >= 17)
			{

				//if (plat_state != platform5)
				if (jumpCounter >= 18)
				jump_state = fall;
				stopJump = false;
			}
		}
		if (curr_states == face_left)
		{
			if (jumpCounter <= 6)
			{
				if (gamestates == 1)
					tutorial[0]->scrollRight(magnitude + 6);
				else if (gamestates == 2)
					theFirst[0]->scrollRight(magnitude+6);
				posy = posy + (magnitude + acc_y);
			}
			else if (jumpCounter > 7 && jumpCounter <= 10)
			{
				if (gamestates == 1)
					tutorial[0]->scrollRight(magnitude + 6);
				else if (gamestates == 2)
					theFirst[0]->scrollRight(magnitude + 6);
				posy = posy;
				
			}
			else if (jumpCounter > 10 && jumpCounter < 17)
			{
				if (gamestates == 1)
					tutorial[0]->scrollRight(magnitude + 6);
				else if (gamestates == 2)
					theFirst[0]->scrollRight(magnitude + 6);
				posy = posy - (magnitude + acc_y);	

			}
			else if (jumpCounter >= 17)
			{
				
				//if (plat_state != platform5)
				if (jumpCounter >= 18)
				jump_state = fall;
				stopJump = false;
			}
		}
		
		thePlayer[0]->setX(posx);
		thePlayer[0]->setY(posy);
	}
}

void Fall(int leftBound, int rightBound)
{
	if (thePlayer[0]->getX() < leftBound || thePlayer[0]->getX() >rightBound)
	{
		if (thePlayer[0]->getY()> 50)
		{
			jump_state = fall;
		}
	}
}

void Update()
{
	if (thePlayer[0]->getH() > 0)
	thePlayer[0]->nextFrame();
}

int main()
{
	Window& theGame = Window::get_game_window();//https://en.wikipedia.org/wiki/Singleton_pattern
	theGame.init("OPERATION CAJUN", 800, 562)
		.set_screen_size(640, 562)
		.set_keyboard_callback(KeyboardFunc)
		.set_clear_color(0, 255, 0);

	LoadSprites();

	thePlayer.push_back(new Player(player, 300, groundLvl));
	theFirst.push_back(new FirstLvl(background, platform, enemy, enemy2, platform, theFloor, theUI, dead, fpit, knives));
	theBoss.push_back(new BossLvl(theFloor, background, bossTest));
	tutorial.push_back(new Tut(theFloor, background, platform));

	//The main game loop
	while (theGame.update(30))
	{
		if (gamestates == 0)
		{
			menu.draw();

			if (GetAsyncKeyState('A')) gamestates = 1;
		}	
		if (gamestates == 1)
		{
			std::cout << tutorial[0]->getBackgroundX() << std::endl;
			tutorial[0]->RunLevel(thePlayer[0]->getH(), thePlayer[0]->getW1(), thePlayer[0]->getW2(), thePlayer[0]->getW1H(), thePlayer[0]->getW2H(), thePlayer[0]);
			Update();
			Jump();

			//fixes the attack issue
			if (thePlayer[0]->getA() == true)
			{
				timer--;
			}
			if (timer == 0)
			{
				thePlayer[0]->setA(false);
				timer = 5;
			}

			if (jump_state == Platform) //this checks if the player is on a platform. And then it sets the parameters for the player to fall depending
			{
				if (plat_state == platform1)
				{
					Fall((tutorial[0]->getPX() - 60), ((tutorial[0]->getPX() + 320)));
				}
			}

			if (jump_state == fall) //This is if the player is falling. It decreases the player's y position
			{
				if (thePlayer[0]->getY() > 50)
				{
					float posy = thePlayer[0]->getY();
					thePlayer[0]->setY(posy -= (10));

					//the platforms
					platformCollision(tutorial[0]->getPlat(), 400, 100, plat_state, platform1);
				}
				if (thePlayer[0]->getY() <= 50)
				{
					jump_state = ground;
					plat_state = none;
					thePlayer[0]->setY(50);
				}
			}
		}
		if (gamestates == 2)
		{
			float temp = thePlayer[0]->getH();
			theFirst[0]->RunLevel(temp, thePlayer[0]->getW1(), thePlayer[0]->getW2(), thePlayer[0]->getW1H(), thePlayer[0]->getW2H(), thePlayer[0]);
			thePlayer[0]->setH(temp);
			Update();

			//fixes the attack issue
			if (thePlayer[0]->getA() == true)
			{
				timer--;
			}
			if (timer == 0)
			{
				thePlayer[0]->setA(false);
				timer = 5;
			}

			if (theFirst[0]->getP() == false)
			{
				theFirst[0]->Pitfall(theFirst[0]->getFall(), thePlayer[0], 160);
				theFirst[0]->Pitfall(theFirst[0]->getFall2(), thePlayer[0], 1100);
				theFirst[0]->Pitfall(theFirst[0]->getFall3(), thePlayer[0], 810);

				if (jump_state == Platform) //this checks if the player is on a platform. And then it sets the parameters for the player to fall depending
				{
					if (plat_state == platform1)
					{
						Fall((theFirst[0]->getPX() - 60), ((theFirst[0]->getPX() + 320)));
					}
					if (plat_state == platform2)
					{
						Fall((theFirst[0]->getPX2() - 60), ((theFirst[0]->getPX2() + 320)));
					}
					if (plat_state == platform3)
					{
						Fall((theFirst[0]->getPX3() - 60), ((theFirst[0]->getPX3() + 320)));
					}
					if (plat_state == platform4)
					{
						Fall((theFirst[0]->getPX4() - 60), ((theFirst[0]->getPX4() + 320)));
					}
					if (plat_state == platform5)
					{
						Fall((theFirst[0]->getPX5() - 60), ((theFirst[0]->getPX5()) + 200));
					}
					if (plat_state == platform6)
					{
						Fall((theFirst[0]->getPX6() - 60), ((theFirst[0]->getPX6()) + 200));
					}
					if (plat_state == platform7)
					{
						Fall((theFirst[0]->getPX7() - 60), ((theFirst[0]->getPX7()) + 320));
					}

					//the columns
					if (plat_state == column1)
					{
						Fall((theFirst[0]->getC1X() - 85), ((theFirst[0]->getC1X()) + 50));
					}
					if (plat_state == column2)
					{
						Fall((theFirst[0]->getC2X() - 85), ((theFirst[0]->getC2X()) + 50));
					}
					if (plat_state == column3)
					{
						Fall((theFirst[0]->getC3X() - 85), ((theFirst[0]->getC3X()) + 150));
					}
					if (plat_state == column4)
					{
						Fall((theFirst[0]->getC4X() - 85), ((theFirst[0]->getC4X()) + 50));
					}
					if (plat_state == column5)
					{
						Fall((theFirst[0]->getC5X() - 85), ((theFirst[0]->getC5X()) + 150));
					}
					if (plat_state == column6)
					{
						Fall((theFirst[0]->getC6X() - 85), ((theFirst[0]->getC6X()) + 50));
					}
					if (plat_state == column7)
					{
						Fall((theFirst[0]->getC7X() - 85), ((theFirst[0]->getC7X()) + 180));
					}

					//the refill platforms
					if (plat_state == rplat1)
					{
						Fall((theFirst[0]->getRPX1() - 85), ((theFirst[0]->getRPX1() + 50)));
					}
					if (plat_state == rplat2)
					{
						Fall((theFirst[0]->getRPX2() - 85), ((theFirst[0]->getRPX2() + 50)));
					}
					
				}

				if (jump_state == fall) //This is if the player is falling. It decreases the player's y position
				{
					if (thePlayer[0]->getY() > 50)
					{
						float posy = thePlayer[0]->getY();
						thePlayer[0]->setY(posy -= (10));

						//the platforms
						platformCollision(theFirst[0]->getPlat(), 400, 100, plat_state, platform1);
						platformCollision(theFirst[0]->getPlat2(), 400, 100, plat_state, platform2);
						platformCollision(theFirst[0]->getPlat3(), 400, 100, plat_state, platform3);
						platformCollision(theFirst[0]->getPlat4(), 400, 100, plat_state, platform4);
						platformCollision(theFirst[0]->getPlat5(), 250, 100, plat_state, platform5);
						platformCollision(theFirst[0]->getPlat6(), 250, 100, plat_state, platform6);
						platformCollision(theFirst[0]->getPlat7(), 250, 100, plat_state, platform7);
						
						//the columns
						platformCollision(theFirst[0]->getC1(), 100, 100, plat_state, column1);
						platformCollision(theFirst[0]->getC2(), 100, 200, plat_state, column2);
						platformCollision(theFirst[0]->getC3(), 200, 100, plat_state, column3);
						platformCollision(theFirst[0]->getC4(), 100, 100, plat_state, column4);
						platformCollision(theFirst[0]->getC5(), 200, 100, plat_state, column5);
						platformCollision(theFirst[0]->getC6(), 100, 200, plat_state, column6);
						platformCollision(theFirst[0]->getC7(), 200, 100, plat_state, column7);

						//refill platforms
						//the refill platforms
						platformCollision(theFirst[0]->getRP1(), 150, 200, plat_state, rplat1);
						platformCollision(theFirst[0]->getRP2(), 100, 100, plat_state, rplat2);
					}
					if (thePlayer[0]->getY() <= 50)
					{
						jump_state = ground;
						plat_state = none;
						thePlayer[0]->setY(50);
					}
				}
				
				Jump();
			}	
		
		}		
		if (gamestates == 3)
		{
			//fixes the attack issue
			if (thePlayer[0]->getA() == true)
			{
				timer--;
			}
			if (timer == 0)
			{
				thePlayer[0]->setA(false);
				timer = 5;
			}

			theBoss[0]->RunLevel(thePlayer[0]->getH(), thePlayer[0]->getW1(), thePlayer[0]->getW2(), thePlayer[0]->getW1H(), thePlayer[0]->getW2H(), thePlayer[0]);
			Update();
			Jump();
		}
	}

	delete thePlayer[0];
	delete theFirst[0];
	
	return 0;
}

