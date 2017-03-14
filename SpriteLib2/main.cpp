#include "spritelib\spritelib.h"
#include "Menu.h"
#include <iostream>
#include "Buttons.h"

using namespace spritelib;
using namespace std;

//rev.1 = game loop and window settings #GABBY

enum GameState { MENU, NEW_GAME, PAUSE, QUIT, INSTRUCT, SETTINGS, M_STATION }; // M_STATION is just the menu in stationary position
Menu menu; // declaration of menu class

void MouseFunc(Window::Button a_button, int a_mouseX, int a_mouseY, Window::EventType a_eventType)
{ 
	Buttons game, credit, set;
	
	//new game button coordinates
	game.pos_x = 50;
	game.pos_y = 80;
	game.width = 800;
	game.height = 500;
	
	//pause button
	set.pos_x = 525;
	set.pos_y = 80;
	set.width = 800;
	set.height = 500;

	//credit button
	credit.pos_x = 650;
	credit.pos_y = 80;
	credit.width = 800;
	credit.height = 500;

	//quit button
	//quit.pos_x =
	//quit.pos_y =
	//quit.width =
	//quit.height =

	switch (a_eventType)
	{
		case Window::EventType::MouseButtonPressed:
		{
			//statement will check the coordinate of the bottom right corner of the sprite then by adding the height and width, the whole button is taken into consideration
			if (a_mouseX > game.pos_x && a_mouseX < game.pos_x + game.width && a_mouseY > game.pos_y && a_mouseY < game.pos_y + game.height)
			{
				cout << "Start Game";
			}

			else if (a_mouseX > credit.pos_x && a_mouseX < credit.pos_x + credit.width && a_mouseY > credit.pos_y && a_mouseY < credit.pos_y + credit.height)
			{
				cout << "Credits";
			}

			else if (a_mouseX > set.pos_x && a_mouseX < set.pos_x + set.width && a_mouseY > set.pos_y && a_mouseY < set.pos_y + set.height)
			{
				cout << "Settings";
			}
		}
		break;

		case Window::EventType::MouseButtonReleased:
		{
		}
	}
}

int main()
{
	Window& myGame = Window::get_game_window();
	myGame.init("Codename: CAJUN", 1280, 720)
		.set_screen_size(800, 432)
		.set_clear_color(176, 216, 230)
		.set_mouse_callback(MouseFunc)
		.show_mouse(true); // will show the mouse


		// We need to make a music class for sounds and streams etc. 
		//sf::Music or Sound (the sound setting) and (loding the sound) SoundBuffer 
		// sound buffer is also good 
		// to add music -> menuMusic.openFromFile(file path to assets) 

	//text settings: insert below


	GameState gamestate = MENU; // the opening cutscene for the game 
	while (myGame.update(30)) // main game loop 
	{

		menu.drawMenu();
		
						// needing to draw the menu (draw menu fuction and then another that is check menu function)
						// need a function to draw the actual menu and get the coordinate from artist
						// inside of the mouse call back function 
						//check the game state
						// if the button is at x, y and width adn height 
			
	}

	return 0;
}