#include "spritelib\spritelib.h"
#include <iostream>
using namespace spritelib;

//rev.1 = game loop and window settings #GABBY

enum eGameState { NEW_GAME, PAUSE, QUIT, INSTRUCT, SETTINGS, M_STATION }; // M_STATION is just the menu in stationary position
enum mGameState { OPENING, MENU };

int main()
{
	// window definition

	Window& myGame = Window::get_game_window();
	myGame.init("Codename: CAJUN", 1280, 720)
		.set_window_style(true, true);
		// set mouse call back 

		// We need to make a music class for sounds and streams etc. 
		//sf::Music or Sound (the sound setting) and (loding the sound) SoundBuffer 
		// sound buffer is also good 
		// to add music -> menuMusic.openFromFile(file path to assets) 

	//text settings: insert below

	mGameState main = OPENING; // the opening cutscene for the game 
	while (myGame.update(30)) // main game loop 
	{
		switch (main)
		{
			case OPENING: // the opening cutscene for the game 
				{

					mGameState main = MENU; // once the opening is complete, main has been set to menu, there for changing the switch case
				}
				break;

			case MENU: //main menu 
				{
					eGameState gamestate = M_STATION;\

						// needing to draw the menu (draw menu fuction and then another that is check menu function)
						// need a function to draw the actual menu and get the coordinate from artist
						// inside of the mouse call back function 
						//check the game state
						// if the button is at x, y and width adn height 

				}
				break;
		}
	}

	return 0;
}