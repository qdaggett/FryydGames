#include "spritelib/spritelib.h"
#include <fstream>
#include <streambuf>
#include <vector>
#include <iostream>

using namespace spritelib;
using namespace std;

Sprite background, background2, player, enemy, enemy2;

bool direction = true;
bool playerA = false;
int counter = 600;
int newCounter = 1300;
int health1 = 10, health2 = 30;
bool weapon1 = false, weapon2 = false;
float playerHealth = 100.0f;


void KeyboardFunc(Window::Key a_key, Window::EventType a_eventType)
{
	float x = background.get_position().x;
	float y = background.get_position().y;

	float px = player.get_position().x;
	float py = player.get_position().y;

	float enemyx = enemy.get_position().x;
	float enemyy = enemy.get_position().y;

	float enemy2x = enemy2.get_position().x;
	float enemy2y = enemy2.get_position().y;

	switch (a_eventType)
	{
		case Window::EventType::KeyPressed:
		{
			
			if (a_key == Window::Key::Space)//to check
			{
				cout << "JUMP" << endl; 
			}

			else if (a_key == Window::Key::D)
			{
				if (x + background.get_scale().x > Window::get_game_window().get_width(true))
				{
					background.set_position(x -= 7, y);//This makes everything scroll as per the player
					enemy.set_position(enemyx-=7, enemyy);
					enemy2.set_position(enemy2x-=7, enemy2y);
				}


				if (px + 90 < Window::get_game_window().get_width(true))
				player.set_position(px+=3, py);	 //if the player is less than the right boundary they can move forward
			}

			else if (a_key == Window::Key::A)
			{
				if (2 * x < 0)
				{
					background.set_position(x += 7, y); //making sure the background is greater than zero in order for it to scroll back
					enemy.set_position(enemyx += 7, enemyy);
					enemy2.set_position(enemy2x+=7, enemy2y);
				}

				if (px  >0)
				player.set_position(px -= 3, py); // if the player is before the left boundary they can move back
			}
			else if (a_key == Window::Key::E)
			{
				if( Window::EventType::KeyReleased)
				{
					playerA = true;
				}
				break;
			}
			else if (a_key == Window::Key::Right)
			{
				weapon2 = true;
				weapon1 = false;
			}
			else if (a_key == Window::Key::Left)
			{
				weapon1 = true;
				weapon2 = false;
			}
		}
	break;
	}
}

void Move(Sprite &enemy, int backLimit, int frontLimit, int &thecounter, int speed)
{
	float enemyx = enemy.get_position().x;//you can ignore this/take it out if you dont want to worry about spawning 
	float enemyy = enemy.get_position().y;

	if (direction == true)
	{
		enemy.set_position(enemyx -= speed, enemyy);
		thecounter -= speed;
	
		if (thecounter <= backLimit)
		{
			direction = false;
		}
	}
	else if (direction == false)
	{
		enemy.set_position(enemyx += speed, enemyy);
		thecounter += speed;
		
		if (thecounter >= frontLimit)
		{
			direction = true;
		}
	}
}

void Collisions(Sprite &enemy, Sprite &player, bool attack, int &health)
{
	float distanceBetween;

	float radiuses = 60.0f;
	float attackR = 90.0f;

	//the formula
	distanceBetween = sqrt(pow(enemy.get_position().y - player.get_position().y, 2) + pow(enemy.get_position().x - player.get_position().x, 2));

	if (playerA == true)
	{
		if (distanceBetween < attackR && attack == true)	
		{
			cout << "YOU ATTACKED" << endl;
			health -= 10;
			playerA = false;
		}
	}
	if (distanceBetween < radiuses)
	{
		//THIS IS IF THEY'RE ATTACKING AND IT HITS
		//Text::set_color(1.0f, 0.0f, 0.0f);
		//Text::draw_string("POW!", "TimesNewRoman", 200, 150);
		
		playerHealth -= 0.5f;
	}
}

void UI()
{
	if (playerHealth > 0)
	{
		if (playerHealth>70) Shapes::set_color(0.0f, 1.0f, 0.0f);
		else if (playerHealth >40) Shapes::set_color(1.0f, 1.0f, 0.0f);
		else Shapes::set_color(1.0f, 0.0f, 0.0f);
		
		Shapes::draw_rectangle(true, 10, 370, 2 * playerHealth, 30, 0.0f);
	}

	if (weapon1 == true)
	{
		Shapes::set_color(0.0f, 0.0f, 0.9f);
		Shapes::draw_rectangle(true, 525, 360, 45, 45, 0);
	}
	else if (weapon2 == true)
	{
		Shapes::set_color(0.0f, 0.0f, 0.9f);
		Shapes::draw_rectangle(true, 575, 360, 45, 45, 0);
	}

	Shapes::set_color(1.0f, 1.0f, 0.0f);
	Shapes::draw_rectangle(true, 530, 365, 35, 35, 0);


	Shapes::set_color(1.0f, 0.0f, 0.0f);
	Shapes::draw_rectangle(true, 580, 365, 35, 35, 0);

	Text::load_font("assets/KBZipaDeeDooDah.ttf", "TimesNewRoman");

	// Draw Hello World in Times New Roman
	Text::set_color(50.0f, 50.0f, 0.0f);
	Text::draw_string("Health", "TimesNewRoman", 10.0f, 410.0f);

	Text::set_color(50.0f, 50.0f, 0.0f);
	Text::draw_string("Weapons", "TimesNewRoman", 530.0f, 410.0f);
}
	
int main()
{
	Window& theGame = Window::get_game_window();//https://en.wikipedia.org/wiki/Singleton_pattern
	theGame.init("MY GAME", 800, 432)
		.set_screen_size(640, 432)
		.set_keyboard_callback(KeyboardFunc)
		.set_clear_color(0, 255, 0);

	//loading the sprites
	background.load_sprite_image("assets/images/BBackground.png")
		.set_scale(1717, 432);

	player.load_sprite_image("assets/images/Achef.png")
		.set_scale(100, 120)
		.set_center(0,0)
		.set_position(0, 50);
	
	enemy.load_sprite_image("assets/images/Acheese.png")
		.set_scale(130, 130)
		.set_position(600, 50)
		.set_center(0, 0);

	enemy2.load_sprite_image("assets/images/AMeat.png")
		.set_scale(130, 130)
		.set_position(1200, 50)
		.set_center(0, 0);

	//The main game loop
	while (theGame.update(30))
	{
		//background2.draw();
		background.draw();

		UI();

		player.draw();
		
		if (health1 > 0)
		{
			enemy.draw();
			Move(enemy, 400, 700, counter, 2);
			Collisions(enemy, player, weapon1, health1);
		}
		if (health2 > 0)
		{
			enemy2.draw();
			Move(enemy2, 1200, 1600, newCounter, 5);
			Collisions(enemy2, player, weapon2, health2);
		}
		
		
	}

	return 0;
}


